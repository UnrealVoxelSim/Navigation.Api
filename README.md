# UnrealVoxelSim.Navigation.Api

Representation-independent navigation contracts.

`INavigation::Start(entity, goal)` and `Cancel(entity)` execute synchronously. Navigation owns attachment and mutation
of `ExecutionStateComponent` and its private following components. Callers may observe the public execution state but
do not manufacture execution identifiers, command stamps, or planner request identifiers.

`IPlanner::Begin` returns a planner-owned `PlanRequestId`. Incremental planner execution is an implementation lifecycle
concern and is not part of the public planner capability.
