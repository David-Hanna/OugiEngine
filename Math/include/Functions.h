#ifndef OUGI_FUNCTIONS_H
#define OUGI_FUNCTIONS_H
//-------------------------------------------------------------------------------------------
// Functions - defines fundamental mathematical functions
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	float sqrt(const float arg);
	float invsqrt(const float arg);
	
	int abs(const int arg);
	float abs(const float arg);
	
	float sin(const float rads);
	float cos(const float rads);
	float tan(const float rads);
	
	float arcsin(const float rads);
	float arccos(const float rads);
	float arctan(const float rads);
	
	float exp(const float base, const float power);
	float log(const float base, const float arg);
	float factorial(const unsigned int arg);
}

#endif