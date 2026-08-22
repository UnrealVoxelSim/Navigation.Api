#pragma once
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Navigation/Api/Goal.h"
#include "UnrealVoxelSim/Simulation/Api/CommandStamp.h"
namespace UnrealVoxelSim::Navigation::Api
{
struct Start final
{
    Simulation::Api::CommandStamp Stamp;
    Ecs::Api::EntityId Entity;
    ExecutionId Execution;
    Goal Destination;
};
} // namespace UnrealVoxelSim::Navigation::Api
