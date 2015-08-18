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

namespace Ougi
{
	float sqrt(float arg);
	
	int abs(int arg);
	float abs(float arg);
	
	// MUST-USE!! http://mathonweb.com/help_ebook/html/algorithms.htm
	float sin(float rads);
	float cos(float rads);
	float tan(float rads);
	
	float arcsin(float rads);
	float arccos(float rads);
	float arctan(float rads);
	
	float pow(float base, unsigned int power);
	float pow(float base, int power);
	float pow(float base, float power);
	
	float log(float base, float arg);
	unsigned int factorial(unsigned int arg);
	
	// private
	float normalizeAngle(float rads);
	float approximateSin(float rads);
	float approximateCos(float rads);
	float approximateTan(float rads);
}

#endif