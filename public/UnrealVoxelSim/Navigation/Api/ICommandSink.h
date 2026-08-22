#pragma once
#include "UnrealVoxelSim/Navigation/Api/Command.h"
#include "UnrealVoxelSim/Navigation/Api/CommandError.h"
#include <expected>
#include <span>
namespace UnrealVoxelSim::Navigation::Api
{
class ICommandSink
{
  public:
    virtual ~ICommandSink() = default;
    [[nodiscard]] virtual std::expected<void, CommandError> Submit(std::span<const Command> commands) = 0;
};
} // namespace UnrealVoxelSim::Navigation::Api
