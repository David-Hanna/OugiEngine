#include "Vector2.h"

bool Ougi::Vector2::equals(const Ougi::Vector2& rhs, const float toleranceSquared) const
{
	float diff = x - rhs.x;
	if (diff * diff > toleranceSquared)
		return false;

	diff = y - rhs.y;
	if (diff * diff > toleranceSquared)
		return false;

	return true;
}

void Ougi::Vector2::Normalize()
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y));
	x *= inverseLength;
	y *= inverseLength;
}

Ougi::Vector2 Ougi::Vector2::Normalized() const
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y));
	return Vector2(x * inverseLength, y * inverseLength);
}