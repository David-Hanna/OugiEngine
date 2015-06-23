#include "Vector3.h"

bool HM::Vector3::equals(const HM::Vector3& rhs, const float toleranceSquared) const
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

void HM::Vector3::Normalize()
{
	float inverseLength = HM::invsqrt((x * x) + (y * y) + (z * z));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
}

HM::Vector3 HM::Vector3::Normalized() const
{
	float inverseLength = HM::invsqrt((x * x) + (y * y) + (z * z));
	return Vector3(x * inverseLength, y * inverseLength, z * inverseLength);
}

HM::Vector3 HM::Vector3::Cross(const HM::Vector3& multiplier) const
{
	return Vector3(y * multiplier.z - z * multiplier.y, z * multiplier.x - x * multiplier.z, x * multiplier.y - y * multiplier.x);
}