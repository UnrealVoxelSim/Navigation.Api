#pragma once
#include "UnrealVoxelSim/Navigation/Api/MovementPrimitiveId.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct Waypoint final
	{
		Spatial::Api::Position Location;
		MovementPrimitiveId Primitive;
	};
}
