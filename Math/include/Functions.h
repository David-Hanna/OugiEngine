#ifndef OUGI_MATH_FUNCTIONS_H
#define OUGI_MATH_FUNCTIONS_H
//-------------------------------------------------------------------------------------------
// Functions - defines basic mathematical functions
//-------------------------------------------------------------------------------------------

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