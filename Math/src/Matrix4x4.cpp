#include "../include/Matrix4x4.h"

Ougi::Matrix4x4::Matrix4x4()
{
	matrix[0][0] = 0.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 0.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 0.0f; matrix[2][3] = 0.0f;
	matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 0.0f;
}

Ougi::Matrix4x4::Matrix4x4(const float _00, const float _01, const float _02, const float _03,
				  		   const float _10, const float _11, const float _12, const float _13,
				  		   const float _20, const float _21, const float _22, const float _23,
				  		   const float _30, const float _31, const float _32, const float _33)
{
	matrix[0][0] = _00; matrix[0][1] = _01; matrix[0][2] = _02; matrix[0][3] = _03;
	matrix[1][0] = _10; matrix[1][1] = _11; matrix[1][2] = _12; matrix[1][3] = _13;
	matrix[2][0] = _20; matrix[2][1] = _21; matrix[2][2] = _22; matrix[2][3] = _23;
	matrix[3][0] = _30; matrix[3][1] = _31; matrix[3][2] = _32; matrix[3][3] = _33;
}

Ougi::Matrix4x4::Matrix4x4(const float _matrix[4][4])
{
	matrix[0][0] = _matrix[0][0]; matrix[0][1] = _matrix[0][1]; matrix[0][2] = _matrix[0][2]; matrix[0][3] = _matrix[0][3];
	matrix[1][0] = _matrix[1][0]; matrix[1][1] = _matrix[1][1]; matrix[1][2] = _matrix[1][2]; matrix[1][3] = _matrix[1][3];
	matrix[2][0] = _matrix[2][0]; matrix[2][1] = _matrix[2][1]; matrix[2][2] = _matrix[2][2]; matrix[2][3] = _matrix[2][3];
	matrix[3][0] = _matrix[3][0]; matrix[3][1] = _matrix[3][1]; matrix[3][2] = _matrix[3][2]; matrix[3][3] = _matrix[3][3];
}

Ougi::Matrix4x4::Matrix4x4(const Matrix4x4& other)
{
	matrix[0][0] = other[0][0]; matrix[0][1] = other[0][1]; matrix[0][2] = other[0][2]; matrix[0][3] = other[0][3];
	matrix[1][0] = other[1][0]; matrix[1][1] = other[1][1]; matrix[1][2] = other[1][2]; matrix[1][3] = other[1][3];
	matrix[2][0] = other[2][0]; matrix[2][1] = other[2][1]; matrix[2][2] = other[2][2]; matrix[2][3] = other[2][3];
	matrix[3][0] = other[3][0]; matrix[3][1] = other[3][1]; matrix[3][2] = other[3][2]; matrix[3][3] = other[3][3];
}

