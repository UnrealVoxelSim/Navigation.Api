#pragma once
#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionState.h"

namespace UnrealVoxelSim::Navigation::Api
{
	// TODO Name of this struct is difficult to distinguish from ExecutionState. Basically "Status" is a superset of "State" for some reason, which adds ExecutionId field. Renaming required.
	struct ExecutionStatus final
	{
		ExecutionId Execution;
		ExecutionState State;
	};
}
