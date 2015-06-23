#include "Vector4.h"

bool HM::Vector4::equals(const HM::Vector4& rhs, const float toleranceSquared) const
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

	diff = w - rhs.w;
	if (diff * diff > toleranceSquared)
		return false;

	return true;
}

void HM::Vector4::Normalize()
{
	float inverseLength = HM::invsqrt((x * x) + (y * y) + (z * z) + (w * w));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	w *= inverseLength;
}

HM::Vector4 HM::Vector4::Normalized() const
{
	float inverseLength = HM::invsqrt((x * x) + (y * y) + (z * z) + (w * w));
	return Vector4(x * inverseLength, y * inverseLength, z * inverseLength, w * inverseLength);
}