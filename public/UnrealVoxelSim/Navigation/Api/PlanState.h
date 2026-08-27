#pragma once
namespace UnrealVoxelSim::Navigation::Api
{
	enum class PlanState
	{
		Pending,
		Complete,
		Unreachable,
		Cancelled
	};
}
