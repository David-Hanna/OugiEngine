#ifndef OUGI_MATH_FUNCTIONS_H
#define OUGI_MATH_FUNCTIONS_H
//-------------------------------------------------------------------------------------------
// Functions - defines basic mathematical functions
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	float sqrt(const float arg);
	float invsqrt(const float arg);
	
	int abs(const int arg);
	float abs(const float arg);
	
	// MUST-USE!! http://mathonweb.com/help_ebook/html/algorithms.htm
	float sin(const float rads);
	float cos(const float rads);
	float tan(const float rads);
	
	float arcsin(const float rads);
	float arccos(const float rads);
	float arctan(const float rads);
	
	float exp(int base, int power);
	float exp(int base, float power);
	float exp(float base, int power);
	float exp(float base, float power);
	
	float log(const float base, const float arg);
	float factorial(const unsigned int arg);
}

#endif