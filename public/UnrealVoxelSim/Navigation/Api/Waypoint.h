#pragma once
#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Navigation/Api/MovementPrimitiveId.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct Waypoint final
	{
		Movement::Api::Position Location;
		MovementPrimitiveId Primitive;
	};
}
