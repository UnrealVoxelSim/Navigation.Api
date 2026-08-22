#pragma once
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Simulation/Api/CommandStamp.h"
namespace UnrealVoxelSim::Navigation::Api
{
struct Cancel final
{
    Simulation::Api::CommandStamp Stamp;
    Ecs::Api::EntityId Entity;
    ExecutionId Execution;
};
} // namespace UnrealVoxelSim::Navigation::Api
