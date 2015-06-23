#include "Vector2.h"

bool HM::Vector2::equals(const HM::Vector2& rhs, const float toleranceSquared) const
{
	float diff = x - rhs.x;
	if (diff * diff > toleranceSquared)
		return false;

	diff = y - rhs.y;
	if (diff * diff > toleranceSquared)
		return false;

	return true;
}

void HM::Vector2::Normalize()
{
	float inverseLength = HM::invsqrt((x * x) + (y * y));
	x *= inverseLength;
	y *= inverseLength;
}

HM::Vector2 HM::Vector2::Normalized() const
{
	float inverseLength = HM::invsqrt((x * x) + (y * y));
	return Vector2(x * inverseLength, y * inverseLength);
}