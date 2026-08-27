#pragma once
#include "UnrealVoxelSim/Navigation/Api/Command.h"
#include "UnrealVoxelSim/Navigation/Api/CommandError.h"
#include <expected>
#include <span>

namespace UnrealVoxelSim::Navigation::Api
{
	/* TODO Probably needs to be split into multiple sinks
	 * To respect Interface Segregation Principle, each command requires its own sink.
	 * Otherwise ICommandSink can become a god-object responsible for all possible interactions with Navigation domain.
	 */
	class ICommandSink
	{
	public:
		virtual ~ICommandSink() = default;
		[[nodiscard]] virtual std::expected<void, CommandError> Submit(std::span<const Command> commands) = 0;
	};
}
