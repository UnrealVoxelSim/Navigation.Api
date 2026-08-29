#pragma once

#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionState.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct ExecutionStateComponent final
	{
		// TODO since Execution States are now attached to each entity, do we still need ExecutionId? Probably not.
		// If an entity can do multiple navigation executions, it is better to attach another ExecutionComponent.
		ExecutionId Execution;
		ExecutionState State{ExecutionState::Planning};
	};
}
