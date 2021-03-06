//--------------------------------------------------------------------------------
// Vector4.h
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

#ifndef OUGI_MATH_VECTOR4_H
#define OUGI_MATH_VECTOR4_H

#include "Functions.h"
#include "../../Common/include/Debug.h"

namespace Ougi
{
	class Vector4
	{
	public:
		float x, y, z, w;

	public:
		Vector4()													: x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		Vector4(const float _x, const float _y, const float _z, const float _w) : x(_x), y(_y), z(_z), w(_w) {}

		Vector4 operator-() const									{ return Vector4(-x, -y, -z, -w); }

		Vector4 operator+(const Vector4& addend) const				{ return Vector4(x + addend.x, y + addend.y, z + addend.z, w + addend.w); }
		Vector4 operator-(const Vector4& subtrahend) const			{ return Vector4(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z, w - subtrahend.w); }
		Vector4 operator*(const float multiplier) const				{ return Vector4(x * multiplier, y * multiplier, z * multiplier, w * multiplier); }
		float   operator*(const Vector4& multiplier) const			{ return Dot(multiplier); }
		Vector4 operator/(const float divisor) const				{ return Vector4(x / divisor, y / divisor, z / divisor, w / divisor); }

		Vector4 operator+=(const Vector4& addend)					{ x += addend.x; y += addend.y; z += addend.z; w += addend.w; return *this; }
		Vector4 operator-=(const Vector4& subtrahend)				{ x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z; w -= subtrahend.w; return *this; }
		Vector4 operator*=(const float multiplier)					{ x *= multiplier; y *= multiplier; z *= multiplier; w *= multiplier; return *this; }
		Vector4 operator/=(const float divisor)						{ x /= divisor; y /= divisor; z /= divisor; w /= divisor; return *this; }

		bool MagnitudeEquals(const Vector4& rhs, const float tolerance = 0.0f) const;
		bool DirectionEquals(const Vector4& rhs, const float tolerance = 0.0f) const;

		float LengthSquared() const									{ return (x * x) + (y * y) + (z * z) + (w * w); }
		float Length() const										{ return Ougi::Sqrt(LengthSquared()); }

		Vector4 Normalize();
		Vector4 Normalized() const;

		float Dot(const Vector4& multiplier) const					{ return (x * multiplier.x) + (y * multiplier.y) + (z * multiplier.z) + (w * multiplier.w); }
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::Vector4& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
}
#endif

#endif