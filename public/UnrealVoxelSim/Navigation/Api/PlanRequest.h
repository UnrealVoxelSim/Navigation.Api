#pragma once
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Navigation/Api/RequestId.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct PlanRequest final
	{
		// TODO This ID seems to be client-generated. I think this is a bad idea, because it shifts ID generation burden
		// Onto the caller. Calling semantics are unclear as well. How to generate this ID? Should it be unique? Etc.
		// Maybe we can return a promise-like structure from IPlanner::Begin(), that encapsulates request progression tracking.
		RequestId Request;
		Movement::Api::ProfileId Profile;
		Spatial::Api::Position Start;
		Spatial::Api::Position Goal;
	};
}
