#pragma once

//--------------------------------------------------------------------------------
// Matrix4x4.h
//--------------------------------------------------------------------------------

#include "..\Vectors\Vector4.h"

namespace HM
{
	class Matrix4x4
	{
	public:
		Vector4 a, b, c, d;

	public:
		Matrix4x4()														: a(), b(), c(), d()   {}
		Matrix4x4(const Vector4 _a, const Vector4 _b, const Vector4 _c, const Vector4 _d) : a(_a), b(_b), c(_c), d(_d) {}

		Matrix4x4 operator-() const										{ return Matrix4x4(-a, -b, -c, -d); }

		Matrix4x4 operator+(const Matrix4x4& addend) const				{ return Matrix4x4(a + addend.a, b + addend.b, c + addend.c, d + addend.d); }
		Matrix4x4 operator-(const Matrix4x4& subtrahend) const			{ return Matrix4x4(a - subtrahend.a, b - subtrahend.b, c - subtrahend.c, d - subtrahend.d); }
		Matrix4x4 operator*(const float multiplier)	const				{ return Matrix4x4(a * multiplier, b * multiplier, c * multiplier, d * multiplier); }
		Vector4   operator*(const Vector4& multiplier);
		Matrix4x4 operator*(const Matrix4x4& multiplier);
		Matrix4x4 operator/(const float divisor) const					{ return Matrix4x4(a / divisor, b / divisor, c / divisor, d / divisor); }

		Matrix4x4 operator+=(const Matrix4x4& addend)					{ a += addend.a; b += addend.b; c += addend.c; d += addend.d; return *this; }
		Matrix4x4 operator-=(const Matrix4x4& subtrahend)				{ a -= subtrahend.a; b -= subtrahend.b; c -= subtrahend.c; d -= subtrahend.d; return *this; }
		Matrix4x4 operator*=(const float multiplier)					{ a *= multiplier; b *= multiplier; c *= multiplier; d *= multiplier; return *this; }
		Matrix4x4 operator*=(const Matrix4x4& multiplier);
		Matrix4x4 operator/=(const float divisor)						{ a /= divisor; b /= divisor; c /= divisor; d /= divisor; return *this; }

		bool operator==(const Matrix4x4& rhs) const						{ return (a == rhs.a) && (b == rhs.b) && (c == rhs.c) && (d == rhs.d); }
		bool equals(const Matrix4x4& rhs, const float tolerance)		{ return (a.equals(rhs.a, tolerance)) && (b.equals(rhs.b, tolerance)) && (c.equals(rhs.c, tolerance)) && (d.equals(rhs.d, tolerance)); }
	};
}

std::ostream& operator<<(std::ostream& out, const HM::Matrix4x4& mat)
{
	return out << "[" << mat.a << ", " << mat.b << ", " << mat.c << ", " << mat.d << "]";
}