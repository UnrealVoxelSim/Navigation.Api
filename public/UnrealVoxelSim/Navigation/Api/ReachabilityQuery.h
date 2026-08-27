#pragma once

#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Navigation/Api/ReachabilityRequestId.h"

#include <vector>

namespace UnrealVoxelSim::Navigation::Api
{
	struct ReachabilityQuery final
	{
		ReachabilityRequestId Request;
		Movement::Api::ProfileId Profile;
		Movement::Api::Position Start;
		std::vector<Movement::Api::Position> Destinations;
	};
}
