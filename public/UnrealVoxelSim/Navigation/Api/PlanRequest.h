#pragma once
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct PlanRequest final
	{
		Movement::Api::ProfileId Profile;
		Spatial::Api::Position Start;
		Spatial::Api::Position Goal;
	};
}