Ougi::Matrix4x4& Ougi::Matrix4x4::operator=(const Matrix4x4& other)
{
	matrix[0][0] = other[0][0]; matrix[0][1] = other[0][1]; matrix[0][2] = other[0][2]; matrix[0][3] = other[0][3];
	matrix[1][0] = other[1][0]; matrix[1][1] = other[1][1]; matrix[1][2] = other[1][2]; matrix[1][3] = other[1][3];
	matrix[2][0] = other[2][0]; matrix[2][1] = other[2][1]; matrix[2][2] = other[2][2]; matrix[2][3] = other[2][3];
	matrix[3][0] = other[3][0]; matrix[3][1] = other[3][1]; matrix[3][2] = other[3][2]; matrix[3][3] = other[3][3];
	return (*this);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator-() const
{
	return Matrix4x4(
		-matrix[0][0], -matrix[0][1], -matrix[0][2], -matrix[0][3],
		-matrix[1][0], -matrix[1][1], -matrix[1][2], -matrix[1][3],
		-matrix[2][0], -matrix[2][1], -matrix[2][2], -matrix[2][3],
		-matrix[3][0], -matrix[3][1], -matrix[3][2], -matrix[3][3]
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator+(const Matrix4x4& addend) const
{
	return Matrix4x4(
		matrix[0][0] + addend[0][0], matrix[0][1] + addend[0][1], matrix[0][2] + addend[0][2], matrix[0][3] + addend[0][3],
		matrix[1][0] + addend[1][0], matrix[1][1] + addend[1][1], matrix[1][2] + addend[1][2], matrix[1][3] + addend[1][3],
		matrix[2][0] + addend[2][0], matrix[2][1] + addend[2][1], matrix[2][2] + addend[2][2], matrix[2][3] + addend[2][3],
		matrix[3][0] + addend[3][0], matrix[3][1] + addend[3][1], matrix[3][2] + addend[3][2], matrix[3][3] + addend[3][3]
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator-(const Matrix4x4& subtrahend) const
{
	return Matrix4x4(
		matrix[0][0] - subtrahend[0][0], matrix[0][1] - subtrahend[0][1], matrix[0][2] - subtrahend[0][2], matrix[0][3] - subtrahend[0][3],
		matrix[1][0] - subtrahend[1][0], matrix[1][1] - subtrahend[1][1], matrix[1][2] - subtrahend[1][2], matrix[1][3] - subtrahend[1][3],
		matrix[2][0] - subtrahend[2][0], matrix[2][1] - subtrahend[2][1], matrix[2][2] - subtrahend[2][2], matrix[2][3] - subtrahend[2][3],
		matrix[3][0] - subtrahend[3][0], matrix[3][1] - subtrahend[3][1], matrix[3][2] - subtrahend[3][2], matrix[3][3] - subtrahend[3][3]
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator*(const float multiplier) const
{
	return Matrix4x4(
		matrix[0][0] * multiplier, matrix[0][1] * multiplier, matrix[0][2] * multiplier, matrix[0][3] * multiplier,
		matrix[1][0] * multiplier, matrix[1][1] * multiplier, matrix[1][2] * multiplier, matrix[1][3] * multiplier,
		matrix[2][0] * multiplier, matrix[2][1] * multiplier, matrix[2][2] * multiplier, matrix[2][3] * multiplier,
		matrix[3][0] * multiplier, matrix[3][1] * multiplier, matrix[3][2] * multiplier, matrix[3][3] * multiplier
	);
}

Ougi::Vector4 Ougi::Matrix4x4::operator*(const Ougi::Vector4& multiplier) const
{
	return Vector4(
		(matrix[0][0] * multiplier.x) + (matrix[1][0] * multiplier.y) + (matrix[2][0] * multiplier.z) + (matrix[3][0] * multiplier.w),
		(matrix[0][1] * multiplier.x) + (matrix[1][1] * multiplier.y) + (matrix[2][1] * multiplier.z) + (matrix[3][1] * multiplier.w),
		(matrix[0][2] * multiplier.x) + (matrix[1][2] * multiplier.y) + (matrix[2][2] * multiplier.z) + (matrix[3][2] * multiplier.w),
		(matrix[0][3] * multiplier.x) + (matrix[1][3] * multiplier.y) + (matrix[2][3] * multiplier.z) + (matrix[3][3] * multiplier.w)
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator*(const Ougi::Matrix4x4& multiplier) const
{
	return Matrix4x4(
		(matrix[0][0] * multiplier[0][0]) + (matrix[0][1] * multiplier[1][0]) + (matrix[0][2] * multiplier[2][0]) + (matrix[0][3] * multiplier[3][0]),
		(matrix[0][0] * multiplier[0][1]) + (matrix[0][1] * multiplier[1][1]) + (matrix[0][2] * multiplier[2][1]) + (matrix[0][3] * multiplier[3][1]),
		(matrix[0][0] * multiplier[0][2]) + (matrix[0][1] * multiplier[1][2]) + (matrix[0][2] * multiplier[2][2]) + (matrix[0][3] * multiplier[3][2]),
		(matrix[0][0] * multiplier[0][3]) + (matrix[0][1] * multiplier[1][3]) + (matrix[0][2] * multiplier[2][3]) + (matrix[0][3] * multiplier[3][3]),
		
		(matrix[1][0] * multiplier[0][0]) + (matrix[1][1] * multiplier[1][0]) + (matrix[1][2] * multiplier[2][0]) + (matrix[1][3] * multiplier[3][0]),
		(matrix[1][0] * multiplier[0][1]) + (matrix[1][1] * multiplier[1][1]) + (matrix[1][2] * multiplier[2][1]) + (matrix[1][3] * multiplier[3][1]),
		(matrix[1][0] * multiplier[0][2]) + (matrix[1][1] * multiplier[1][2]) + (matrix[1][2] * multiplier[2][2]) + (matrix[1][3] * multiplier[3][2]),
		(matrix[1][0] * multiplier[0][3]) + (matrix[1][1] * multiplier[1][3]) + (matrix[1][2] * multiplier[2][3]) + (matrix[1][3] * multiplier[3][3]),
		
		(matrix[2][0] * multiplier[0][0]) + (matrix[2][1] * multiplier[1][0]) + (matrix[2][2] * multiplier[2][0]) + (matrix[2][3] * multiplier[3][0]),
		(matrix[2][0] * multiplier[0][1]) + (matrix[2][1] * multiplier[1][1]) + (matrix[2][2] * multiplier[2][1]) + (matrix[2][3] * multiplier[3][1]),
		(matrix[2][0] * multiplier[0][2]) + (matrix[2][1] * multiplier[1][2]) + (matrix[2][2] * multiplier[2][2]) + (matrix[2][3] * multiplier[3][2]),
		(matrix[2][0] * multiplier[0][3]) + (matrix[2][1] * multiplier[1][3]) + (matrix[2][2] * multiplier[2][3]) + (matrix[2][3] * multiplier[3][3]),
		
		(matrix[3][0] * multiplier[0][0]) + (matrix[3][1] * multiplier[1][0]) + (matrix[3][2] * multiplier[2][0]) + (matrix[3][3] * multiplier[3][0]),
		(matrix[3][0] * multiplier[0][1]) + (matrix[3][1] * multiplier[1][1]) + (matrix[3][2] * multiplier[2][1]) + (matrix[3][3] * multiplier[3][1]),
		(matrix[3][0] * multiplier[0][2]) + (matrix[3][1] * multiplier[1][2]) + (matrix[3][2] * multiplier[2][2]) + (matrix[3][3] * multiplier[3][2]),
		(matrix[3][0] * multiplier[0][3]) + (matrix[3][1] * multiplier[1][3]) + (matrix[3][2] * multiplier[2][3]) + (matrix[3][3] * multiplier[3][3])
	);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator/(const float divisor) const
{
	return (*this) * (1.0f / divisor);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator+=(const Matrix4x4& addend)
{
	(*this) = (*this) + addend;
	return (*this);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator-=(const Matrix4x4& subtrahend)
{
	(*this) = (*this) - subtrahend;
	return (*this);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator*=(const float multiplier)
{
	(*this) = (*this) * multiplier;
	return (*this);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator*=(const Matrix4x4& multiplier)
{
	(*this) = (*this) * multiplier;
	return (*this);
}

Ougi::Matrix4x4 Ougi::Matrix4x4::operator/=(const float divisor)
{
	(*this) = (*this) / divisor;
	return (*this);
}

bool Ougi::Matrix4x4::operator==(const Matrix4x4& rhs) const
{
	return Equals(rhs, 0.0f);
}

bool Ougi::Matrix4x4::Equals(const Matrix4x4& rhs, const float tolerance) const
{
	bool equal = true; int i = 0; int j = 0;
	while (equal && i < 4)
	{
		while (equal && j < 4)
		{
			if (Ougi::abs(matrix[i][j] - rhs[i][j]) > tolerance)
				equal = false;
			j++;
		}
		i++;
	}
	return equal;
}