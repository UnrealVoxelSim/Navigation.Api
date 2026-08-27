#pragma once
#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Navigation::Api
{
	class MovementPrimitiveId final
	{
	public:
		constexpr MovementPrimitiveId() noexcept = default;

		explicit constexpr MovementPrimitiveId(const std::uint16_t value) noexcept : m_Value(value)
		{
		}

		[[nodiscard]] constexpr bool IsValid() const noexcept { return m_Value != 0; }
		[[nodiscard]] constexpr std::uint16_t Value() const noexcept { return m_Value; }
		auto operator<=>(const MovementPrimitiveId&) const = default;

	private:
		std::uint16_t m_Value{};
	};

	// TODO Can it be an enum? Not sure about it, discussion needed.
	namespace StandardPrimitives
	{
		inline constexpr MovementPrimitiveId Traverse{1};
		inline constexpr MovementPrimitiveId Rise{2};
		inline constexpr MovementPrimitiveId Drop{3};
	}
}
