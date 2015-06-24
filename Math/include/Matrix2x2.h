#pragma once

//--------------------------------------------------------------------------------
// Matrix2x2.h
//--------------------------------------------------------------------------------

#include "Vector2.h"

namespace HM
{
	class Matrix2x2
	{
	private:
		float matrix[2][2];

	public:
		Matrix2x2();
		Matrix2x2(const float _00, const float _01, const float _10, const float _11);
		Matrix2x2(const float _matrix[2][2]);
		Matrix2x2(const Vector2& a, const Vector2& b);

		Matrix2x2(const Matrix2x2& other);

		Matrix2x2& operator=(const Matrix2x2& other);

		float* operator[](const unsigned int index) { return matrix[index]; }

		Matrix2x2 operator-() const;

		Matrix2x2 operator+(const Matrix2x2& addend) const;
		Matrix2x2 operator-(const Matrix2x2& subtrahend) const;
		Matrix2x2 operator*(const float multiplier)	const;
		Vector2   operator*(const Vector2& multiplier);
		Matrix2x2 operator*(const Matrix2x2& multiplier);
		Matrix2x2 operator/(const float divisor) const;

		Matrix2x2 operator+=(const Matrix2x2& addend);
		Matrix2x2 operator-=(const Matrix2x2& subtrahend);
		Matrix2x2 operator*=(const float multiplier);
		Matrix2x2 operator*=(const Matrix2x2& multiplier);
		Matrix2x2 operator/=(const float divisor);

		bool operator==(const Matrix2x2& rhs) const;
		bool equals(const Matrix2x2& rhs, const float tolerance);
	};
}

std::ostream& operator<<(std::ostream& out, const Ougi::Matrix2x2& mat)
{
	return out << "[(" << mat[0][0] << ", " << mat[0][1] << "), (" << mat[1][0] << ", " << mat[1][1] << ")]";
}