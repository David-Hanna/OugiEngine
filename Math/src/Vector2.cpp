#include "../include/Vector2.h"

bool Ougi::Vector2::Equals(const Ougi::Vector2& rhs, const float tolerance) const
{
	return MagnitudeEquals(rhs, tolerance) && DirectionEquals(rhs, tolerance);
}

bool Ougi::Vector2::MagnitudeEquals(const Ougi::Vector2& rhs, const float tolerance) const
{
	return Ougi::Abs(LengthSquared() - rhs.LengthSquared()) < tolerance;
}

bool Ougi::Vector2::DirectionEquals(const Ougi::Vector2& rhs, const float tolerance) const
{
	// TODO
	return false;
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