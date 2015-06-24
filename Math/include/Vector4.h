#pragma once

//--------------------------------------------------------------------------------
// Vector4.h
//--------------------------------------------------------------------------------

#include <ostream>

#include "..\Functions\FundamentalFunctions.h"

namespace HM
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
		Vector4 operator/(const float divisor) const				{ return Vector4(x / divisor, y / divisor, z / divisor, w / divisor); }

		Vector4 operator+=(const Vector4& addend)					{ x += addend.x; y += addend.y; z += addend.z; w += addend.w; return *this; }
		Vector4 operator-=(const Vector4& subtrahend)				{ x -= subtrahend.x; y -= subtrahend.y; z -= subtrahend.z; w -= subtrahend.w; return *this; }
		Vector4 operator*=(const float multiplier)					{ x *= multiplier; y *= multiplier; z *= multiplier; w *= multiplier; return *this; }
		Vector4 operator/=(const float divisor)						{ x /= divisor; y /= divisor; z /= divisor; w /= divisor; return *this; }

		bool operator==(const Vector4& rhs) const					{ return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w); }
		bool equals(const Vector4& rhs, const float toleranceSquared = 0.0f) const;

		float LengthSquared() const									{ return (x * x) + (y * y) + (z * z) + (w * w); }
		float Length() const										{ return HM::sqrt(LengthSquared()); }

		void Normalize();
		Vector4 Normalized() const;

		float Dot(const Vector4& multiplier) const					{ return (x * multiplier.x) + (y * multiplier.y) + (z * multiplier.z) + (w * multiplier.w); }
	};
}

std::ostream& operator<<(std::ostream& out, const HM::Vector4& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
}