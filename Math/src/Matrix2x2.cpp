#include "Matrix2x2.h"

Ougi::Matrix2x2::Matrix2x2()
{
	matrix[0][0] = 0; matrix[0][1] = 0;
	matrix[1][0] = 0; matrix[1][1] = 0;
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

Ougi::Matrix2x2::Matrix2x2(const Ougi::Vector2& a, const Ougi::Vector2& b)
{
	matrix[0][0] = a.x; matrix[0][1] = a.y;
	matrix[1][0] = b.x; matrix[1][1] = b.y;
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

Ougi::Vector2 Ougi::Matrix2x2::operator*(const Ougi::Vector2& multiplier)
{
	return Vector2(
		(matrix[0][0] * multiplier.x) + (matrix[1][0] * multiplier.y),
		(matrix[0][1] * multiplier.x) + (matrix[1][1] * multiplier.y)
	);
}

Ougi::Matrix2x2 Ougi::Matrix2x2::operator*(const Ougi::Matrix2x2& multiplier)
{
	return Matrix2x2(
		Vector2(
			(a.x * multiplier.a.x) + (a.y * multiplier.b.x),
			(a.x * multiplier.a.y) + (a.y * multiplier.b.y)
		),
		Vector2(
			(b.x * multiplier.a.x) + (b.y * multiplier.b.x),
			(b.x * multiplier.a.y) + (b.y * multiplier.b.y)
		)
	);
}

Matrix2x2 operator/(const float divisor) const;

Matrix2x2 operator+=(const Matrix2x2& addend);
Matrix2x2 operator-=(const Matrix2x2& subtrahend);
Matrix2x2 operator*=(const float multiplier);

Ougi::Matrix2x2 Ougi::Matrix2x2::operator*=(const Ougi::Matrix2x2& multiplier)
{
	a.x = (a.x * multiplier.a.x) + (a.y * multiplier.b.x);
	a.y = (a.x * multiplier.a.y) + (a.y * multiplier.b.y);

	b.x = (b.x * multiplier.a.x) + (b.y * multiplier.b.x);
	b.y = (b.x * multiplier.a.y) + (b.y * multiplier.b.y);

	return *this;
}

Matrix2x2 operator/=(const float divisor);

bool operator==(const Matrix2x2& rhs) const;
bool equals(const Matrix2x2& rhs, const float tolerance);