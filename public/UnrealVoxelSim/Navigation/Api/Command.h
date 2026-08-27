#pragma once
#include "UnrealVoxelSim/Navigation/Api/Cancel.h"
#include "UnrealVoxelSim/Navigation/Api/Start.h"
#include <variant>

namespace UnrealVoxelSim::Navigation::Api
{
	// TODO Types in Api modules are intended for cross-domain usage. Is it a good idea to expose internal command structs?
	class Command final
	{
	public:
		Command(Start start) : m_Value(std::move(start))
		{
		}

		Command(Cancel cancel) : m_Value(std::move(cancel))
		{
		}

		[[nodiscard]] const Simulation::Api::CommandStamp& Stamp() const noexcept
		{
			return std::visit([](const auto& value) -> const Simulation::Api::CommandStamp& { return value.Stamp; },
			                  m_Value);
		}

		[[nodiscard]] const std::variant<Start, Cancel>& Value() const noexcept { return m_Value; }

	private:
		std::variant<Start, Cancel> m_Value;
	};
} // namespace UnrealVoxelSim::Navigation::Api
