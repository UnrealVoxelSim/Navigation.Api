#pragma once
#include "UnrealVoxelSim/Math/Api/FixedPointScalar.h"
#include "UnrealVoxelSim/Spatial/Api/Position.h"

namespace UnrealVoxelSim::Navigation::Api
{
	struct Goal final
	{
		Spatial::Api::Position Location;
		Math::Api::FixedPointScalar ArrivalRadius{
			Math::Api::FixedPointScalar::FromRaw(Math::Api::FixedPointScalar::OneRaw / 4)};
	};
}
