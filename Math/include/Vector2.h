#ifndef OUGI_MATH_VECTOR2_H
#define OUGI_MATH_VECTOR2_H
//--------------------------------------------------------------------------------
// Vector2.h
//--------------------------------------------------------------------------------

#ifdef DEBUG
#include <ostream>
#endif

#include "Functions.h"

namespace Ougi
{
	class Vector2
	{
	public:
		float x, y, __pad_z, __pad_w;

	public:
		Vector2()													: x(0.0f), y(0.0f) {}
		Vector2(const float _x, const float _y)						: x(_x), y(_y) {}

		Vector2 operator-() const									{ return Vector2(-x, -y); }

		Vector2 operator+(const Vector2& addend) const				{ return Vector2(x + addend.x, y + addend.y); }
		Vector2 operator-(const Vector2& subtrahend) const			{ return Vector2(x - subtrahend.x, y - subtrahend.y); }
		Vector2 operator*(const float multiplier) const				{ return Vector2(x * multiplier, y * multiplier); }
		float   operator*(const Vector2& multiplier) const			{ return Dot(multiplier); }
		Vector2 operator/(const float divisor) const				{ return Vector2(x / divisor, y / divisor); }

		Vector2 operator+=(const Vector2& addend)					{ x += addend.x; y += addend.y; return *this; }
		Vector2 operator-=(const Vector2& subtrahend)				{ x -= subtrahend.x; y -= subtrahend.y; return *this; }
		Vector2 operator*=(const float multiplier)					{ x *= multiplier; y *= multiplier; return *this; }
		Vector2 operator/=(const float divisor)						{ x /= divisor; y /= divisor; return *this; }

		float operator==(const Vector2& rhs) const					{ return Equals(rhs, 0.0f) ? 0.0f : -1.0f; }
		float Equals(const Vector2& rhs) const 						{ return Equals(rhs, 0.0f) ? 0.0f : -1.0f; }
		bool Equals(const Vector2& rhs, const float tolerance) const;
		bool MagnitudeEquals(const Vector2& rhs, const float tolerance = 0.0f) const;
		bool DirectionEquals(const Vector2& rhs, const float tolerance = 0.0f) const;

		float LengthSquared() const									{ return (x * x) + (y * y); }
		float Length() const										{ return Ougi::sqrt(LengthSquared()); }

		Vector2 Normalize();
		Vector2 Normalized() const;

		float Dot(const Vector2& multiplier) const					{ return (x * multiplier.x) + (y * multiplier.y); }
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::Vector2& vec)
{
	return out << "(" << vec.x << ", " << vec.y << ")";
}
#endif

#endif