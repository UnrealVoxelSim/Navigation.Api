#pragma once

#include "UnrealVoxelSim/Navigation/Api/ExecutionState.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct ExecutionStateComponent final
	{
		ExecutionState State{ExecutionState::Planning};
	};
}
