#ifndef OUGI_MATH_FUNCTIONS_H
#define OUGI_MATH_FUNCTIONS_H
//-------------------------------------------------------------------------------------------
// Functions - defines basic mathematical functions
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	float sqrt(float arg);
	float invsqrt(float arg);
	
	int abs(int arg);
	float abs(float arg);
	
	// MUST-USE!! http://mathonweb.com/help_ebook/html/algorithms.htm
	float sin(float rads);
	float cos(float rads);
	float tan(float rads);
	
	float arcsin(float rads);
	float arccos(float rads);
	float arctan(float rads);
	
	float exp(int base, int power);
	float exp(int base, float power);
	float exp(float base, int power);
	float exp(float base, float power);
	
	float log(float base, float arg);
	float factorial(unsigned int arg);
}

#endif