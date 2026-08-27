#pragma once

namespace UnrealVoxelSim::Navigation::Api
{
	enum class ReachabilityError
	{
		InvalidRequest,
		UnknownProfile,
		EmptyDestinations,
		DuplicateRequest,
	};
} // namespace UnrealVoxelSim::Navigation::Api
