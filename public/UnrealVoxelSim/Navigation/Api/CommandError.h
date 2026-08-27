#pragma once
#include <cstddef>

namespace UnrealVoxelSim::Navigation::Api
{
	enum class CommandErrorType
	{
		InvalidStamp, InvalidEntity, InvalidExecution, InvalidGoal, DuplicateStamp, TickAlreadyProcessed
	};

	struct CommandError final
	{
		CommandErrorType Error;
		std::size_t CommandIndex{};
	};
} // namespace UnrealVoxelSim::Navigation::Api
