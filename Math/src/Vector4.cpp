#include "../include/Vector4.h"

bool Ougi::Vector4::equals(const Ougi::Vector4& rhs, const float tolerance) const
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

	diff = Ougi::abs(w - rhs.w);
	if (diff > tolerance)
		return false;

	return true;
}

Ougi::Vector4 Ougi::Vector4::Normalize()
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z) + (w * w));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	w *= inverseLength;
	return (*this);
}

Ougi::Vector4 Ougi::Vector4::Normalized() const
{
	float inverseLength = Ougi::invsqrt((x * x) + (y * y) + (z * z) + (w * w));
	return Vector4(x * inverseLength, y * inverseLength, z * inverseLength, w * inverseLength);
}