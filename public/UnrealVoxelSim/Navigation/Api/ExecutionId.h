#pragma once
#include <compare>
#include <cstdint>
namespace UnrealVoxelSim::Navigation::Api
{
class ExecutionId final
{
  public:
    constexpr ExecutionId() noexcept = default;
    explicit constexpr ExecutionId(const std::uint64_t value) noexcept : Value_(value) {}
    [[nodiscard]] constexpr bool IsValid() const noexcept { return Value_ != 0; }
    [[nodiscard]] constexpr std::uint64_t Value() const noexcept { return Value_; }
    auto operator<=>(const ExecutionId &) const = default;
  private:
    std::uint64_t Value_{};
};
} // namespace UnrealVoxelSim::Navigation::Api
