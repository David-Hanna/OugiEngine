#include "Vector4.h"

bool Ougi::Vector4::equals(const Ougi::Vector4& rhs, const float toleranceSquared) const
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

void Ougi::Vector4::Normalize()
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z) + (w * w));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	w *= inverseLength;
}

Ougi::Vector4 Ougi::Vector4::Normalized() const
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z) + (w * w));
	return Vector4(x * inverseLength, y * inverseLength, z * inverseLength, w * inverseLength);
}