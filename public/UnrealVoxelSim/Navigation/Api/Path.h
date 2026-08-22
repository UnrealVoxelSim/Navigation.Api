#pragma once
#include "UnrealVoxelSim/Navigation/Api/Waypoint.h"
#include <cstdint>
#include <vector>
namespace UnrealVoxelSim::Navigation::Api
{
struct Path final
{
    std::uint64_t EnvironmentRevision{};
    std::vector<Waypoint> Waypoints;
};
} // namespace UnrealVoxelSim::Navigation::Api
