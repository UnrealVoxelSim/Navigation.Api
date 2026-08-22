#pragma once
#include "UnrealVoxelSim/Simulation/Api/StepContext.h"
namespace UnrealVoxelSim::Navigation::Api
{
class IFollowingUpdater
{
  public:
    virtual ~IFollowingUpdater() = default;
    virtual void UpdateFollowing(Simulation::Api::StepContext context) = 0;
};
} // namespace UnrealVoxelSim::Navigation::Api
