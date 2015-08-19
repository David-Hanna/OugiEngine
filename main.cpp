
#define DEBUG

#define UNIT_TEST
#define BENCHMARK

#define MATH
#define STANDARD

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
#endif

#include <iostream>
#include <cmath>
#include <limits>

#include "unittest.h"
#include "benchmarking.h"

void math()
{
#ifdef MATH
#ifdef UNIT_TEST
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Functions - Unit Tests          -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	ftestf("Ougi::Sqrt", 0.0f, Ougi::Sqrt(0.0f), 0.0f);
	ftestf("Ougi::Sqrt", 2.0f, Ougi::Sqrt(2.0f), 1.41386);
	ftestf("Ougi::Sqrt", 5.14f, Ougi::Sqrt(5.14f), 2.26644);
	
	ftestf("Ougi::Abs", 5, Ougi::Abs(5), 5);
	ftestf("Ougi::Abs", -5, Ougi::Abs(-5), 5);
	ftestf("Ougi::Abs", 4.6f, Ougi::Abs(4.6f), 4.6f);
	ftestf("Ougi::Abs", -4.6f, Ougi::Abs(-4.6f), 4.6f);
	
	ftesti("Ougi::Floor", 45.678f, Ougi::Floor(45.678f), 45);
	ftesti("Ougi::Floor", -45.678f, Ougi::Floor(-45.678f), -46);
	
	ftesti("Ougi::Ceiling", 45.678f, Ougi::Ceiling(45.678f), 46);
	ftesti("Ougi::Ceiling", -45.678f, Ougi::Ceiling(-45.678f), -45);
	
	// needs to be re-written to ModFloat.
	// ftestf("Ougi::NormalizeAngle", 0.12f, Ougi::NormalizeAngle(0.12f), 0.12f);
	// ftestf("Ougi::NormalizeAngle", -514.2343f, Ougi::NormalizeAngle(-514.2343f), 0.9868951f);
	// ftestf("Ougi::NormalizeAngle", 514.2343f, Ougi::NormalizeAngle(514.2343f), 5.296290f);
	
	ftestf("Ougi::Sin", -7.89f, Ougi::Sin(-7.89f), -0.9993514f);
	ftestf("Ougi::Sin", -0.12f, Ougi::Sin(-0.12f), -0.1197122f);
	ftestf("Ougi::Sin", 0.12f, Ougi::Sin(0.12f), 0.1197122f);
	ftestf("Ougi::Sin", 1.12f, Ougi::Sin(1.12f), 0.9001004f);
	ftestf("Ougi::Sin", 2.36f, Ougi::Sin(2.36f), 0.7044107f);
	ftestf("Ougi::Sin", 3.55f, Ougi::Sin(3.55f), -0.3971481f);
	ftestf("Ougi::Sin", 4.89f, Ougi::Sin(4.89f), -0.9842685f);
	ftestf("Ougi::Sin", 13.45f, Ougi::Sin(13.45f), 0.7730462f);
	
	ftestf("Ougi::Cos", -7.89f, Ougi::Cos(-7.89f), -0.03601057f);
	ftestf("Ougi::Cos", -0.12f, Ougi::Cos(-0.12f), 0.9928086f);
	ftestf("Ougi::Cos", 0.12f, Ougi::Cos(0.12f), 0.9928086f);
	ftestf("Ougi::Cos", 1.12f, Ougi::Cos(1.12f), 0.4356824f);
	ftestf("Ougi::Cos", 2.36f, Ougi::Cos(2.36f), -0.7097925f);
	ftestf("Ougi::Cos", 3.55f, Ougi::Cos(3.55f), -0.9177545f);
	ftestf("Ougi::Cos", 4.89f, Ougi::Cos(4.89f), 0.1766786f);
	ftestf("Ougi::Cos", 13.45f, Ougi::Cos(13.45f), 0.6343496f);
	
	fftestf("Ougi::Pow", 3, 4, Ougi::Pow(3, 4), 81);
	fftestf("Ougi::Pow", 5.4f, 3, Ougi::Pow(5.4f, 3), 157.464f);
	fftestf("Ougi::Pow", 19.2f, -5, Ougi::Pow(19.2f, -5), 0.0000003832603f);
	
	std::cout << std::endl;
#endif
#ifdef BENCHMARK
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Functions - Benchmarking        -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	dbenchmarkd("std::sqrt", sqrt, 7346.123);
	fbenchmarkf("Ougi::Sqrt", Ougi::Sqrt, 7346.123f);
	// needs to be re-written to ModFloat.
	// fbenchmarkf("Ougi::NormalizeAngle", Ougi::NormalizeAngle, 0.81f);
	dbenchmarkd("std::sin", sin, 56.321f);
	fbenchmarkf("Ougi::Sin", Ougi::Sin, 56.321f);
	dbenchmarkd("std::cos", cos, 56.321f);
	fbenchmarkf("Ougi::Cos", Ougi::Cos, 56.321f);
	ddbenchmarkd("std::pow", pow, 342.6745f, 4.0f);
	fubenchmarkf("Ougi::Pow(float, unsigned int)", Ougi::Pow, 342.7645f, 4u);
	fibenchmarkf("Ougi::Pow(float, positive int)", Ougi::Pow, 342.7645f, 4);
	fibenchmarkf("Ougi::Pow(float, negative int)", Ougi::Pow, 342.7645f, -4);
	ubenchmarku("Ougi::Factorial", Ougi::Factorial, 8u);
	
	std::cout << std::endl;
#endif
	
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
	
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Matrix2x2              -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << Ougi::Matrix2x2(11.0f, 12.0f, 13.0f, 14.0f) << std::endl;
	std::cout << std::endl;
	
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Matrix3x3              -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << Ougi::Matrix3x3(15.0f, 16.0f, 17.0f, 18.0f, 19.0f, 20.0f, 21.0f, 22.0f, 23.0f) << std::endl;
	std::cout << std::endl;
	
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

#endif
}

int main(int argc, char* argv[])
{
	math();
	standard();
	return 0;
}