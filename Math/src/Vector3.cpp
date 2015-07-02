#include "../include/Vector3.h"

bool Ougi::Vector3::equals(const Ougi::Vector3& rhs, const float tolerance) const
{
	float diff = Ougi::abs(x - rhs.x);
	if (diff > tolerance)
		return false;

	diff = Ougi::abs(y - rhs.y);
	if (diff > tolerance)
		return false;

	diff = Ougi::abs(z - rhs.z);
	if (diff > tolerance)
		return false;

	return true;
}

Ougi::Vector3 Ougi::Vector3::Normalize()
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	return (*this);
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