#include "../include/Vector2.h"

bool Ougi::Vector2::Equals(const Ougi::Vector2& rhs, const float tolerance) const
{
	return MagnitudeEquals(rhs, tolerance) && DirectionEquals(rhs, tolerance);
}

bool Ougi::Vector2::MagnitudeEquals(const Ougi::Vector2& rhs, const float tolerance) const
{
	return Ougi::abs(LengthSquared() - rhs.LengthSquared()) < tolerance;
}

bool Ougi::Vector2::DirectionEquals(const Ougi::Vector2& rhs, const float tolerance) const
{
	
}

Ougi::Vector2 Ougi::Vector2::Normalize()
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y));
	x *= inverseLength;
	y *= inverseLength;
	return (*this);
}

Ougi::Vector2 Ougi::Vector2::Normalized() const
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y));
	return Vector2(x * inverseLength, y * inverseLength);
}