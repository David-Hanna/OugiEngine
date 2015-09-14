//--------------------------------------------------------------------------------
// Functions.cpp
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

#include "../include/Functions.h"

float Ougi::Sqrt(float arg)
{	
	unsigned int i = *(unsigned int*) &arg;
	i = (i + (127 << 23)) >> 1;
	return *(float*) &i;
}

int Ougi::Abs(int arg)
{
	return arg > 0 ? arg : -arg;
}

float Ougi::Abs(float arg)
{
	return arg > 0.0f ? arg : -arg;
}

int Ougi::Floor(float arg)
{
	if (arg >= 0.0f)
	{
		return (int)(arg);
	}
	else
	{
		// (int)(arg - 1) is incorrect in the case arg is already an int
		if ((float)((int)arg) == arg)
		{
			return arg;
		}
		else
		{
			return (int)(arg - 1);
		}
	}
}

int Ougi::Ceiling(float arg)
{
	if (arg >= 0.0f)
	{
		// (int)(arg + 1) is incorrect in the case arg is already an int
		if ((float)((int)arg) == arg)
		{
			return arg;
		}
		else
		{
			return (int)(arg + 1);
		}
	}
	else
	{
		return (int)arg;
	}
}

float Ougi::ModFloat(float val, float start, float end)
{
	if (val < start || val > end)
	{
		const float width = end - start;
		const float offsetValue = val - start;
		
		return (offsetValue - (Floor(offsetValue / width) * width)) + start;
	}
	return val;
}

float Ougi::Sin(float rads)
{	
	rads = ModFloat(rads, -PI, PI);
#ifdef EXTRA_PRECISION
	const float y = (4.0f / PI) * rads + (-4.0f / (PI_SQUARED)) * rads * Abs(rads);
	return 0.225f * (y * Abs(y) - y) + y;
#else
	return (4.0f / PI) * rads + (-4.0f / (PI_SQUARED)) * rads * Abs(rads);
#endif
}

float Ougi::Cos(float rads)
{
	rads *= 1.0f / (2.0f * PI);
	rads -= 0.25f + Floor(rads + 0.25f);
	rads *= 16.0f * (Abs(rads) - 0.5f);
#ifdef EXTRA_PRECISION
	rads += 0.225f * rads * (Abs(rads) - 1.0f);
#endif
	return rads;
}

float Ougi::Tan(float rads)
{
	// Improve speed and accuracy with non-sin/cos algorithm.
	return Sin(rads) / Cos(rads);
}

float Ougi::Arcsin(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::Arccos(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::Arctan(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::Pow(float base, unsigned int power)
{
	float result = 1;
	
	while (power)
	{
		if (power & 1)
		{
			result *= base;
		}
		power >>= 1;
		base *= base;
	}
	
	return result;
}

float Ougi::Pow(float base, int power)
{
	bool inverse = power < 0;
	if (inverse)
	{
		power = -power;
	}
	
	float result = Pow(base, (unsigned int)power);
	
	if (inverse)
	{
		return 1.0f / result;
	}
	else
	{
		return result;
	}
}

float Ougi::Pow(float base, float power)
{
	// TODO
	return 0.0f;
}

float Ougi::Log(float base, float arg)
{
	// TODO
	return 0.0f;
}

unsigned int Ougi::Factorial(unsigned int arg)
{
	unsigned int result = 1;
	for (unsigned int i = 0; i < arg; ++i)
	{
		result *= i + 1;
	}
	return result;
}