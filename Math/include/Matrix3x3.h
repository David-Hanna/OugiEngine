#ifndef OUGI_MATRIX3X3_H
#define OUGI_MATRIX3X3_H
//--------------------------------------------------------------------------------
// Matrix3x3.h
//--------------------------------------------------------------------------------

#include "../include/Functions.h"
#include "../include/Vector3.h"

namespace Ougi
{
	class Matrix3x3
	{
	public:
		float matrix[3][3];

	public:
		Matrix3x3();
		Matrix3x3(const float _00, const float _01, const float _02,
				  const float _10, const float _11, const float _12,
				  const float _20, const float _21, const float _22);
		Matrix3x3(const float _matrix[3][3]);
		Matrix3x3(const Matrix3x3& other);
		
		Matrix3x3& operator=(const Matrix3x3& other);

		float*       operator[](const unsigned int index)       { return matrix[index]; }
		float const* operator[](const unsigned int index) const { return matrix[index]; }

		Matrix3x3 operator-() const;

		Matrix3x3 operator+(const Matrix3x3& addend) const;
		Matrix3x3 operator-(const Matrix3x3& subtrahend) const;
		Matrix3x3 operator*(const float multiplier)	const;
		Vector3   operator*(const Vector3& multiplier) const;
		Matrix3x3 operator*(const Matrix3x3& multiplier) const;
		Matrix3x3 operator/(const float divisor) const;

		Matrix3x3 operator+=(const Matrix3x3& addend);
		Matrix3x3 operator-=(const Matrix3x3& subtrahend);
		Matrix3x3 operator*=(const float multiplier);
		Matrix3x3 operator*=(const Matrix3x3& multiplier);
		Matrix3x3 operator/=(const float divisor);

		float operator==(const Matrix3x3& rhs) const;
		float equals(const Matrix3x3& rhs, const float tolerance = 0.0f) const;
	};
}

inline std::ostream& operator<<(std::ostream& out, const Ougi::Matrix3x3& matrix)
{
	return out << "[(" << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2] << "), (" << matrix[1][0] << ", " << matrix[1][1] << ", " << matrix[1][2] << "), (" << matrix[2][0] << ", " << matrix[2][1] << ", " << matrix[2][2] << ")]";
}

#endif