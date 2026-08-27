#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Navigation::Api
{

class ReachabilityRequestId final
{
  public:
    constexpr ReachabilityRequestId() noexcept = default;
    explicit constexpr ReachabilityRequestId(const std::uint64_t value) noexcept : m_Value(value) {}
    [[nodiscard]] constexpr std::uint64_t Value() const noexcept { return m_Value; }
    [[nodiscard]] constexpr bool IsValid() const noexcept { return m_Value != 0; }
    auto operator<=>(const ReachabilityRequestId &) const = default;

  private:
    std::uint64_t m_Value{};
};

} // namespace UnrealVoxelSim::Navigation::Api
