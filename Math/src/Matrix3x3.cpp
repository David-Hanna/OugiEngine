#include "Matrix3x3.h"

Ougi::Vector3 Ougi::Matrix3x3::operator*(const Ougi::Vector3& multiplier)
{
	return Vector3(
		(a.x * multiplier.x) + (b.x * multiplier.y) + (c.x * multiplier.z),
		(a.y * multiplier.x) + (b.y * multiplier.y) + (c.y * multiplier.z),
		(a.z * multiplier.x) + (b.z * multiplier.y) + (c.z * multiplier.z)
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator*(const Ougi::Matrix3x3& multiplier)
{
	return Matrix3x3(
		Vector3(
			(a.x * multiplier.a.x) + (a.y * multiplier.b.x) + (a.z * multiplier.c.x),
			(a.x * multiplier.a.y) + (a.y * multiplier.b.y) + (a.z * multiplier.c.y),
			(a.x * multiplier.a.z) + (a.y * multiplier.b.z) + (a.z * multiplier.c.z)
		),
		Vector3(
			(b.x * multiplier.a.x) + (b.y * multiplier.b.x) + (b.z * multiplier.c.x),
			(b.x * multiplier.a.y) + (b.y * multiplier.b.y) + (b.z * multiplier.c.y),
			(b.x * multiplier.a.z) + (b.y * multiplier.b.z) + (b.z * multiplier.c.z)
		),
		Vector3(
			(c.x * multiplier.a.x) + (c.y * multiplier.b.x) + (c.z * multiplier.c.x),
			(c.x * multiplier.a.y) + (c.y * multiplier.b.y) + (c.z * multiplier.c.y),
			(c.x * multiplier.a.z) + (c.y * multiplier.b.z) + (c.z * multiplier.c.z)
		)
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator*=(const Ougi::Matrix3x3& multiplier)
{
	a.x = (a.x * multiplier.a.x) + (a.y * multiplier.b.x) + (a.z * multiplier.c.x);
	a.y = (a.x * multiplier.a.y) + (a.y * multiplier.b.y) + (a.z * multiplier.c.y);
	a.z = (a.x * multiplier.a.z) + (a.y * multiplier.b.z) + (a.z * multiplier.c.z);

	b.x = (b.x * multiplier.a.x) + (b.y * multiplier.b.x) + (b.z * multiplier.c.x);
	b.y = (b.x * multiplier.a.y) + (b.y * multiplier.b.y) + (b.z * multiplier.c.y);
	b.z = (b.x * multiplier.a.z) + (b.y * multiplier.b.z) + (b.z * multiplier.c.z);

	c.x = (c.x * multiplier.a.x) + (c.y * multiplier.b.x) + (c.z * multiplier.c.x);
	c.y = (c.x * multiplier.a.y) + (c.y * multiplier.b.y) + (c.z * multiplier.c.y);
	c.z = (c.x * multiplier.a.z) + (c.y * multiplier.b.z) + (c.z * multiplier.c.z);

	return *this;
}