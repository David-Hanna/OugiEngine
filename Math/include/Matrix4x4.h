//--------------------------------------------------------------------------------
// Matrix4x4.h
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

#ifndef OUGI_MATH_MATRIX4X4_H
#define OUGI_MATH_MATRIX4X4_H

#ifdef DEBUG
#include <iostream>
#endif

#include "Functions.h"
#include "Vector4.h"

namespace Ougi
{
	class Matrix4x4
	{
	public:
		Matrix4x4();
		Matrix4x4(const float _00, const float _01, const float _02, const float _03,
				  const float _10, const float _11, const float _12, const float _13,
				  const float _20, const float _21, const float _22, const float _23,
				  const float _30, const float _31, const float _32, const float _33);
		Matrix4x4(const float _matrix[4][4]);
		Matrix4x4(const Matrix4x4& other);
		
		Matrix4x4& operator=(const Matrix4x4& other);

		float*       operator[](const unsigned int index)       { return matrix[index]; }
		float const* operator[](const unsigned int index) const { return matrix[index]; }

		Matrix4x4 operator-() const;

		Matrix4x4 operator+(const Matrix4x4& addend) const;
		Matrix4x4 operator-(const Matrix4x4& subtrahend) const;
		Matrix4x4 operator*(const float multiplier)	const;
		Vector4   operator*(const Vector4& multiplier) const;
		Matrix4x4 operator*(const Matrix4x4& multiplier) const;
		Matrix4x4 operator/(const float divisor) const;

		Matrix4x4 operator+=(const Matrix4x4& addend);
		Matrix4x4 operator-=(const Matrix4x4& subtrahend);
		Matrix4x4 operator*=(const float multiplier);
		Matrix4x4 operator*=(const Matrix4x4& multiplier);
		Matrix4x4 operator/=(const float divisor);

		bool operator==(const Matrix4x4& rhs) const;
		bool Equals(const Matrix4x4& rhs, const float tolerance = 0.0f) const;
		 
	protected:
		float matrix[4][4];
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::Matrix4x4& matrix)
{
	return out << "[(" << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2] << ", " << matrix[0][3] << "), (" << matrix[1][0] << ", " << matrix[1][1] << ", " << matrix[1][2] << ", " << matrix[1][3] << "), (" << matrix[2][0] << ", " << matrix[2][1] << ", " << matrix[2][2] << ", " << matrix[2][3] << "), (" << matrix[3][0] << ", " << matrix[3][1] << ", " << matrix[3][2] << ", " << matrix[3][3] << ")]";
}
#endif

#endif