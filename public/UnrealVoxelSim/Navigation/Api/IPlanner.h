#pragma once
#include "UnrealVoxelSim/Navigation/Api/Path.h"
#include "UnrealVoxelSim/Navigation/Api/PlanError.h"
#include "UnrealVoxelSim/Navigation/Api/PlanRequest.h"
#include "UnrealVoxelSim/Navigation/Api/PlanState.h"
#include "UnrealVoxelSim/Simulation/Api/StepContext.h"
#include <expected>
#include <memory>

namespace UnrealVoxelSim::Navigation::Api
{
	/* TODO IPlanner mostly represents a valid Navigation domain service, but Advance() does not
	* belong to this public contract.
	*
	* Begin, Cancel, State and ReadPath describe planner capabilities that Navigation consumers
	* legitimately need. Advance(), however, exposes an implementation/lifecycle detail: callers
	* must know that planning is incremental and must be progressed explicitly during simulation
	* execution.
	*
	* Questions such as when planning advances, how much work it performs per step, and where it
	* runs relative to other simulation phases belong to the simulation execution model and the
	* Navigation implementation, not to Navigation.Api.
	*
	* The planner implementation should participate in the simulation-owned step/phase mechanism
	* internally, while IPlanner remains focused on submitting, cancelling and querying plans.
	*/
	class IPlanner
	{
	public:
		virtual ~IPlanner() = default;
		[[nodiscard]] virtual std::expected<void, PlanError> Begin(PlanRequest request) = 0;
		virtual void Cancel(RequestId request) noexcept = 0;
		virtual void Advance(Simulation::Api::StepContext context) = 0;
		[[nodiscard]] virtual std::uint64_t CurrentEnvironmentRevision() const noexcept = 0;
		[[nodiscard]] virtual bool IsPathCurrent(const Path& path) const noexcept = 0;
		// TODO Probably should be "GetPlanState"
		[[nodiscard]] virtual PlanState State(RequestId request) const noexcept = 0;
		// TODO Make it GetPath()
		[[nodiscard]] virtual std::shared_ptr<const Path> ReadPath(RequestId request) const noexcept = 0;
	};
}
