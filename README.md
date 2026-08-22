# UnrealVoxelSim.Navigation.Api

External navigation contracts for task executors, AI queries, planning implementations, and following implementations.
A navigation execution is a subordinate asynchronous attempt to reach a spatial goal; it is not a pawn task or order.

Domain-owned commands carry canonical simulation stamps and are processed only when the composition root invokes the
navigation processor. Immutable paths are an implementation-facing contract between planners and followers; tasks
observe execution status rather than pathfinding internals.

`IReachability` exposes asynchronous source-to-many queries for task planning and AI. Results are profile-specific,
directional, tagged with the environment revision, and may remain pending while the implementation consumes its
deterministic per-tick work budget. Voxel layers remain behind `Navigation.Voxel.Api`; neither this contract nor callers
depend on layer payload types.
