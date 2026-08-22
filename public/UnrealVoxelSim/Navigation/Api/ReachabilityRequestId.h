#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Navigation::Api
{

class ReachabilityRequestId final
{
  public:
    constexpr ReachabilityRequestId() noexcept = default;
    explicit constexpr ReachabilityRequestId(const std::uint64_t value) noexcept : Value_(value) {}
    [[nodiscard]] constexpr std::uint64_t Value() const noexcept { return Value_; }
    [[nodiscard]] constexpr bool IsValid() const noexcept { return Value_ != 0; }
    auto operator<=>(const ReachabilityRequestId &) const = default;

  private:
    std::uint64_t Value_{};
};

} // namespace UnrealVoxelSim::Navigation::Api
