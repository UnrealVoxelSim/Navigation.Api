#pragma once
#include "UnrealVoxelSim/Navigation/Api/PrimitiveId.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct Waypoint final
	{
		Spatial::Api::Position Location;
		PrimitiveId Primitive;
	};
}
