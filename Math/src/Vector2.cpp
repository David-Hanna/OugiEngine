//--------------------------------------------------------------------------------
// Vector2.cpp
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

#include "../include/Vector2.h"

bool Ougi::Vector2::MagnitudeEquals(const Ougi::Vector2& rhs, const float tolerance) const
{
	return Ougi::Abs(LengthSquared() - rhs.LengthSquared()) <= tolerance;
}

bool Ougi::Vector2::DirectionEquals(const Ougi::Vector2& rhs, const float tolerance) const
{
	return ((y < 0.0f && rhs.y < 0.0f) || (y >= 0.0f && rhs.y >= 0.0f))
		&& ((x < 0.0f && rhs.x < 0.0f) || (x >= 0.0f && rhs.x >= 0.0f)) 
		&& ( Abs((y / x) - (rhs.y / rhs.x)) <= tolerance );
}

Ougi::Vector2 Ougi::Vector2::Normalize()
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y));
	x *= inverseLength;
	y *= inverseLength;
	return (*this);
}

Ougi::Vector2 Ougi::Vector2::Normalized() const
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y));
	return Vector2(x * inverseLength, y * inverseLength);
}