#pragma once
#include "UnrealVoxelSim/Navigation/Api/Cancel.h"
#include "UnrealVoxelSim/Navigation/Api/Start.h"
#include <variant>
namespace UnrealVoxelSim::Navigation::Api
{
class Command final
{
  public:
    Command(Start start) : Value_(std::move(start)) {}
    Command(Cancel cancel) : Value_(std::move(cancel)) {}
    [[nodiscard]] const Simulation::Api::CommandStamp &Stamp() const noexcept
    {
        return std::visit([](const auto &value) -> const Simulation::Api::CommandStamp & { return value.Stamp; }, Value_);
    }
    [[nodiscard]] const std::variant<Start, Cancel> &Value() const noexcept { return Value_; }
  private:
    std::variant<Start, Cancel> Value_;
};
} // namespace UnrealVoxelSim::Navigation::Api
