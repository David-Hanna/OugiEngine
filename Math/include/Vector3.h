#pragma once

//--------------------------------------------------------------------------------
// Vector3.h
//--------------------------------------------------------------------------------

#include <ostream>

#include "..\Functions\FundamentalFunctions.h"

namespace HM
{
	class Vector3
	{
	public:
		float x, y, z;

	public:
		Vector3()													: x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(const float _x, const float _y, const float _z)		: x(_x), y(_y), z(_z) {}

		Vector3 operator-() const									{ return Vector3(-x, -y, -z); }

		Vector3 operator+(const Vector3& addend) const				{ return Vector3(x + addend.x, y + addend.y, z + addend.z); }
		Vector3 operator-(const Vector3& subtrahend) const			{ return Vector3(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z); }
		Vector3 operator*(const float multiplier) const				{ return Vector3(x * multiplier, y * multiplier, z * multiplier); }
		Vector3 operator/(const float divisor) const				{ return Vector3(x / divisor, y / divisor, z / divisor); }

		Vector3 operator+=(const Vector3& addend)					{ x += addend.x; y += addend.y; z += addend.z; return *this; }
		Vector3 operator-=(const Vector3& subtrahend)				{ x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z; return *this; }
		Vector3 operator*=(const float multiplier)					{ x *= multiplier; y *= multiplier; z *= multiplier; return *this; }
		Vector3 operator/=(const float divisor)						{ x /= divisor; y /= divisor; z /= divisor; return *this; }

		bool operator==(const Vector3& rhs) const					{ return (x == rhs.x) && (y == rhs.y) && (z == rhs.z); }
		bool equals(const Vector3& rhs, const float toleranceSquared = 0.0f) const;

		float LengthSquared() const									{ return (x * x) + (y * y) + (z * z); }
		float Length() const										{ return HM::sqrt(LengthSquared()); }

		void Normalize();
		Vector3 Normalized() const;

		float Dot(const Vector3& multiplier) const					{ return (x * multiplier.x) + (y * multiplier.y) + (z * multiplier.z); }
		Vector3 Cross(const Vector3& multiplier) const;
	};
}

std::ostream& operator<<(std::ostream& out, const HM::Vector3& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}