#pragma once

#include <cstdint>

namespace UnrealVoxelSim::Navigation::Api
{
	enum class PrimitiveId : std::uint16_t
	{
		Invalid = 0,
		Traverse = 1,
		Rise = 2,
		Drop = 3,
	};

	namespace StandardPrimitives
	{
		inline constexpr PrimitiveId Traverse = PrimitiveId::Traverse;
		inline constexpr PrimitiveId Rise = PrimitiveId::Rise;
		inline constexpr PrimitiveId Drop = PrimitiveId::Drop;
	}
}
