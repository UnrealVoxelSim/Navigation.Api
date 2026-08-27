#pragma once
#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Navigation::Api
{
	/* TODO This interface exposes a Navigation-internal simulation phase as public API.
	*
	* "UpdateFollowing" is not really a service that other modules need from Navigation. It describes
	* a piece of Navigation's internal per-step processing and requires callers to know that following
	* must be updated explicitly as part of the simulation pipeline.
	*
	* This leaks execution order and lifecycle concerns across the module boundary. Questions such as
	* when following is updated, how often it runs, and where it belongs relative to pathfinding,
	* movement, and command processing should be owned by the simulation/navigation implementation,
	* not by Navigation.Api.
	*
	* Navigation.Api should expose domain capabilities and state related to following. If following
	* requires periodic simulation work, the corresponding internal system should participate in a
	* simulation-owned step/phase contract instead of exposing a dedicated updater interface.
	*/
	class IFollowingUpdater
	{
	public:
		virtual ~IFollowingUpdater() = default;
		virtual void UpdateFollowing(Simulation::Api::StepContext context) = 0;
	};
}
