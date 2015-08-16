
#define DEBUG
#define MATH
//#define STANDARD

#ifdef MATH
#include "Math/include/Constants.h"
#include "Math/include/Functions.h"
#include "Math/include/Vector2.h"
#include "Math/include/Vector3.h"
#include "Math/include/Vector4.h"
#include "Math/include/Matrix2x2.h"
#include "Math/include/Matrix3x3.h"
#include "Math/include/Matrix4x4.h"
#endif

#ifdef STANDARD
#include "Standard/include/String.h"
#endif

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <limits>

int TIMES = 10000000;
std::clock_t start;
std::clock_t end;

void begin()
{
	start = std::clock();
}

void stop()
{
	end = std::clock();
}

double duration()
{
	return (((end - start) / ((double) CLOCKS_PER_SEC)) * 1000);
}

void ftestf(const char* name, float input, float val, float expected)
{
	std::cout << name << "(" << input << "): " << val << " == " << expected << ", "; 
	if (Ougi::abs(val - expected) < 0.0001f) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void fftestf(const char* name, float input1, float input2, float val, float expected)
{
	std::cout << name << "(" << input1 << ", " << input2 << "): " << val << " == " << expected << ", "; 
	if (Ougi::abs(val - expected) < 0.0001f) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void math()
{
#ifdef MATH
	float fval;

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Functions - Unit Tests          -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	ftestf("Ougi::sqrt", 0.0f, Ougi::sqrt(0.0f), 0.0f);
	ftestf("Ougi::sqrt", 2.0f, Ougi::sqrt(2.0f), 1.41386);
	ftestf("Ougi::sqrt", 5.14f, Ougi::sqrt(5.14f), 2.26644);
	ftestf("Ougi::sqrt", -3.0f, Ougi::sqrt(-3.0f), -std::numeric_limits<float>::infinity());
	ftestf("Ougi::abs", 5, Ougi::abs(5), 5);
	ftestf("Ougi::abs", -5, Ougi::abs(-5), 5);
	ftestf("Ougi::abs", 4.6f, Ougi::abs(4.6f), 4.6f);
	ftestf("Ougi::abs", -4.6f, Ougi::abs(-4.6f), 4.6f);
	ftestf("Ougi::sin", 0.89f, Ougi::sin(0.89f), 0.777071f);
	ftestf("Ougi::sin", -0.89f, Ougi::sin(-0.89f), -0.777071f);
	ftestf("Ougi::sin", 5.41f, Ougi::sin(5.14f), -0.909959f);
	ftestf("Ougi::sin", -5.92f, Ougi::sin(-5.92f), 0.355254f);
	fftestf("Ougi::pow", 3, 4, Ougi::pow(3, 4), 81);
	fftestf("Ougi::pow", 5.4f, 3, Ougi::pow(5.4f, 3), 157.464f);
	
	std::cout << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Functions - Benchmarking        -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = sqrt(7346.123f);
	}
	stop();
	std::cout << "std::sqrt: " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = Ougi::sqrt(7346.123f);
	}
	stop();
	std::cout << "ougi::sqrt: " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = sin(0.89f);
	}
	stop();
	std::cout << "std::sin: " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = Ougi::sin(0.89f);
	}
	stop();
	std::cout << "ougi::sin: " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = pow(342.6745f, 4);
	}
	stop();
	std::cout << "std::pow: " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = Ougi::pow(342.6745f, 4u);
	}
	stop();
	std::cout << "ougi::pow(float, unsigned int): " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = Ougi::pow(342.6745f, -4);
	}
	stop();
	std::cout << "ougi::pow(float, int): " << duration() << std::endl;
	
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		fval = Ougi::factorial(8u);
	}
	stop();
	std::cout << "ougi::factorial: " << duration() << std::endl;
	
	std::cout << std::endl;
	
	//=======================
	// Vector2
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Vector 2               -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	Ougi::Vector2 a(1.0f, 2.0f);
	Ougi::Vector2 b(-9.875f, 32.99f);
	std::cout << "Vector2 a: " << a << std::endl;
	std::cout << "Vector2 b: " << b << std::endl;
	std::cout << "Negative a: " << -a << std::endl;
	std::cout << "Negative b: " << -b << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * 6: " << (a * 6) << std::endl;
	std::cout << "a dot b: " << (a * b) << std::endl;
	std::cout << "a / 6: " << (a / 6) << std::endl;
	std::cout << "a += b: " << (a += b) << std::endl;
	std::cout << "a -= b: " << (a -= b) << std::endl;
	std::cout << "a *= -3: " << (a *= -3) << std::endl;
	std::cout << "a /= -3: " << (a /= -3) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a.Equals(b, 50.0f): " << (a.Equals(b, 50.0f)) << std::endl;
	std::cout << "a.LengthSquared(): " << a.LengthSquared() << std::endl;
	std::cout << "a.Length(): " << a.Length() << std::endl;
	std::cout << "a.Normalized(): " << a.Normalized() << std::endl;
	std::cout << "a.Normalize(): " << a.Normalize() << std::endl;
	std::cout << std::endl;
	
	//=======================
	// Vector3
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Vector 3               -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	Ougi::Vector3 c(1.0f, 2.0f, 3.0f);
	Ougi::Vector3 d(-9.875f, 32.99f, 12.2f);
	std::cout << "Vector3 c: " << c << std::endl;
	std::cout << "Vector3 d: " << d << std::endl;
	std::cout << "Negative c: " << -c << std::endl;
	std::cout << "Negative d: " << -d << std::endl;
	std::cout << "c + d: " << (c + d) << std::endl;
	std::cout << "c - d: " << (c - d) << std::endl;
	std::cout << "c * 7: " << (c * 7) << std::endl;
	std::cout << "c dot d: " << (c * d) << std::endl;
	std::cout << "c cross d: " << (c.Cross(d)) << std::endl;
	std::cout << "c / 7: " << (c / 7) << std::endl;
	std::cout << "c += d: " << (c += d) << std::endl;
	std::cout << "c -= d: " << (c -= d) << std::endl;
	std::cout << "c *= -2: " << (c *= -2) << std::endl;
	std::cout << "c /= -2: " << (c /= -2) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c.Equals(d, 50.0f): " << (c.Equals(d, 50.0f)) << std::endl;
	std::cout << "c.LengthSquared(): " << c.LengthSquared() << std::endl;
	std::cout << "c.Length(): " << c.Length() << std::endl;
	std::cout << "c.Normalized(): " << c.Normalized() << std::endl;
	std::cout << "c.Normalize(): " << c.Normalize() << std::endl;
	std::cout << std::endl;
	
	//=======================
	// Vector4
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Vector 4               -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	Ougi::Vector4 e(1.0f, 2.0f, 3.0f, 4.0f);
	Ougi::Vector4 f(-9.875f, 32.99f, 12.2f, -4.5f);
	std::cout << "Vector4 e: " << e << std::endl;
	std::cout << "Vector4 f: " << f << std::endl;
	std::cout << "Negative e: " << -e << std::endl;
	std::cout << "Negative f: " << -f << std::endl;
	std::cout << "e + f: " << (e + f) << std::endl;
	std::cout << "e - f: " << (e - f) << std::endl;
	std::cout << "e * 7: " << (e * 7) << std::endl;
	std::cout << "e dot f: " << (e * f) << std::endl;
	std::cout << "e / 7: " << (e / 7) << std::endl;
	std::cout << "e += f: " << (e += f) << std::endl;
	std::cout << "e -= f: " << (e -= f) << std::endl;
	std::cout << "e *= -2: " << (e *= -2) << std::endl;
	std::cout << "e /= -2: " << (e /= -2) << std::endl;
	std::cout << "e == f: " << (e == f) << std::endl;
	std::cout << "e.Equals(f, 50.0f): " << (e.Equals(f, 50.0f)) << std::endl;
	std::cout << "e.LengthSquared(): " << e.LengthSquared() << std::endl;
	std::cout << "e.Length(): " << e.Length() << std::endl;
	std::cout << "e.Normalized(): " << e.Normalized() << std::endl;
	std::cout << "e.Normalize(): " << e.Normalize() << std::endl;
	std::cout << std::endl;
	
	//=======================
	// Matrix2x2
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Matrix2x2              -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << Ougi::Matrix2x2(11.0f, 12.0f, 13.0f, 14.0f) << std::endl;
	std::cout << std::endl;
	
	//=======================
	// Matrix3x3
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Matrix3x3              -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << Ougi::Matrix3x3(15.0f, 16.0f, 17.0f, 18.0f, 19.0f, 20.0f, 21.0f, 22.0f, 23.0f) << std::endl;
	std::cout << std::endl;
	
	//=======================
	// Matrix4x4
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Matrix4x4              -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << Ougi::Matrix4x4(24.0f, 25.0f, 26.0f, 27.0f, 28.0f, 29.0f, 30.0f, 31.0f, 32.0f, 33.0f, 34.0f, 35.0f, 36.0f, 37.0f, 38.0f, 39.0f) << std::endl;
	std::cout << std::endl;
