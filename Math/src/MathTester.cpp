//--------------------------------------------------------------------------------
// MathTester.cpp
// Author: David Hanna
// Copyright (C) 20xx David Hanna, Inc.
//
// This file is part of Ougi Engine.
//
// Ougi Engine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Ougi Engine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Ougi Engine.  If not, see <http://www.gnu.org/licenses/>.
//--------------------------------------------------------------------------------

#include "../include/MathTester.h"

std::string Ougi::MathTester::PASS_STRING = "PASS";
std::string Ougi::MathTester::FAIL_STRING = "====== ALERT - UNIT TEST FAILED ======";
float Ougi::MathTester::FLOAT_TOLERANCE = 0.07f; // tolerance of floating point errors to FLOAT_TOLERANCE% of expected value.
unsigned int Ougi::MathTester::TIMES = 10000000;
std::clock_t Ougi::MathTester::start = std::clock();
std::clock_t Ougi::MathTester::end = std::clock();

void Ougi::MathTester::Test()
{
	ConstantsTest();
	FunctionTest();
	Vector2Test();
	Vector3Test();
	Vector4Test();
	Matrix2x2Test();
	Matrix3x3Test();
	Matrix4x4Test();
}

void Ougi::MathTester::Benchmark()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Functions - Benchmarking        -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	dbenchmarkd("std::sqrt", std::sqrt, 7346.123);
	fbenchmarkf("Ougi::Sqrt", Ougi::Sqrt, 7346.123f);
	
	fbenchmarkf("std::abs", std::abs, 4.6f);
	fbenchmarkf("Ougi::Abs", Ougi::Abs, 4.6f);
	
	fbenchmarkf("std::floor", std::floor, -3.2f);
	fbenchmarki("Ougi::Floor", Ougi::Floor, -3.2f);
	
	fbenchmarkf("std::ceil", std::ceil, -3.2f);
	fbenchmarki("Ougi::Ceiling", Ougi::Ceiling, -3.2f);
	
	fffbenchmarkf("Ougi::ModFloat", Ougi::ModFloat, -6.78152f, 9.999f, 21.054f);
	
	fbenchmarkf("std::sin", std::sin, 56.321f);
	fbenchmarkf("Ougi::Sin", Ougi::Sin, 56.321f);
	
	fbenchmarkf("std::cos", std::cos, 56.321f);
	fbenchmarkf("Ougi::Cos", Ougi::Cos, 56.321f);
	
	fbenchmarkf("std::tan", std::tan, 56.321f);
	fbenchmarkf("Ougi::Tan", Ougi::Tan, 56.321f);
	
	fbenchmarkf("std::asin", std::asin, 0.321f);
	fbenchmarkf("Ougi::Arcsin", Ougi::Arcsin, 0.321f);
	
	fbenchmarkf("std::acos", std::acos, 0.321f);
	fbenchmarkf("Ougi::Arccos", Ougi::Arccos, 0.321f);
	
	fbenchmarkf("std::atan", std::atan, 56.321f);
	fbenchmarkf("Ougi::Arctan", Ougi::Arctan, 56.321f);
	
	fbenchmarkf("std::Exp", std::exp, 56.321f);
	fbenchmarkf("Ougi::Exp", Ougi::Exp, 56.321f);
	
	fbenchmarkf("std::log", std::log, 32.1534f);
	fbenchmarkf("Ougi::Ln", Ougi::Ln, 32.1534f);
	
	ffbenchmarkf("std::pow", std::pow, 342.6745f, 4.0f);
	fubenchmarkf("Ougi::Pow(float, unsigned int)", Ougi::Pow, 342.7645f, 4u);
	fibenchmarkf("Ougi::Pow(float, positive int)", Ougi::Pow, 342.7645f, 4);
	fibenchmarkf("Ougi::Pow(float, negative int)", Ougi::Pow, 342.7645f, -4);
	
	ubenchmarku("Ougi::Factorial", Ougi::Factorial, 8u);
	
	std::cout << std::endl;
}

void Ougi::MathTester::ftestf(const char* name, float input, float val, float expected)
{
	std::cout << name << "(" << input << "): " << val << " ~= " << expected << ", ";
	if (expected == 0.0f && Ougi::Abs(val - expected) < FLOAT_TOLERANCE) std::cout << PASS_STRING;
	else if (Ougi::Abs(val - expected) / expected < FLOAT_TOLERANCE) std::cout << PASS_STRING;
	else std::cout << FAIL_STRING;
	std::cout << std::endl;
}

