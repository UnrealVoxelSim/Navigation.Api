#pragma once
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionId.h"
#include "UnrealVoxelSim/Navigation/Api/Goal.h"
#include "UnrealVoxelSim/Simulation/Api/CommandStamp.h"

namespace UnrealVoxelSim::Navigation::Api
{
	/*
	 * TODO This command struct exposes implementation details (ExecutionId) to other domains.
	 */
	struct Start final
	{
		// TODO The purpose of this field is unclear. Considering potential cross-domain leak associated with CommandStamp, this concept needs a discussion. I suggest completely removing the Stamp and accept a cross-cutting concept that domains execute cross-domain requests on next simulation tick.
		Simulation::Api::CommandStamp Stamp;
		Ecs::Api::EntityId Entity;

		// TODO Other domains should not be concerned with manual execution ordering, unless this truly provides them some capability.
		ExecutionId Execution;

		Goal Destination;
	};
}
