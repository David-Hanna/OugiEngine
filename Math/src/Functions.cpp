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

float normalizeAngle(float rads)
{
	while (rads < 0.0f)
	{
		rads += TWO_PI;
	}
	while (rads >= TWO_PI)
	{
		rads -= TWO_PI;
	}
	return rads;
}

float approximateSin(float rads)
{
	const float TWO_RADS = rads * rads;
	const float THREE_RADS = TWO_RADS * rads;
	return rads - (THREE_RADS * 0.1666667f) + (THREE_RADS * TWO_RADS * 0.008333333f);
}

float approximateCos(float rads)
{
	const float TWO_RADS = rads * rads;
	const float FOUR_RADS = TWO_RADS * TWO_RADS;
	return 1.0f - (TWO_RADS * 0.5f) + (FOUR_RADS * 0.04166667f) - (FOUR_RADS * TWO_RADS * 0.001388888f);
}

float approximateTan(float rads)
{
	const float TWO_RADS = rads * rads;
	const float THREE_RADS = TWO_RADS * rads;
	const float FIVE_RADS = THREE_RADS * TWO_RADS;
	return rads + (THREE_RADS * 0.3333333f) + (FIVE_RADS * 0.1333333f) + (FIVE_RADS * TWO_RADS * 0.05396825f);
}

float sin(float rads)
{
	rads = normalizeAngle(rads);
	// for 3rd quadrant -> using -sin(x) == sin(-x).
	// hopefully the small angle approximation works with negative inputs...
	if (rads > HALF_PI && rads <= THREE_HALVES_PI)
	{
		rads = PI - rads;
	}
	// negative rads again here. same note as above.
	else if (rads > THREE_HALVES_PI)
	{
		rads = TWO_PI - rads;
	}
	if (rads < QUARTER_PI)
	{
		return approximateSin(rads);
	}
	else
	{
		return approximateCos(HALF_PI - rads);
	}
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