void Ougi::MathTester::fftestf(const char* name, float input1, float input2, float val, float expected)
{
	std::cout << name << "(" << input1 << ", " << input2 << "): " << val << " ~= " << expected << ", ";
	if (expected == 0.0f && Ougi::Abs(val - expected) < FLOAT_TOLERANCE) std::cout << PASS_STRING;
	else if (Ougi::Abs(val - expected) / expected < FLOAT_TOLERANCE) std::cout << PASS_STRING;
	else std::cout << FAIL_STRING;
	std::cout << std::endl;
}

void Ougi::MathTester::ffftestf(const char* name, float input1, float input2, float input3, float val, float expected)
{
	std::cout << name << "(" << input1 << ", " << input2 << ", " << input3 << "): " << val << " ~= " << expected << ", ";
	if (expected == 0.0f && Ougi::Abs(val - expected) < FLOAT_TOLERANCE) std::cout << PASS_STRING;
	else if (Ougi::Abs(val - expected) / expected < FLOAT_TOLERANCE) std::cout << PASS_STRING;
	else std::cout << FAIL_STRING;
	std::cout << std::endl;
}

void Ougi::MathTester::ftesti(const char* name, float input, float val, int expected)
{
	std::cout << name << "(" << input << "): " << val << " == " << expected << ", ";
	if (val == expected) std::cout << PASS_STRING;
	else std::cout << FAIL_STRING;
	std::cout << std::endl;
}

double Ougi::MathTester::duration()
{
	return (((end - start) / ((double) CLOCKS_PER_SEC)) * 1000);
}

