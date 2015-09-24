//--------------------------------------------------------------------------------
// Matrix3x3.h
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

#ifndef OUGI_MATH_MATRIX3X3_H
#define OUGI_MATH_MATRIX3X3_H

#include "Functions.h"
#include "Vector3.h"
#include "../../Standard/include/Debug.h"

namespace Ougi
{
	class Matrix3x3
	{
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

		bool operator==(const Matrix3x3& rhs) const;
		bool Equals(const Matrix3x3& rhs, const float tolerance = 0.0f) const;
	protected:
		float matrix[3][3];
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::Matrix3x3& matrix)
{
	return out << "[(" << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2] << "), (" << matrix[1][0] << ", " << matrix[1][1] << ", " << matrix[1][2] << "), (" << matrix[2][0] << ", " << matrix[2][1] << ", " << matrix[2][2] << ")]";
}
#endif

#endif