#pragma once

#include "UnrealVoxelSim/Navigation/Api/ReachabilityRequestId.h"
#include "UnrealVoxelSim/Navigation/Api/ReachabilityState.h"

#include <cstdint>
#include <vector>

namespace UnrealVoxelSim::Navigation::Api
{

struct ReachabilityResult final
{
    ReachabilityRequestId Request;
    std::uint64_t EnvironmentRevision{};
    std::vector<ReachabilityState> Destinations;

    [[nodiscard]] bool IsComplete() const noexcept;
};

inline bool ReachabilityResult::IsComplete() const noexcept
{
    for (const auto state : Destinations)
        if (state == ReachabilityState::Pending) return false;
    return true;
}

} // namespace UnrealVoxelSim::Navigation::Api
