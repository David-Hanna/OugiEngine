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

int Ougi::abs(int arg)
{
	return arg > 0 ? arg : -arg;
}

float Ougi::abs(float arg)
{
	return arg > 0.0f ? arg : -arg;
}

float Ougi::normalizeAngle(float rads)
{
	while (rads < 0.0f)
	{
		rads += Ougi::TWO_PI;
	}
	while (rads >= Ougi::TWO_PI)
	{
		rads -= Ougi::TWO_PI;
	}
	return rads;
}

float Ougi::approximateSin(float rads)
{
	const float TWO_RADS = rads * rads;
	const float THREE_RADS = TWO_RADS * rads;
	return rads - (THREE_RADS * 0.1666667f) + (THREE_RADS * TWO_RADS * 0.008333333f);
}

float Ougi::approximateCos(float rads)
{
	const float TWO_RADS = rads * rads;
	const float FOUR_RADS = TWO_RADS * TWO_RADS;
	return 1.0f - (TWO_RADS * 0.5f) + (FOUR_RADS * 0.04166667f) - (FOUR_RADS * TWO_RADS * 0.001388888f);
}

float Ougi::approximateTan(float rads)
{
	const float TWO_RADS = rads * rads;
	const float THREE_RADS = TWO_RADS * rads;
	const float FIVE_RADS = THREE_RADS * TWO_RADS;
	return rads + (THREE_RADS * 0.3333333f) + (FIVE_RADS * 0.1333333f) + (FIVE_RADS * TWO_RADS * 0.05396825f);
}

float Ougi::sin(float rads)
{
	rads = normalizeAngle(rads);
	// for 3rd quadrant -> using -sin(x) == sin(-x).
	// hopefully the small angle approximation works with negative inputs...
	if (rads > Ougi::HALF_PI && rads <= Ougi::THREE_HALVES_PI)
	{
		rads = Ougi::PI - rads;
	}
	// negative rads again here. same note as above.
	else if (rads > Ougi::THREE_HALVES_PI)
	{
		rads = Ougi::TWO_PI - rads;
	}
	if (rads < Ougi::QUARTER_PI)
	{
		return approximateSin(rads);
	}
	else
	{
		return approximateCos(Ougi::HALF_PI - rads);
	}
}

float Ougi::cos(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::tan(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::arcsin(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::arccos(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::arctan(float rads)
{
	// TODO
	return 0.0f;
}

float Ougi::pow(float base, unsigned int power)
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

float Ougi::pow(float base, int power)
{
	bool inverse = power < 0;
	if (inverse)
	{
		power = -power;
	}
	
	float result = pow(base, (unsigned int)power);
	
	if (inverse)
	{
		return 1.0f / result;
	}
	else
	{
		return result;
	}
}

float Ougi::pow(float base, float power)
{
	// TODO
	return 0.0f;
}

float Ougi::log(float base, float arg)
{
	// TODO
	return 0.0f;
}

unsigned int Ougi::factorial(unsigned int arg)
{
	unsigned int result = 1;
	for (unsigned int i = 0; i < arg; ++i)
	{
		result *= i + 1;
	}
	return result;
}