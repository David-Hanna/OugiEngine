//--------------------------------------------------------------------------------
// Matrix3x3.cpp
// Author: David Hanna
// Copyright (C) 20xx David Hanna, Inc.
//
// This file is part of Ougi Engine.
//
// Ougi Engine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Ougi Engine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Ougi Engine.  If not, see <http://www.gnu.org/licenses/>.
//--------------------------------------------------------------------------------

#include "../include/Matrix3x3.h"

Ougi::Matrix3x3::Matrix3x3()
{
	matrix[0][0] = 0.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 0.0f; matrix[1][2] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 0.0f;
}

Ougi::Matrix3x3::Matrix3x3(const float _00, const float _01, const float _02,
				  		   const float _10, const float _11, const float _12,
				  		   const float _20, const float _21, const float _22)
{
 	matrix[0][0] = _00; matrix[0][1] = _01; matrix[0][2] = _02;
	matrix[1][0] = _10; matrix[1][1] = _11; matrix[1][2] = _12;
	matrix[2][0] = _20; matrix[2][1] = _21; matrix[2][2] = _22;
}

Ougi::Matrix3x3::Matrix3x3(const float _matrix[3][3])
{
	matrix[0][0] = _matrix[0][0]; matrix[0][1] = _matrix[0][1]; matrix[0][2] = _matrix[0][2];
	matrix[1][0] = _matrix[1][0]; matrix[1][1] = _matrix[1][1]; matrix[1][2] = _matrix[1][2];
	matrix[2][0] = _matrix[2][0]; matrix[2][1] = _matrix[2][1]; matrix[2][2] = _matrix[2][2];
}

Ougi::Matrix3x3::Matrix3x3(const Matrix3x3& other)
{
	matrix[0][0] = other[0][0]; matrix[0][1] = other[0][1]; matrix[0][2] = other[0][2];
	matrix[1][0] = other[1][0]; matrix[1][1] = other[1][1]; matrix[1][2] = other[1][2];
	matrix[2][0] = other[2][0]; matrix[2][1] = other[2][1]; matrix[2][2] = other[2][2];
}

Ougi::Matrix3x3& Ougi::Matrix3x3::operator=(const Matrix3x3& other)
{
	matrix[0][0] = other[0][0]; matrix[0][1] = other[0][1]; matrix[0][2] = other[0][2];
	matrix[1][0] = other[1][0]; matrix[1][1] = other[1][1]; matrix[1][2] = other[1][2];
	matrix[2][0] = other[2][0]; matrix[2][1] = other[2][1]; matrix[2][2] = other[2][2];
	return (*this);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator-() const
{
	return Matrix3x3(
		-matrix[0][0], -matrix[0][1], -matrix[0][2],
		-matrix[1][0], -matrix[1][1], -matrix[1][2],
		-matrix[2][0], -matrix[2][1], -matrix[2][2]
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator+(const Matrix3x3& addend) const
{
	return Matrix3x3(
		matrix[0][0] + addend[0][0], matrix[0][1] + addend[0][1], matrix[0][2] + addend[0][2],
		matrix[1][0] + addend[1][0], matrix[1][1] + addend[1][1], matrix[1][2] + addend[1][2],
		matrix[2][0] + addend[2][0], matrix[2][1] + addend[2][1], matrix[2][2] + addend[2][2]
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator-(const Matrix3x3& subtrahend) const
{
	return Matrix3x3(
		matrix[0][0] - subtrahend[0][0], matrix[0][1] - subtrahend[0][1], matrix[0][2] - subtrahend[0][2],
		matrix[1][0] - subtrahend[1][0], matrix[1][1] - subtrahend[1][1], matrix[1][2] - subtrahend[1][2],
		matrix[2][0] - subtrahend[2][0], matrix[2][1] - subtrahend[2][1], matrix[2][2] - subtrahend[2][2]
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator*(const float multiplier) const
{
	return Matrix3x3(
		matrix[0][0] * multiplier, matrix[0][1] * multiplier, matrix[0][2] * multiplier,
		matrix[1][0] * multiplier, matrix[1][1] * multiplier, matrix[1][2] * multiplier,
		matrix[2][0] * multiplier, matrix[2][1] * multiplier, matrix[2][2] * multiplier
	);
}

Ougi::Vector3 Ougi::Matrix3x3::operator*(const Ougi::Vector3& multiplier) const
{
	return Vector3(
		(matrix[0][0] * multiplier.x) + (matrix[1][0] * multiplier.y) + (matrix[2][0] * multiplier.z),
		(matrix[0][1] * multiplier.x) + (matrix[1][1] * multiplier.y) + (matrix[2][1] * multiplier.z),
		(matrix[0][2] * multiplier.x) + (matrix[1][2] * multiplier.y) + (matrix[2][2] * multiplier.z)
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator*(const Ougi::Matrix3x3& multiplier) const
{
	return Matrix3x3(
		(matrix[0][0] * multiplier[0][0]) + (matrix[0][1] * multiplier[1][0]) + (matrix[0][2] * multiplier[2][0]),
		(matrix[0][0] * multiplier[0][1]) + (matrix[0][1] * multiplier[1][1]) + (matrix[0][2] * multiplier[2][1]),
		(matrix[0][0] * multiplier[0][2]) + (matrix[0][1] * multiplier[1][2]) + (matrix[0][2] * multiplier[2][2]),
		
		(matrix[1][0] * multiplier[0][0]) + (matrix[1][1] * multiplier[1][0]) + (matrix[1][2] * multiplier[2][0]),
		(matrix[1][0] * multiplier[0][1]) + (matrix[1][1] * multiplier[1][1]) + (matrix[1][2] * multiplier[2][1]),
		(matrix[1][0] * multiplier[0][2]) + (matrix[1][1] * multiplier[1][2]) + (matrix[1][2] * multiplier[2][2]),
		
		(matrix[2][0] * multiplier[0][0]) + (matrix[2][1] * multiplier[1][0]) + (matrix[2][2] * multiplier[2][0]),
		(matrix[2][0] * multiplier[0][1]) + (matrix[2][1] * multiplier[1][1]) + (matrix[2][2] * multiplier[2][1]),
		(matrix[2][0] * multiplier[0][2]) + (matrix[2][1] * multiplier[1][2]) + (matrix[2][2] * multiplier[2][2])
	);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator/(const float divisor) const
{
	return (*this) * (1.0f / divisor);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator+=(const Matrix3x3& addend)
{
	(*this) = (*this) + addend;
	return (*this);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator-=(const Matrix3x3& subtrahend)
{
	(*this) = (*this) - subtrahend;
	return (*this);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator*=(const float multiplier)
{
	(*this) = (*this) * multiplier;
	return (*this);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator*=(const Ougi::Matrix3x3& multiplier)
{
	(*this) = (*this) * multiplier;
	return (*this);
}

Ougi::Matrix3x3 Ougi::Matrix3x3::operator/=(const float divisor)
{
	(*this) = (*this) / divisor;
	return (*this);
}

bool Ougi::Matrix3x3::operator==(const Matrix3x3& rhs) const
{
	return Equals(rhs, 0.0f);
}

bool Ougi::Matrix3x3::Equals(const Matrix3x3& rhs, const float tolerance) const
{
	bool equal = true; int i = 0; int j = 0;
	while (equal && i < 3)
	{
		while (equal && j < 3)
		{
			if (Ougi::Abs(matrix[i][j] - rhs[i][j]) > tolerance)
				equal = false;
			j++;
		}
		i++;
	}
	return equal;
}