//--------------------------------------------------------------------------------
// Vector4.cpp
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

#include "../include/Vector4.h"

bool Ougi::Vector4::Equals(const Ougi::Vector4& rhs, const float tolerance) const
{
	return MagnitudeEquals(rhs, tolerance) && DirectionEquals(rhs, tolerance);
}

bool Ougi::Vector4::MagnitudeEquals(const Ougi::Vector4& rhs, const float tolerance) const
{
	return Ougi::Abs(LengthSquared() - rhs.LengthSquared()) < tolerance;
}

bool Ougi::Vector4::DirectionEquals(const Ougi::Vector4& rhs, const float tolerance) const
{
	// TODO
	return false;
}

Ougi::Vector4 Ougi::Vector4::Normalize()
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y) + (z * z) + (w * w));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	w *= inverseLength;
	return (*this);
}

Ougi::Vector4 Ougi::Vector4::Normalized() const
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y) + (z * z) + (w * w));
	return Vector4(x * inverseLength, y * inverseLength, z * inverseLength, w * inverseLength);
}