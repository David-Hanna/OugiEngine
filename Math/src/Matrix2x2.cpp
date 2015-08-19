#include "../include/Matrix2x2.h"

Ougi::Matrix2x2::Matrix2x2()
{
	matrix[0][0] = 0.0f; matrix[0][1] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 0.0f;
}

Ougi::Matrix2x2::Matrix2x2(const float _00, const float _01, const float _10, const float _11)
{
	matrix[0][0] = _00; matrix[0][1] = _01;
	matrix[1][0] = _10; matrix[1][1] = _11;
}

Ougi::Matrix2x2::Matrix2x2(const float _matrix[2][2])
{
	matrix[0][0] = _matrix[0][0]; matrix[0][1] = _matrix[0][1];
	matrix[1][0] = _matrix[1][0]; matrix[1][1] = _matrix[1][1];
}

Ougi::Matrix2x2::Matrix2x2(const Ougi::Matrix2x2& other)
{
	matrix[0][0] = other[0][0]; matrix[0][1] = other[0][1];
	matrix[1][0] = other[1][0]; matrix[1][1] = other[1][1];
}

Ougi::Matrix2x2& Ougi::Matrix2x2::operator=(const Ougi::Matrix2x2& other)
{
	matrix[0][0] = other[0][0]; matrix[0][1] = other[0][1];
	matrix[1][0] = other[1][0]; matrix[1][1] = other[1][1];
	return *this;
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator-() const
{
	return Ougi::Matrix2x2(
		-matrix[0][0], -matrix[0][1],
		-matrix[1][0], -matrix[1][1]
	);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator+(const Ougi::Matrix2x2& addend) const
{
	return Ougi::Matrix2x2(
		matrix[0][0] + addend[0][0], matrix[0][1] + addend[0][1],
		matrix[1][0] + addend[1][0], matrix[1][1] + addend[1][1]
	);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator-(const Ougi::Matrix2x2& subtrahend) const
{
	return Ougi::Matrix2x2(
		matrix[0][0] - subtrahend[0][0], matrix[0][1] - subtrahend[0][1],
		matrix[1][0] - subtrahend[1][0], matrix[1][1] - subtrahend[1][1]
	);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator*(const float multiplier) const
{
	return Ougi::Matrix2x2(
		matrix[0][0] * multiplier, matrix[0][1] * multiplier,
		matrix[1][0] * multiplier, matrix[1][1] * multiplier
	);
}

Ougi::Vector2 Ougi::Matrix2x2::operator*(const Ougi::Vector2& multiplier) const
{
	return Vector2(
		(matrix[0][0] * multiplier.x) + (matrix[1][0] * multiplier.y),
		(matrix[0][1] * multiplier.x) + (matrix[1][1] * multiplier.y)
	);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator*(const Ougi::Matrix2x2& multiplier) const
{
	return Matrix2x2(
		(matrix[0][0] * multiplier[0][0]) + (matrix[0][1] * multiplier[1][0]),
		(matrix[0][0] * multiplier[0][1]) + (matrix[0][1] * multiplier[1][1]),
		
		(matrix[1][0] * multiplier[0][0]) + (matrix[1][1] * multiplier[1][0]),
		(matrix[1][0] * multiplier[0][1]) + (matrix[1][1] * multiplier[1][1])
	);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator/(const float divisor) const
{
	return (*this) * (1.0f / divisor);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator+=(const Matrix2x2& addend)
{
	(*this) = (*this) + addend;
	return (*this);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator-=(const Matrix2x2& subtrahend)
{
	(*this) = (*this) - subtrahend;
	return (*this);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator*=(const float multiplier)
{
	(*this) = (*this) * multiplier;
	return (*this);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator*=(const Ougi::Matrix2x2& multiplier)
{
	(*this) = (*this) * multiplier;
	return (*this);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator/=(const float divisor)
{
	(*this) = (*this) / divisor;
	return (*this);
}

bool Ougi::Matrix2x2::operator==(const Matrix2x2& rhs) const
{
	return Equals(rhs, 0.0f);
}

bool Ougi::Matrix2x2::Equals(const Matrix2x2& rhs, const float tolerance) const
{
	bool equal = true; int i = 0; int j = 0;
	while (equal && i < 2)
	{
		while (equal && j < 2)
		{
			if (Ougi::Abs(matrix[i][j] - rhs[i][j]) > tolerance)
				equal = false;
			j++;
		}
		i++;
	}
	return equal;
}