#endif
}

void standard()
{
#ifdef STANDARD
	//=======================
	// String
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  String                 -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;
	Ougi::String empty;
	std::cout << "Empty: " << empty << std::endl;
	std::cout << "empty has any?: " << empty.Any() << std::endl;
	std::cout << "Is empty empty?: " << empty.Empty() << std::endl;
	std::cout << "Empty's length: " << empty.Length() << std::endl;
	std::cout << "Empty at char 0: " << empty[0] << std::endl;
	std::cout << "empty starts with c? " << empty.StartsWith('c') << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	Ougi::String z('z');
	std::cout << "z: " << z << std::endl;
	std::cout << "z has any?: " << z.Any() << std::endl;
	std::cout << "Is z empty?: " << z.Empty() << std::endl;
	std::cout << "z's length: " << z.Length() << std::endl;
	std::cout << "z at char 0: " << z[0] << std::endl;
	std::cout << "z starts with z?: " << z.StartsWith('z') << std::endl;
	std::cout << "z contains z?: " << z.Contains('z') << std::endl;
	std::cout << "z insert a at 0: " << z.Insert('a', 0) << std::endl;
	std::cout << "z insert a at 1: " << z.Insert('a', 1) << std::endl;
	std::cout << "z equals z?: " << (z == 'z') << std::endl;
	std::cout << "z equals a?: " << (z == 'a') << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	Ougi::String hello("hello");
	std::cout << "hello: " << hello << std::endl;
	std::cout << "hello has any?: " << hello.Any() << std::endl;
	std::cout << "Is hello empty?: " << hello.Empty() << std::endl;
	std::cout << "hello's length: " << hello.Length() << std::endl;
	std::cout << "hello at char 2: " << hello[2] << std::endl;
	std::cout << "substring of hello at 1: " << hello.Substring(1) << std::endl;
	std::cout << "hello starts with hell?: " << hello.StartsWith("hell") << std::endl;
	std::cout << "hello + \' : \' + hello: " << hello + " / " + hello << std::endl;
	std::cout << "hello contains llo? " << hello.Contains("llo") << std::endl;
	std::cout << "hello equals hello?: " << (hello == "hello") << std::endl;
	std::cout << "hello equals magic?: " << (hello == "magic") << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	Ougi::String mystring(Ougi::String("mystring"));
	std::cout << "mystring: " << mystring << std::endl;
	std::cout << "mystring has any?: " << mystring.Any() << std::endl;
	std::cout << "Is mystring empty?: " << mystring.Empty() << std::endl;
	std::cout << "mystring's length: " << mystring.Length() << std::endl;
	std::cout << "mystring at char 6: " << mystring[6] << std::endl;
	std::cout << "substring of mystring from 3 to 6: " << mystring.Substring(3, 6) << std::endl;
	std::cout << "mystring starts with magic?: " << mystring.StartsWith("magic") << std::endl;
	std::cout << "mystring contains foo?: " << mystring.Contains("foo") << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	empty = z;
	std::cout << "empty after assigning z: " << empty << std::endl;
	empty = hello;
	std::cout << "empty after assigning hello: " << empty << std::endl;
	empty = mystring;
	std::cout << "empty after assigning mystring: " << empty << std::endl;
	empty.Clear();
	std::cout << "empty after clearing: " << empty << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	std::cout << std::endl;
#endif
}

int main(int argc, char* argv[])
{
	math();
	standard();
	return 0;
}