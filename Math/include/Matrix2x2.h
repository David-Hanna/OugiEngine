//--------------------------------------------------------------------------------
// Matrix2x2.h
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

#ifndef OUGI_MATH_MATRIX2X2_H
#define OUGI_MATH_MATRIX2X2_H

#include "Functions.h"
#include "Vector2.h"
#include "../../Common/include/Debug.h"

namespace Ougi
{
	class Matrix2x2
	{
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

		bool operator==(const Matrix2x2& rhs) const;
		bool Equals(const Matrix2x2& rhs, const float tolerance = 0.0f) const;
	protected:
		float matrix[2][2];
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::Matrix2x2& matrix)
{
	return out << "[(" << matrix[0][0] << ", " << matrix[0][1] << "), (" << matrix[1][0] << ", " << matrix[1][1] << ")]";
}
#endif

#endif