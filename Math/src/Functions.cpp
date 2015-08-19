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
	return arg >= 0.0f ? (int)(arg) : (int)(arg - 1);
}

int Ougi::Ceiling(float arg)
{
	return arg >= 0.0f ? (int)(arg + 1) : (int)(arg);
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
#if EXTRA_PRECISION
	const float y = (4.0f / PI) * rads + (-4.0f / (PI * PI)) * rads * Abs(rads);
	return 0.225f * (y * Abs(y) - y) + y;
#else
	return (4.0f / PI) * rads + (-4.0f / (PI * PI)) * rads * Abs(rads);
#endif
}

float Ougi::Cos(float rads)
{
	rads *= 1.0f / (2.0f * PI);
	rads -= 0.25f + Floor(rads + 0.25f);
	rads *= 16.0f * (Abs(rads) - 0.5f);
#if EXTRA_PRECISION
	rads += 0.225f * rads * (Abs(rads) - 1.0f);
#endif
	return rads;
}

float Ougi::Tan(float rads)
{
	// TODO
	return 0.0f;
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