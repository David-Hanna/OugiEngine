#include "../include/Vector3.h"

bool Ougi::Vector3::Equals(const Ougi::Vector3& rhs, const float tolerance) const
{
	return MagnitudeEquals(rhs, tolerance) && DirectionEquals(rhs, tolerance);
}

bool Ougi::Vector3::MagnitudeEquals(const Ougi::Vector3& rhs, const float tolerance) const
{
	return Ougi::Abs(LengthSquared() - rhs.LengthSquared()) < tolerance;
}

bool Ougi::Vector3::DirectionEquals(const Ougi::Vector3& rhs, const float tolerance) const
{
	// TODO
	return false;
}

Ougi::Vector3 Ougi::Vector3::Normalize()
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y) + (z * z));
	x *= inverseLength;
	y *= inverseLength;
	z *= inverseLength;
	return (*this);
}

Ougi::Vector3 Ougi::Vector3::Normalized() const
{
	float inverseLength = 1.0f / Ougi::Sqrt((x * x) + (y * y) + (z * z));
	return Vector3(x * inverseLength, y * inverseLength, z * inverseLength);
}

Ougi::Vector3 Ougi::Vector3::Cross(const Ougi::Vector3& multiplier) const
{
	return Vector3(y * multiplier.z - z * multiplier.y, z * multiplier.x - x * multiplier.z, x * multiplier.y - y * multiplier.x);
}