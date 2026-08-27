#pragma once
#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Navigation::Api
{
	// TODO This type is used broadly in different modules. Verification is needed, whether all usage instances truly have to share this type, of need their own Request Ids.
	class RequestId final
	{
	public:
		constexpr RequestId() noexcept = default;

		explicit constexpr RequestId(const std::uint64_t value) noexcept : m_Value(value)
		{
		}

		[[nodiscard]] constexpr bool IsValid() const noexcept { return m_Value != 0; }
		[[nodiscard]] constexpr std::uint64_t Value() const noexcept { return m_Value; }
		auto operator<=>(const RequestId&) const = default;

	private:
		std::uint64_t m_Value{};
	};
}
