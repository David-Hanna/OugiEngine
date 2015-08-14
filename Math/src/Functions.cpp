#include "../include/Functions.h"

float Ougi::sqrt(float arg)
{
	const float arghalf = 0.5f*arg;

	union // get bits for floating value
	{
		float x;
		int i;
	} u;

	u.x = arg;
	u.i = 0x5f3759df - (u.i >> 1);  // gives initial guess y0
	return arg*u.x*(1.5f - arghalf*u.x*u.x);// Newton step, repeating increases accuracy
}

float Ougi::invsqrt(float arg)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = arg * 0.5F;
	y = arg;
	i = *(long *)&y;                       // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);             // magic number
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));   // repeat for more accuracy

	return y;
}

int Ougi::abs(int arg)
{
	return arg > 0 ? arg : -arg;
}

float Ougi::abs(float arg)
{
	return arg > 0.0f ? arg : -arg;
}

float sin(float rads)
{
	
}

float cos(float rads)
{
	
}

float tan(float rads)
{
	
}

float arcsin(float rads)
{
	
}

float arccos(float rads)
{
	
}

float arctan(float rads)
{
	
}

float exp(int base, int power)
{
	int result = 1;
	
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

float exp(int base, float power);
{
	
}

float exp(float base, int power)
{
	float result = 1.0f;
	
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

float exp(float base, float power)
{
	
}

float log(float base, float arg)
{
	
}

float factorial(unsigned int arg)
{
	unsigned int result = 1;
	for (unsigned int i = 0; i < arg; ++i)
	{
		result *= i + 1;
	}
	return result;
}