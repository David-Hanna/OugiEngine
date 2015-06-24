#include "Vector3.h"

bool Ougi::Vector3::equals(const Ougi::Vector3& rhs, const float toleranceSquared) const
{
	float diff = x - rhs.x;
	if (diff * diff > toleranceSquared)
		return false;

	diff = y - rhs.y;
	if (diff * diff > toleranceSquared)
		return false;

	diff = z - rhs.z;
	if (diff * diff > toleranceSquared)
		return false;

	return true;
}

void Ougi::Vector3::Normalize()
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
}

Ougi::Vector3 Ougi::Vector3::Normalized() const
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z));
	return Vector3(x * inverseLength, y * inverseLength, z * inverseLength);
}

Ougi::Vector3 Ougi::Vector3::Cross(const Ougi::Vector3& multiplier) const
{
	return Vector3(y * multiplier.z - z * multiplier.y, z * multiplier.x - x * multiplier.z, x * multiplier.y - y * multiplier.x);
}