#pragma once
#include <compare>
#include <cstdint>
namespace UnrealVoxelSim::Navigation::Api
{
class MovementPrimitiveId final
{
  public:
    constexpr MovementPrimitiveId() noexcept = default;
    explicit constexpr MovementPrimitiveId(const std::uint16_t value) noexcept : Value_(value) {}
    [[nodiscard]] constexpr bool IsValid() const noexcept { return Value_ != 0; }
    [[nodiscard]] constexpr std::uint16_t Value() const noexcept { return Value_; }
    auto operator<=>(const MovementPrimitiveId &) const = default;
  private:
    std::uint16_t Value_{};
};
namespace StandardPrimitives
{
inline constexpr MovementPrimitiveId Traverse{1};
inline constexpr MovementPrimitiveId Rise{2};
inline constexpr MovementPrimitiveId Drop{3};
}
} // namespace UnrealVoxelSim::Navigation::Api