void Ougi::MathTester::fbenchmarkf(const char* name, float (*func)(float), float input)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fffbenchmarkf(const char* name, float (*func)(float, float, float), float input1, float input2, float input3)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2, input3);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fbenchmarki(const char* name, int (*func)(float), float input)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::dbenchmarkd(const char* name, double (*func)(double), double input)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::ffbenchmarkf(const char* name, float (*func)(float, float), float input1, float input2)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::ddbenchmarkd(const char* name, double (*func)(double, double), double input1, double input2)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fubenchmarkf(const char* name, float (*func)(float, unsigned int), float input1, unsigned int input2)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fibenchmarkf(const char* name, float (*func)(float, int), float input1, int input2)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::ubenchmarku(const char* name, unsigned int (*func)(unsigned int), unsigned int input)
{
	start = std::clock();
	for (unsigned int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::PrintPassOrFail(bool expression)
{
	if (expression) std::cout << " " << PASS_STRING << std::endl;
	else std::cout << " " << FAIL_STRING << std::endl;
}

void Ougi::MathTester::ConstantsTest()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                Constants                -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "E: " << Ougi::E << std::endl;
	std::cout << "QUARTER_PI: " << Ougi::QUARTER_PI << std::endl;
	std::cout << "HALF_PI: " << Ougi::HALF_PI << std::endl;
	std::cout << "PI: " << Ougi::PI << std::endl;
	std::cout << "THREE_HALVES_PI: " << Ougi::THREE_HALVES_PI << std::endl;
	std::cout << "TWO_PI: " << Ougi::TWO_PI << std::endl;
	std::cout << "PI_SQUARED: " << Ougi::PI_SQUARED << std::endl;
	std::cout << "DEG2RAD: " << Ougi::DEG2RAD << std::endl;
	std::cout << "RAD2DEG: " << Ougi::RAD2DEG << std::endl;
	std::cout << std::endl;
}

void Ougi::MathTester::FunctionTest()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Functions - Unit Tests          -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	ftestf("Ougi::Sqrt", 0.0f, Ougi::Sqrt(0.0f), 0.0f);
	ftestf("Ougi::Sqrt", 2.0f, Ougi::Sqrt(2.0f), 1.41386f);
	ftestf("Ougi::Sqrt", 5.14f, Ougi::Sqrt(5.14f), 2.26644f);
	
	ftestf("Ougi::Abs", 5, Ougi::Abs(5), 5);
	ftestf("Ougi::Abs", -5, Ougi::Abs(-5), 5);
	ftestf("Ougi::Abs", 4.6f, Ougi::Abs(4.6f), 4.6f);
	ftestf("Ougi::Abs", -4.6f, Ougi::Abs(-4.6f), 4.6f);
	
	ftesti("Ougi::Floor", 32.0f, Ougi::Floor(32.0f), 32);
	ftesti("Ougi::Floor", 92.1f, Ougi::Floor(92.1f), 92);
	ftesti("Ougi::Floor", 45.678f, Ougi::Floor(45.678f), 45);
	ftesti("Ougi::Floor", -32.0f, Ougi::Floor(-32.0f), -32);
	ftesti("Ougi::Floor", -92.1f, Ougi::Floor(-92.1f), -93);
	ftesti("Ougi::Floor", -45.678f, Ougi::Floor(-45.678f), -46);
	
	ftesti("Ougi::Ceiling", 32.0f, Ougi::Ceiling(32.0f), 32);
	ftesti("Ougi::Ceiling", 92.1f, Ougi::Ceiling(92.1f), 93);
	ftesti("Ougi::Ceiling", 45.678f, Ougi::Ceiling(45.678f), 46);
	ftesti("Ougi::Ceiling", -32.0f, Ougi::Ceiling(-32.0f), -32);
	ftesti("Ougi::Ceiling", -92.1f, Ougi::Ceiling(-92.1f), -92);
	ftesti("Ougi::Ceiling", -45.678f, Ougi::Ceiling(-45.678f), -45);
	
	ftesti("Ougi::Round", 32.0f, Ougi::Round(32.0f), 32);
	ftesti("Ougi::Round", 92.1f, Ougi::Round(92.1f), 92);
	ftesti("Ougi::Round", 45.678f, Ougi::Round(45.678f), 46);
	ftesti("Ougi::Round", -32.0f, Ougi::Round(-32.0f), -32);
	ftesti("Ougi::Round", -92.1f, Ougi::Round(-92.1f), -92);
	ftesti("Ougi::Round", -45.678f, Ougi::Round(-45.678f), -46);
	
	ffftestf("Ougi::ModFloat", 42.0f, 0.0f, 8.0f, Ougi::ModFloat(42.0f, 0.0f, 8.0f), 2.0f);
	ffftestf("Ougi::ModFloat", 43.567f, 2.45, 5.67, Ougi::ModFloat(43.567f, 2.45, 5.67), 4.927f);
	ffftestf("Ougi::ModFloat", -3.67f, -4.56f, -2.1f, Ougi::ModFloat(-3.67f, -4.56f, -2.1f), -3.67f);
	ffftestf("Ougi::ModFloat", 5.6f, 5.6f, 34.0f, Ougi::ModFloat(5.6f, 5.6f, 34.0f), 5.6f);
	
	ftestf("Ougi::Sin", -7.89f, Ougi::Sin(-7.89f), -0.999351f);
	ftestf("Ougi::Sin", -0.12f, Ougi::Sin(-0.12f), -0.119712f);
	ftestf("Ougi::Sin", 0.12f, Ougi::Sin(0.12f), 0.119712f);
	ftestf("Ougi::Sin", 1.12f, Ougi::Sin(1.12f), 0.900100f);
	ftestf("Ougi::Sin", 2.36f, Ougi::Sin(2.36f), 0.704411f);
	ftestf("Ougi::Sin", 3.55f, Ougi::Sin(3.55f), -0.397148f);
	ftestf("Ougi::Sin", 4.89f, Ougi::Sin(4.89f), -0.984269f);
	ftestf("Ougi::Sin", 13.45f, Ougi::Sin(13.45f), 0.773046f);
	
	ftestf("Ougi::Cos", -7.89f, Ougi::Cos(-7.89f), -0.0360106f);
	ftestf("Ougi::Cos", -0.12f, Ougi::Cos(-0.12f), 0.992809f);
	ftestf("Ougi::Cos", 0.12f, Ougi::Cos(0.12f), 0.992809f);
	ftestf("Ougi::Cos", 1.12f, Ougi::Cos(1.12f), 0.435682f);
	ftestf("Ougi::Cos", 2.36f, Ougi::Cos(2.36f), -0.709793f);
	ftestf("Ougi::Cos", 3.55f, Ougi::Cos(3.55f), -0.917755f);
	ftestf("Ougi::Cos", 4.89f, Ougi::Cos(4.89f), 0.176679f);
	ftestf("Ougi::Cos", 13.45f, Ougi::Cos(13.45f), 0.63435f);
	
	ftestf("Ougi::Tan", -7.89f, Ougi::Tan(-7.89f), 27.7516f);
	ftestf("Ougi::Tan", -0.12f, Ougi::Tan(-0.12f), -0.120579f);
	ftestf("Ougi::Tan", 0.12f, Ougi::Tan(0.12f), 0.120579f);
	ftestf("Ougi::Tan", 1.12f, Ougi::Tan(1.12f), 2.06595f);
	ftestf("Ougi::Tan", 2.36f, Ougi::Tan(2.36f), -0.992417f);
	ftestf("Ougi::Tan", 3.55f, Ougi::Tan(3.55f), 0.432739f);
	ftestf("Ougi::Tan", 4.89f, Ougi::Tan(4.89f), -5.57095f);
	ftestf("Ougi::Tan", 13.45f, Ougi::Tan(13.45f), 1.21864f);
	
	ftestf("Ougi::Arcsin", -1.0f, Ougi::Arcsin(-1.0f), -1.57079f);
	ftestf("Ougi::Arcsin", -0.67f, Ougi::Arcsin(-0.67f), -0.734208f);
	ftestf("Ougi::Arcsin", -0.12f, Ougi::Arcsin(-0.12f), -0.120289f);
	ftestf("Ougi::Arcsin", 0.12f, Ougi::Arcsin(0.12f), 0.120289f);
	ftestf("Ougi::Arcsin", 0.35f, Ougi::Arcsin(0.35f), 0.357571f);
	ftestf("Ougi::Arcsin", 1.0f, Ougi::Arcsin(1.0f), 1.57079f);
	
	ftestf("Ougi::Arccos", 0.12f, Ougi::Arccos(0.12f), 1.45051f);
	ftestf("Ougi::Arccos", 0.35f, Ougi::Arccos(0.35f), 1.21322f);
	ftestf("Ougi::Arccos", 1.0f, Ougi::Arccos(1.0f), 0.0f);
	
	ftestf("Ougi::Arctan", -7.89f, Ougi::Arctan(-7.89f), -1.44472f);
	ftestf("Ougi::Arctan", -0.12f, Ougi::Arctan(-0.12f), -0.119428f);
	ftestf("Ougi::Arctan", 0.12f, Ougi::Arctan(0.12f), 0.119428f);
	ftestf("Ougi::Arctan", 1.12f, Ougi::Arctan(1.12f), 0.841941f);
	ftestf("Ougi::Arctan", 2.36f, Ougi::Arctan(2.36f), 1.17f);
	ftestf("Ougi::Arctan", 3.55f, Ougi::Arctan(3.55f), 1.29622f);
	ftestf("Ougi::Arctan", 4.89f, Ougi::Arctan(4.89f), 1.36907f);
	ftestf("Ougi::Arctan", 13.45f, Ougi::Arctan(13.45f), 1.49658f);
	
	ftestf("Ougi::Ln", 1.0f, Ougi::Ln(1.0f), 0.0f);
	ftestf("Ougi::Ln", 13.4f, Ougi::Ln(13.4f), 2.59525f);
	ftestf("Ougi::Ln", 5.8f, Ougi::Ln(5.8f), 1.75785f);
	ftestf("Ougi::Ln", 34.2f, Ougi::Ln(34.2f), 3.53222f);
	
	ftestf("Ougi::Log2", 1.0f, Ougi::Log2(1.0f), 0.0f);
	ftestf("Ougi::Log2", 13.4f, Ougi::Log2(13.4f), 1.1271f);
	ftestf("Ougi::Log2", 5.8f, Ougi::Log2(5.8f), 0.763427f);
	ftestf("Ougi::Log2", 34.2f, Ougi::Log2(34.2f), 1.53403f);
	
	ftestf("Ougi::Log10", 1.0f, Ougi::Log10(1.0f), 0.0f);
	ftestf("Ougi::Log10", 13.4f, Ougi::Log10(13.4f), 1.1271f);
	ftestf("Ougi::Log10", 5.8f, Ougi::Log10(5.8f), 0.763427f);
	ftestf("Ougi::Log10", 34.2f, Ougi::Log10(34.2f), 1.53403f);
	
	ftestf("Ougi::Exp", 4, Ougi::Exp(4), 54.5982f);
	ftestf("Ougi::Exp", 3, Ougi::Exp(3u), 20.0855f);
	ftestf("Ougi::Exp", -5, Ougi::Exp(-5), 0.00673795f);
	ftestf("Ougi::Exp", -6.1f, Ougi::Exp(-6.1f), 0.00224286f);
	ftestf("Ougi::Exp", 3.2f, Ougi::Exp(3.2f), 24.5325f);
	
	fftestf("Ougi::Pow", 3, 4, Ougi::Pow(3, 4), 81);
	fftestf("Ougi::Pow", 5.4f, 3, Ougi::Pow(5.4f, 3u), 157.464f);
	fftestf("Ougi::Pow", 19.2f, -5, Ougi::Pow(19.2f, -5), 0.00000038326f);
	fftestf("Ougi::Pow", 7.4f, 3.2f, Ougi::Pow(7.4f, 3.2f), 604.702f);
	
	std::cout << std::endl;
}

