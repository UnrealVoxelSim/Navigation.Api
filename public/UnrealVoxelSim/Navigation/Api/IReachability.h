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
		[[nodiscard]] virtual std::expected<void, ReachabilityError> BeginReachability(ReachabilityQuery query) = 0;
		virtual void CancelReachability(ReachabilityRequestId request) noexcept = 0;
		[[nodiscard]] virtual std::shared_ptr<const ReachabilityResult> ReadReachability(
			ReachabilityRequestId request) const noexcept = 0;
	};
}
