#pragma once
#include "UnrealVoxelSim/Navigation/Api/Path.h"
#include "UnrealVoxelSim/Navigation/Api/PlanError.h"
#include "UnrealVoxelSim/Navigation/Api/PlanRequest.h"
#include "UnrealVoxelSim/Navigation/Api/PlanState.h"
#include "UnrealVoxelSim/Simulation/Api/StepContext.h"
#include <expected>
#include <memory>
namespace UnrealVoxelSim::Navigation::Api
{
class IPlanner
{
  public:
    virtual ~IPlanner() = default;
    [[nodiscard]] virtual std::expected<void, PlanError> Begin(PlanRequest request) = 0;
    virtual void Cancel(RequestId request) noexcept = 0;
    virtual void Advance(Simulation::Api::StepContext context) = 0;
    [[nodiscard]] virtual std::uint64_t CurrentEnvironmentRevision() const noexcept = 0;
    [[nodiscard]] virtual bool IsPathCurrent(const Path &path) const noexcept = 0;
    [[nodiscard]] virtual PlanState State(RequestId request) const noexcept = 0;
    [[nodiscard]] virtual std::shared_ptr<const Path> ReadPath(RequestId request) const noexcept = 0;
};
} // namespace UnrealVoxelSim::Navigation::Api
