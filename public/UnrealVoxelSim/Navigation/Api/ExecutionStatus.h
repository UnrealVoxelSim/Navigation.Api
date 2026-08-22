#pragma once
#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionState.h"
namespace UnrealVoxelSim::Navigation::Api
{
struct ExecutionStatus final { ExecutionId Execution; ExecutionState State; };
} // namespace UnrealVoxelSim::Navigation::Api
