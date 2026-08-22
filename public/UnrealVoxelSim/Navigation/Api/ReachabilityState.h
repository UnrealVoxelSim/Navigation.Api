#pragma once

namespace UnrealVoxelSim::Navigation::Api
{

enum class ReachabilityState
{
    Pending,
    Reachable,
    Unreachable,
    InvalidStart,
    InvalidGoal,
    Cancelled,
};

} // namespace UnrealVoxelSim::Navigation::Api
