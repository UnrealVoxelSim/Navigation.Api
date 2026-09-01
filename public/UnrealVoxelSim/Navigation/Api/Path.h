#pragma once
#include "UnrealVoxelSim/Navigation/Api/Waypoint.h"
#include <cstdint>
#include <vector>

namespace UnrealVoxelSim::Navigation::Api
{
	struct Path final
	{
		// TODO what is EnvironmentRevision? Does it change on any Voxel world update? What if updated voxel does not affect the path?
		std::uint64_t EnvironmentRevision{};
		std::uint64_t ValidationToken{};
		std::vector<Waypoint> Waypoints;
	};
}
