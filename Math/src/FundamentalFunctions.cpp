#include "FundamentalFunctions.h"

float HM::sqrt(float arg)
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

float HM::invsqrt(float arg)
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