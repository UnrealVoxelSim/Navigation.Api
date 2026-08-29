#pragma once

#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionState.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct NavigationExecutionComponent final
	{
		ExecutionId Execution;
		ExecutionState State{ExecutionState::Planning};
	};
} // namespace UnrealVoxelSim::Navigation::Api
