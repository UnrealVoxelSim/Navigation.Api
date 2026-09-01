#pragma once

#include "UnrealVoxelSim/Navigation/Api/ReachabilityError.h"
#include "UnrealVoxelSim/Navigation/Api/ReachabilityQuery.h"
#include "UnrealVoxelSim/Navigation/Api/ReachabilityResult.h"

#include <expected>
#include <memory>

namespace UnrealVoxelSim::Navigation::Api
{
	class IReachability
	{
	public:
		virtual ~IReachability() = default;
		// TODO ReachabilityQuery forces caller to generate ReachabilityRequestId. IReachability should be responsible for this, as IPlanner is responsible for PlanRequestId.
		[[nodiscard]] virtual std::expected<void, ReachabilityError> BeginReachabilityQuery(ReachabilityQuery query) = 0;
		virtual void CancelReachabilityQuery(ReachabilityRequestId request) noexcept = 0;
		[[nodiscard]] virtual std::shared_ptr<const ReachabilityResult> GetReachabilityQueryResult(
			ReachabilityRequestId request) const noexcept = 0;
	};
}
