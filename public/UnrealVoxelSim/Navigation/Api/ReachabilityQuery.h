#pragma once

#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Navigation/Api/ReachabilityRequestId.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

#include <vector>

namespace UnrealVoxelSim::Navigation::Api
{
	struct ReachabilityQuery final
	{
		ReachabilityRequestId Request;
		Movement::Api::ProfileId Profile;
		Spatial::Api::Position Start;
		std::vector<Spatial::Api::Position> Destinations;
	};
}
