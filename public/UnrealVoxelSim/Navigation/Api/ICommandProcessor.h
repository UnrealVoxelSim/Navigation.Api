#pragma once
#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Navigation::Api
{
	/* TODO This interface mixes Navigation's domain API with simulation pipeline orchestration.
	 *
	 * "ProcessCommands" looks like a Navigation capability, but the interface does not actually
	 * accept commands. Instead, it receives StepContext and is expected to be invoked at some
	 * particular point of every simulation step. This makes it a lifecycle/pipeline contract
	 * disguised as a domain service.
	 *
	 * The questions of when command processing runs, how often it runs, and in what order relative
	 * to other simulation phases belong to the simulation execution model, not Navigation.Api.
	 *
	 * Navigation should expose domain concepts such as navigation commands and command submission.
	 * If Navigation requires a simulation phase in which queued commands are consumed, its internal
	 * implementation should participate in a simulation-owned execution/phase contract instead.
	 *
	 * The problem is very similar to Movement::Api::IUpdater. They probably require a similar solution.
	 */
	class ICommandProcessor
	{
	public:
		virtual ~ICommandProcessor() = default;
		virtual void ProcessCommands(Simulation::Api::StepContext context) = 0;
	};
} // namespace UnrealVoxelSim::Navigation::Api
