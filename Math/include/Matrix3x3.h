#pragma once

//--------------------------------------------------------------------------------
// Matrix3x3.h
//--------------------------------------------------------------------------------

#include "..\Vectors\Vector3.h"

namespace HM
{
	class Matrix3x3
	{
	public:
		Vector3 a, b, c;

	public:
		Matrix3x3()														: a(), b(), c()   {}
		Matrix3x3(const Vector3 _a, const Vector3 _b, const Vector3 _c) : a(_a), b(_b), c(_c) {}

		Matrix3x3 operator-() const										{ return Matrix3x3(-a, -b, -c); }

		Matrix3x3 operator+(const Matrix3x3& addend) const				{ return Matrix3x3(a + addend.a, b + addend.b, c + addend.c); }
		Matrix3x3 operator-(const Matrix3x3& subtrahend) const			{ return Matrix3x3(a - subtrahend.a, b - subtrahend.b, c - subtrahend.c); }
		Matrix3x3 operator*(const float multiplier)	const				{ return Matrix3x3(a * multiplier, b * multiplier, c * multiplier); }
		Vector3   operator*(const Vector3& multiplier);
		Matrix3x3 operator*(const Matrix3x3& multiplier);
		Matrix3x3 operator/(const float divisor) const					{ return Matrix3x3(a / divisor, b / divisor, c / divisor); }

		Matrix3x3 operator+=(const Matrix3x3& addend)					{ a += addend.a; b += addend.b; c += addend.c; return *this; }
		Matrix3x3 operator-=(const Matrix3x3& subtrahend)				{ a -= subtrahend.a; b -= subtrahend.b; c -= subtrahend.c; return *this; }
		Matrix3x3 operator*=(const float multiplier)					{ a *= multiplier; b *= multiplier; c *= multiplier; return *this; }
		Matrix3x3 operator*=(const Matrix3x3& multiplier);
		Matrix3x3 operator/=(const float divisor)						{ a /= divisor; b /= divisor; c /= divisor; return *this; }

		bool operator==(const Matrix3x3& rhs) const						{ return (a == rhs.a) && (b == rhs.b) && (c == rhs.c); }
		bool equals(const Matrix3x3& rhs, const float tolerance)		{ return (a.equals(rhs.a, tolerance)) && (b.equals(rhs.b, tolerance)) && (c.equals(rhs.c, tolerance)); }
	};
}

std::ostream& operator<<(std::ostream& out, const Ougi::Matrix3x3& mat)
{
	return out << "[" << mat.a << ", " << mat.b << ", " << mat.c << "]";
}