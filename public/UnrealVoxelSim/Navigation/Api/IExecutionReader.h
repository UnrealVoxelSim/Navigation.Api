#pragma once
#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Navigation/Api/ExecutionStatus.h"
#include <optional>

namespace UnrealVoxelSim::Navigation::Api
{
	class IExecutionReader
	{
	public:
		virtual ~IExecutionReader() = default;
		[[nodiscard]] virtual std::optional<ExecutionStatus> ReadExecution(Ecs::Api::EntityId entity) const noexcept =
		0;
	};
}