void Ougi::MathTester::Vector2Test()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-         Vector 2 - Unit Tests           -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	Ougi::Vector2 a;
	std::cout << "Default Constructor: " << a << " == (0, 0)";
	PrintPassOrFail(a.x == 0.0f && a.y == 0.0f);
	
	Ougi::Vector2 b(3.4f, -28.1f);
	std::cout << "Custom Constructor: " << b << " == (3.4, -28.1)";
	PrintPassOrFail(b.x == 3.4f && b.y == -28.1f);
	
	a = b;
	std::cout << "Assignment Operator: " << a << " = " << b;
	PrintPassOrFail(a.x == b.x && a.y == b.y);
	
	a = -a;
	std::cout << "Unary Negative Operator: " << a << " == (-3.4, 28.1)";
	PrintPassOrFail(a.x == -3.4f && a.y == 28.1f);
	
	a = a + b;
	std::cout << "Addition Operator: " << a << " == (0, 0)";
	PrintPassOrFail(a.x == 0.0f && a.y == 0.0f);
	
	a = a - b;
	std::cout << "Subtraction Operator: " << a << " == (-3.4, 28.1)";
	PrintPassOrFail(a.x == -3.4f && a.y == 28.1f);
	
	float dot = a * b;
	std::cout << "Vector Multiplication (Dot Product): " << dot << " == -801.17";
	PrintPassOrFail( (Abs(dot + 801.17f) / dot) < FLOAT_TOLERANCE );
	
	a = a * 3.14f;
	std::cout << "Scalar-Vector Multiplication: " << a << " == (-10.676, 88.234)";
	PrintPassOrFail( (Abs(a.x + 10.676f) / a.x) < FLOAT_TOLERANCE && (Abs(a.y - 88.234f) / a.y) < FLOAT_TOLERANCE );
	
	a = a / 3.14f;
	std::cout << "Scalar-Vector Division: " << a << " == (-3.4, 28.1)";
	PrintPassOrFail( (Abs(a.x + -3.4f) / a.x) < FLOAT_TOLERANCE && (Abs(a.y - 28.1f) / a.y) < FLOAT_TOLERANCE );
	
	a += b;
	std::cout << "Addition-Assignment Operator: " << a << " == (0.0, 0.0)";
	PrintPassOrFail( Abs(a.x) < FLOAT_TOLERANCE && Abs(a.y) < FLOAT_TOLERANCE );
	
	a -= b;
	std::cout << "Subtraction-Assignment Operator: " << a << " == (-3.4, 28.1)";
	PrintPassOrFail( (Abs(a.x + -3.4f) / a.x) < FLOAT_TOLERANCE && (Abs(a.y - 28.1f) / a.y) < FLOAT_TOLERANCE );
	
	a *= 3.14f;
	std::cout << "Scalar-Multiplication-Assignment Operator: " << a << " == (-10.676, 88.234)";
	PrintPassOrFail( (Abs(a.x + 10.676f) / a.x) < FLOAT_TOLERANCE && (Abs(a.y - 88.234f) / a.y) < FLOAT_TOLERANCE );
	
	a /= 3.14f;
	std::cout << "Scalar-Division-Assignment Operator: " << a << " == (-3.4, 28.1)";
	PrintPassOrFail( (Abs(a.x + -3.4f) / a.x) < FLOAT_TOLERANCE && (Abs(a.y - 28.1f) / a.y) < FLOAT_TOLERANCE );
	
	std::cout << "Equality Operator: " << (a == a) << " == 1, and " << (a == Vector2(3.14f, 2.71828f)) << " == 0, and "
			  << (a == b) << " == 0";
	PrintPassOrFail(a == a && !(a == Vector2(3.14f, 2.71828f)) && !(a == b));
	
	std::cout << std::endl;
}

void Ougi::MathTester::Vector3Test()
{
	
}

void Ougi::MathTester::Vector4Test()
{
	
}

void Ougi::MathTester::Matrix2x2Test()
{
	
}

void Ougi::MathTester::Matrix3x3Test()
{
	
}

void Ougi::MathTester::Matrix4x4Test()
{
	
}