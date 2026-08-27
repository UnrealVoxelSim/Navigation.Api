#pragma once
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Simulation/Api/CommandStamp.h"

namespace UnrealVoxelSim::Navigation::Api
{
	// TODO Purpose unclear. Cancel what?
	struct Cancel final
	{
		// TODO I am not sure, but this looks like a cross-domain leak. Why a struct from Simulation.Api is called "CommandStamp"? What does Simulation have to do with commands? Investigation needed.
		Simulation::Api::CommandStamp Stamp;
		Ecs::Api::EntityId Entity;
		ExecutionId Execution;
	};
}
