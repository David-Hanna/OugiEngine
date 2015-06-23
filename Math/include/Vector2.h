#pragma once

//--------------------------------------------------------------------------------
// Vector2.h
//--------------------------------------------------------------------------------

#include <ostream>

#include "..\Functions\FundamentalFunctions.h"

namespace HM
{
	class Vector2
	{
	public:
		float x, y;

	public:
		Vector2()													: x(0.0f), y(0.0f) {}
		Vector2(const float _x, const float _y)						: x(_x), y(_y) {}

		Vector2 operator-() const									{ return Vector2(-x, -y); }

		Vector2 operator+(const Vector2& addend) const				{ return Vector2(x + addend.x, y + addend.y); }
		Vector2 operator-(const Vector2& subtrahend) const			{ return Vector2(x - subtrahend.x, y - subtrahend.y); }
		Vector2 operator*(const float multiplier) const				{ return Vector2(x * multiplier, y * multiplier); }
		Vector2 operator/(const float divisor) const				{ return Vector2(x / divisor, y / divisor); }

		Vector2 operator+=(const Vector2& addend)					{ x += addend.x; y += addend.y; return *this; }
		Vector2 operator-=(const Vector2& subtrahend)				{ x -= subtrahend.x; y -= subtrahend.y; return *this; }
		Vector2 operator*=(const float multiplier)					{ x *= multiplier; y *= multiplier; return *this; }
		Vector2 operator/=(const float divisor)						{ x /= divisor; y /= divisor; return *this; }

		bool operator==(const Vector2& rhs) const					{ return (x == rhs.x) && (y == rhs.y); }
		bool equals(const Vector2& rhs, const float toleranceSquared = 0.0f) const;

		float LengthSquared() const									{ return (x * x) + (y * y); }
		float Length() const										{ return HM::sqrt(LengthSquared()); }

		void Normalize();
		Vector2 Normalized() const;

		float Dot(const Vector2& multiplier) const					{ return (x * multiplier.x) + (y * multiplier.y); }
	};
}

std::ostream& operator<<(std::ostream& out, const HM::Vector2& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ")";
}