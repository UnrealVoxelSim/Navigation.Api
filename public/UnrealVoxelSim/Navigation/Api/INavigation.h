#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Navigation/Api/Goal.h"
#include "UnrealVoxelSim/Navigation/Api/NavigationError.h"

#include <expected>

namespace UnrealVoxelSim::Navigation::Api
{
	class INavigation
	{
	public:
		virtual ~INavigation() = default;
		[[nodiscard]] virtual std::expected<void, NavigationError> BeginNavigateToGoal(Ecs::Api::EntityId entity, Goal goal) = 0;
		virtual void CancelNavigateToGoal(Ecs::Api::EntityId entity) noexcept = 0;
	};
}
