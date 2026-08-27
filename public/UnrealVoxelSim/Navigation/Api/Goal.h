#pragma once
#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/Scalar.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct Goal final
	{
		Movement::Api::Position Location;
		Movement::Api::Scalar ArrivalRadius{Movement::Api::Scalar::FromRaw(Movement::Api::Scalar::OneRaw / 4)};
	};
}
