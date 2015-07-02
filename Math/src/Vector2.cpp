#include "../include/Vector2.h"

bool Ougi::Vector2::equals(const Ougi::Vector2& rhs, const float tolerance) const
{
	float diff = Ougi::abs(x - rhs.x);
	if (diff > tolerance)
		return false;

	diff = Ougi::abs(y - rhs.y);
	if (diff > tolerance)
		return false;

	return true;
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