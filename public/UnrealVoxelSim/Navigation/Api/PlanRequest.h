#pragma once
#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Navigation/Api/RequestId.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct PlanRequest final
	{
		RequestId Request;
		Movement::Api::ProfileId Profile;
		Movement::Api::Position Start;
		Movement::Api::Position Goal;
	};
} // namespace UnrealVoxelSim::Navigation::Api
