#ifndef OUGI_MATRIX2X2_H
#define OUGI_MATRIX2X2_H
//--------------------------------------------------------------------------------
// Matrix2x2.h
//--------------------------------------------------------------------------------

#include "../include/Functions.h"
#include "../include/Vector2.h"

namespace Ougi
{
	class Matrix2x2
	{
	private:
		float matrix[2][2];

	public:
		Matrix2x2();
		Matrix2x2(const float _00, const float _01, 
				  const float _10, const float _11);
		Matrix2x2(const float _matrix[2][2]);
		Matrix2x2(const Matrix2x2& other);
		
		Matrix2x2& operator=(const Matrix2x2& other);

		float*       operator[](const unsigned int index)       { return matrix[index]; }
		float const* operator[](const unsigned int index) const { return matrix[index]; }

		Matrix2x2 operator-() const;

		Matrix2x2 operator+(const Matrix2x2& addend) const;
		Matrix2x2 operator-(const Matrix2x2& subtrahend) const;
		Matrix2x2 operator*(const float multiplier)	const;
		Vector2   operator*(const Vector2& multiplier) const;
		Matrix2x2 operator*(const Matrix2x2& multiplier) const;
		Matrix2x2 operator/(const float divisor) const;

		Matrix2x2 operator+=(const Matrix2x2& addend);
		Matrix2x2 operator-=(const Matrix2x2& subtrahend);
		Matrix2x2 operator*=(const float multiplier);
		Matrix2x2 operator*=(const Matrix2x2& multiplier);
		Matrix2x2 operator/=(const float divisor);

		float operator==(const Matrix2x2& rhs) const;
		float equals(const Matrix2x2& rhs, const float tolerance = 0.0f) const;
	};
}

inline std::ostream& operator<<(std::ostream& out, const Ougi::Matrix2x2& matrix)
{
	return out << "[(" << matrix[0][0] << ", " << matrix[0][1] << "), (" << matrix[1][0] << ", " << matrix[1][1] << ")]";
}

#endif