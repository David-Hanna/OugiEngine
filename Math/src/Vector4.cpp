#include "../include/Vector4.h"

bool Ougi::Vector4::Equals(const Ougi::Vector4& rhs, const float tolerance) const
{
	return MagnitudeEquals(rhs, tolerance) && DirectionEquals(rhs, tolerance);
}

bool Ougi::Vector4::MagnitudeEquals(const Ougi::Vector4& rhs, const float tolerance) const
{
	return Ougi::abs(LengthSquared() - rhs.LengthSquared()) < tolerance;
}

bool Ougi::Vector4::DirectionEquals(const Ougi::Vector4& rhs, const float tolerance) const
{
	
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