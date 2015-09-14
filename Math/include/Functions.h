//-------------------------------------------------------------------------------------------
// Functions.h
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
//-------------------------------------------------------------------------------------------

#ifndef OUGI_MATH_FUNCTIONS_H
#define OUGI_MATH_FUNCTIONS_H

#include "Constants.h"

#define EXTRA_PRECISION  // for sin and cos, lose a little speed for more accuracy. still faster than std::sin/cos

namespace Ougi
{
	float Sqrt(float arg);
	
	int Abs(int arg);
	float Abs(float arg);
	
	int Floor(float arg);
	int Ceiling(float arg);
	
	float ModFloat(float val, float start, float end);

	float Sin(float rads);
	float Cos(float rads);
	float ApproximateTan(float rads); // private - use Tan instead.
	float Tan(float rads);
	
	float Arcsin(float arg); // domain -1 <= arg <= 1
	float Arccos(float arg); // domain 0 <= arg <= PI
	float ApproximateArctan(float arg); // private - use Tan instead.
	float Arctan(float arg);
	
	float Log(float base, float arg);
	
	float Exp(int power);
	float Exp(float power);
	
	float Pow(float base, unsigned int power);
	float Pow(float base, int power);
	float Pow(float base, float power);
	
	unsigned int Factorial(unsigned int arg);
}

#endif