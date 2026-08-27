#pragma once
#include "UnrealVoxelSim/Navigation/Api/Waypoint.h"
#include <cstdint>
#include <vector>

namespace UnrealVoxelSim::Navigation::Api
{
	struct Path final
	{
		std::uint64_t EnvironmentRevision{};
		std::uint64_t ValidationToken{};
		std::vector<Waypoint> Waypoints;
	};
}
