//--------------------------------------------------------------------------------
// Vector3.h
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

#ifndef OUGI_MATH_VECTOR3_H
#define OUGI_MATH_VECTOR3_H

#include "Functions.h"
#include "../../Standard/include/Debug.h"

namespace Ougi
{
	class Vector3
	{
	public:
		float x, y, z, __pad_w;

	public:
		Vector3()													: x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(const float _x, const float _y, const float _z)		: x(_x), y(_y), z(_z) {}

		Vector3 operator-() const									{ return Vector3(-x, -y, -z); }

		Vector3 operator+(const Vector3& addend) const				{ return Vector3(x + addend.x, y + addend.y, z + addend.z); }
		Vector3 operator-(const Vector3& subtrahend) const			{ return Vector3(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z); }
		Vector3 operator*(const float multiplier) const				{ return Vector3(x * multiplier, y * multiplier, z * multiplier); }
		float   operator*(const Vector3& multiplier) const			{ return Dot(multiplier); }
		Vector3 operator/(const float divisor) const				{ return Vector3(x / divisor, y / divisor, z / divisor); }

		Vector3 operator+=(const Vector3& addend)					{ x += addend.x; y += addend.y; z += addend.z; return *this; }
		Vector3 operator-=(const Vector3& subtrahend)				{ x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z; return *this; }
		Vector3 operator*=(const float multiplier)					{ x *= multiplier; y *= multiplier; z *= multiplier; return *this; }
		Vector3 operator/=(const float divisor)						{ x /= divisor; y /= divisor; z /= divisor; return *this; }

		virtual bool operator==(const Vector3& rhs) const;
		bool MagnitudeEquals(const Vector3& rhs, const float tolerance = 0.0f) const;
		bool DirectionEquals(const Vector3& rhs, const float tolerance = 0.0f) const;
		virtual bool operator<(const Vector3& rhs) const;

		float LengthSquared() const									{ return (x * x) + (y * y) + (z * z); }
		float Length() const										{ return Ougi::Sqrt(LengthSquared()); }

		Vector3 Normalize();
		Vector3 Normalized() const;

		float Dot(const Vector3& multiplier) const					{ return (x * multiplier.x) + (y * multiplier.y) + (z * multiplier.z); }
		Vector3 Cross(const Vector3& multiplier) const;
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::Vector3& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}
#endif

#endif