#pragma once
#include "UnrealVoxelSim/Navigation/Api/Path.h"
#include "UnrealVoxelSim/Navigation/Api/PlanError.h"
#include "UnrealVoxelSim/Navigation/Api/PlanRequest.h"
#include "UnrealVoxelSim/Navigation/Api/PlanRequestId.h"
#include "UnrealVoxelSim/Navigation/Api/PlanState.h"
#include <expected>
#include <memory>

namespace UnrealVoxelSim::Navigation::Api
{
	class IPlanner
	{
	public:
		virtual ~IPlanner() = default;
		[[nodiscard]] virtual std::expected<PlanRequestId, PlanError> BeginPathPlanning(PlanRequest request) = 0;
		virtual void CancelPathPlanning(PlanRequestId request) noexcept = 0;
		[[nodiscard]] virtual std::uint64_t GetCurrentEnvironmentRevision() const noexcept = 0;
		[[nodiscard]] virtual bool IsPathCurrent(const Path& path) const noexcept = 0;
		[[nodiscard]] virtual PlanState GetPlanState(PlanRequestId request) const noexcept = 0;
		[[nodiscard]] virtual std::shared_ptr<const Path> GetPath(PlanRequestId request) const noexcept = 0;
	};
}
