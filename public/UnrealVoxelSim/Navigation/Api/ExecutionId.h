#pragma once
#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Navigation::Api
{
	class ExecutionId final
	{
	public:
		constexpr ExecutionId() noexcept = default;

		explicit constexpr ExecutionId(const std::uint64_t value) noexcept : m_Value(value)
		{
		}

		[[nodiscard]] constexpr bool IsValid() const noexcept { return m_Value != 0; }
		[[nodiscard]] constexpr std::uint64_t Value() const noexcept { return m_Value; }
		auto operator<=>(const ExecutionId&) const = default;

	private:
		std::uint64_t m_Value{};
	};
} // namespace UnrealVoxelSim::Navigation::Api
