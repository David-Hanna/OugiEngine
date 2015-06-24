#include "Matrix4x4.h"

Ougi::Vector4 Ougi::Matrix4x4::operator*(const Ougi::Vector4& multiplier)
{
	return Vector4(
		(a.x * multiplier.x) + (b.x * multiplier.y) + (c.x * multiplier.z) + (d.x * multiplier.w),
		(a.y * multiplier.x) + (b.y * multiplier.y) + (c.y * multiplier.z) + (d.y * multiplier.w),
		(a.z * multiplier.x) + (b.z * multiplier.y) + (c.z * multiplier.z) + (d.z * multiplier.w),
		(a.w * multiplier.x) + (b.w * multiplier.y) + (c.w * multiplier.z) + (d.w * multiplier.w)
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator*(const Ougi::Matrix4x4& multiplier)
{
	return Matrix4x4(
		Vector4(
			(a.x * multiplier.a.x) + (a.y * multiplier.b.x) + (a.z * multiplier.c.x) + (a.w * multiplier.d.x),
			(a.x * multiplier.a.y) + (a.y * multiplier.b.y) + (a.z * multiplier.c.y) + (a.w * multiplier.d.y),
			(a.x * multiplier.a.z) + (a.y * multiplier.b.z) + (a.z * multiplier.c.z) + (a.w * multiplier.d.z),
			(a.x * multiplier.a.w) + (a.y * multiplier.b.w) + (a.z * multiplier.c.w) + (a.w * multiplier.d.w)
		),
		Vector4(
			(b.x * multiplier.a.x) + (b.y * multiplier.b.x) + (b.z * multiplier.c.x) + (b.w * multiplier.d.x),
			(b.x * multiplier.a.y) + (b.y * multiplier.b.y) + (b.z * multiplier.c.y) + (b.w * multiplier.d.y),
			(b.x * multiplier.a.z) + (b.y * multiplier.b.z) + (b.z * multiplier.c.z) + (b.w * multiplier.d.z),
			(b.x * multiplier.a.w) + (b.y * multiplier.b.w) + (b.z * multiplier.c.w) + (b.w * multiplier.d.w)
		),
		Vector4(
			(c.x * multiplier.a.x) + (c.y * multiplier.b.x) + (c.z * multiplier.c.x) + (c.w * multiplier.d.x),
			(c.x * multiplier.a.y) + (c.y * multiplier.b.y) + (c.z * multiplier.c.y) + (c.w * multiplier.d.y),
			(c.x * multiplier.a.z) + (c.y * multiplier.b.z) + (c.z * multiplier.c.z) + (c.w * multiplier.d.z),
			(c.x * multiplier.a.w) + (c.y * multiplier.b.w) + (c.z * multiplier.c.w) + (c.w * multiplier.d.w)
		),
		Vector4(
			(d.x * multiplier.a.x) + (d.y * multiplier.b.x) + (d.z * multiplier.c.x) + (d.w * multiplier.d.x),
			(d.x * multiplier.a.y) + (d.y * multiplier.b.y) + (d.z * multiplier.c.y) + (d.w * multiplier.d.y),
			(d.x * multiplier.a.z) + (d.y * multiplier.b.z) + (d.z * multiplier.c.z) + (d.w * multiplier.d.z),
			(d.x * multiplier.a.w) + (d.y * multiplier.b.w) + (d.z * multiplier.c.w) + (d.w * multiplier.d.w)
		)
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator*=(const Ougi::Matrix4x4& multiplier)
{
	a.x = (a.x * multiplier.a.x) + (a.y * multiplier.b.x) + (a.z * multiplier.c.x) + (a.w * multiplier.d.x);
	a.y = (a.x * multiplier.a.y) + (a.y * multiplier.b.y) + (a.z * multiplier.c.y) + (a.w * multiplier.d.y);
	a.z = (a.x * multiplier.a.z) + (a.y * multiplier.b.z) + (a.z * multiplier.c.z) + (a.w * multiplier.d.z);
	a.w = (a.x * multiplier.a.w) + (a.y * multiplier.b.w) + (a.z * multiplier.c.w) + (a.w * multiplier.d.w);

	b.x = (b.x * multiplier.a.x) + (b.y * multiplier.b.x) + (b.z * multiplier.c.x) + (b.w * multiplier.d.x);
	b.y = (b.x * multiplier.a.y) + (b.y * multiplier.b.y) + (b.z * multiplier.c.y) + (b.w * multiplier.d.y);
	b.z = (b.x * multiplier.a.z) + (b.y * multiplier.b.z) + (b.z * multiplier.c.z) + (b.w * multiplier.d.z);
	b.w = (b.x * multiplier.a.w) + (b.y * multiplier.b.w) + (b.z * multiplier.c.w) + (b.w * multiplier.d.w);

	c.x = (c.x * multiplier.a.x) + (c.y * multiplier.b.x) + (c.z * multiplier.c.x) + (c.w * multiplier.d.x);
	c.y = (c.x * multiplier.a.y) + (c.y * multiplier.b.y) + (c.z * multiplier.c.y) + (c.w * multiplier.d.y);
	c.z = (c.x * multiplier.a.z) + (c.y * multiplier.b.z) + (c.z * multiplier.c.z) + (c.w * multiplier.d.z);
	c.w = (c.x * multiplier.a.w) + (c.y * multiplier.b.w) + (c.z * multiplier.c.w) + (c.w * multiplier.d.w);

	d.x = (d.x * multiplier.a.x) + (d.y * multiplier.b.x) + (d.z * multiplier.c.x) + (d.w * multiplier.d.x);
	d.y = (d.x * multiplier.a.y) + (d.y * multiplier.b.y) + (d.z * multiplier.c.y) + (d.w * multiplier.d.y);
	d.z = (d.x * multiplier.a.z) + (d.y * multiplier.b.z) + (d.z * multiplier.c.z) + (d.w * multiplier.d.z);
	d.w = (d.x * multiplier.a.w) + (d.y * multiplier.b.w) + (d.z * multiplier.c.w) + (d.w * multiplier.d.w);

	return *this;
}