# UnrealVoxelSim.Navigation.Api

External navigation contracts for task executors, AI queries, planning implementations, and following implementations.
A navigation execution is a subordinate asynchronous attempt to reach a spatial goal; it is not a pawn task or order.
An upper-level task such as fetching an item may start, observe, replace, or cancel navigation without exposing its own
meaning to this domain.

## Boundaries and consumers

| Consumer or provider | Contracts | Purpose |
| --- | --- | --- |
| Task executors, AI, and input adapters | `ICommandSink`, `IExecutionReader` | Queue movement-to-goal executions and observe their lifecycle. |
| Composition root | `ICommandProcessor`, `IFollowingUpdater`, `IPlanner::Advance` | Place navigation phases explicitly in the simulation tick. |
| Following implementations | `IPlanner`, `Path`, `Waypoint` | Request paths, observe completion, and turn immutable paths into movement intents. |
| AI and task-planning services | `IReachability` | Test one source against many destinations without constructing a path for every destination. |
| Planning implementations | `PlanRequest`, `PlanState`, `Path`, reachability types | Implement bounded asynchronous planning behind stable domain contracts. |

Presentation adapters may depend on this API to submit navigation commands and read status. They do not receive a
planner implementation, movement storage, voxel layers, or a general service locator. Navigation has its own narrow
command sink and processor; it does not share a god-object command queue with other domains.

## Working model

Navigation is intentionally asynchronous and advances only at composition-defined simulation phases:

1. A caller assigns a unique `ExecutionId`, creates a `Start` with a canonical `Simulation::Api::CommandStamp`, and
   submits it through `ICommandSink`.
2. Submission validates and queues the command but does not mutate navigation or movement state immediately.
3. The composition root calls `ICommandProcessor::ProcessCommands` for the stamped target tick. A following service
   starts a profile-specific `PlanRequest` from the entity's authoritative movement position.
4. The composition root advances topology and then calls `IPlanner::Advance`. A request may remain `Pending` for a
   deterministic number of ticks while shared work budgets are consumed.
5. `IFollowingUpdater::UpdateFollowing` consumes a completed immutable path and submits transient intents through the
   movement API. Movement remains authoritative for continuous position, velocity, gravity, and collision.
6. Callers observe `Planning`, `Following`, `Replanning`, `Arrived`, `Unreachable`, or `Cancelled` through
   `IExecutionReader`. They do not poll planner internals.

The composition root owns this order; neither the fixed-step simulation engine nor the API embeds a system registry.

## Commands and executions

`Start` identifies the entity, caller-chosen execution generation, spatial `Goal`, and target simulation tick. A new
start for an entity supersedes its current execution. `Cancel` includes both entity and `ExecutionId`, so a delayed
cancel cannot terminate a newer generation accidentally. `Goal::ArrivalRadius` is expressed in deterministic movement
coordinates and must be positive.

`Command` is the closed `Start`/`Cancel` variant. `ICommandSink::Submit` accepts batches and reports validation failure
with a `CommandError` and command index. Stamps provide deterministic total ordering through target tick, command source,
and source-local sequence; duplicates are rejected. Callers must submit before the target tick is processed.

`IExecutionReader::ReadExecution` returns the current execution generation and state for an entity. Terminal states are
observable results, not task semantics: an upper-level task decides whether to retry, choose another destination, or
fail its own order.

## Planning and paths

`IPlanner::Begin` accepts a unique `RequestId`, a `Movement::Api::ProfileId`, and continuous start and goal positions.
The planner owns asynchronous request state and progresses it only in `Advance`. `Cancel` is idempotent from the
caller's perspective. `State` exposes `Pending`, `Complete`, `Unreachable`, or `Cancelled`; `ReadPath` returns a shared,
immutable path only after completion.

Each `Path` carries the environment revision against which it was built and an opaque planner validation token. Its
waypoints use deterministic continuous coordinates and label the movement needed to enter them with a
`MovementPrimitiveId`. V1 defines `Traverse`, `Rise`, and `Drop`; future followers and movement implementations may add
primitives without placing voxel concepts in task APIs. A follower asks `IsPathCurrent` before using a path; planners
may retain paths across unrelated environment revisions and invalidate only paths whose dependencies changed.

`IPlanner` is an implementation-facing service, not the primary task/AI command surface. Most gameplay code should use
`ICommandSink` and `IExecutionReader` so planners and followers remain independently replaceable.

## Reachability

`IReachability` is the cheaper AI-facing question: from this source, which of these destinations can this movement
profile reach? `BeginReachability` accepts one source and an ordered destination vector. `ReadReachability` returns an
immutable result whose states correspond by index to that vector and may independently be `Pending`, `Reachable`,
`Unreachable`, `InvalidStart`, `InvalidGoal`, or `Cancelled`.

The result carries the environment revision used for the query. Implementations may share derived connectivity and
incremental work across queries; callers must not assume immediate completion or infer a concrete path from a positive
answer. Reachability is directional because rise and drop capabilities may differ. Cancellation preserves a readable
result with cancelled destination states.

## Determinism and ownership

Identifiers, fixed-point positions, integer movement primitives, environment revisions, command stamps, and explicit
`StepContext` values are the cross-module deterministic vocabulary. Implementations must not use wall-clock time to
decide how much planning work to perform. Returned paths and reachability results are immutable shared values; callers
must not retain writable implementation storage. Concrete implementations document their thread affinity, allocation,
and lifetime requirements.

Voxel payloads and material policy remain behind `UnrealVoxelSim.Navigation.Voxel.Api`. This API never depends on solid,
liquid, terrain, renderer, Qt, Unreal Engine, or ECS-registry implementation types.
