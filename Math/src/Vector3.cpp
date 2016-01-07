//--------------------------------------------------------------------------------
// Vector3.cpp
// Author: David Hanna
// Copyright (C) 20xx David Hanna, Inc.
//
// This file is part of Ougi Engine.
//
// Ougi Engine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Ougi Engine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Ougi Engine.  If not, see <http://www.gnu.org/licenses/>.
//--------------------------------------------------------------------------------

#include "../include/Vector3.h"

bool Ougi::Vector3::MagnitudeEquals(const Ougi::Vector3& rhs, const float tolerance) const
{
	return Ougi::Abs(LengthSquared() - rhs.LengthSquared()) <= tolerance;
}

bool Ougi::Vector3::DirectionEquals(const Ougi::Vector3& rhs, const float tolerance) const
{
	// TODO
	return false;
}

Ougi::Vector3 Ougi::Vector3::Normalize()
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y) + (z * z));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	return (*this);
}

Ougi::Vector3 Ougi::Vector3::Normalized() const
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y) + (z * z));
	return Vector3(x * inverseLength, y * inverseLength, z * inverseLength);
}

Ougi::Vector3 Ougi::Vector3::Cross(const Ougi::Vector3& multiplier) const
{
	return Vector3(y * multiplier.z - z * multiplier.y, z * multiplier.x - x * multiplier.z, x * multiplier.y - y * multiplier.x);
}