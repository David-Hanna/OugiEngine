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

float Ougi::MathTester::FLOAT_TOLERANCE = 0.1f;
unsigned int Ougi::MathTester::TIMES = 10000000;
std::clock_t Ougi::MathTester::start = std::clock();
std::clock_t Ougi::MathTester::end = std::clock();

void Ougi::MathTester::Test()
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
	ftesti("Ougi::Floor", 45.678f, Ougi::Floor(45.678f), 45);
	ftesti("Ougi::Floor", -32.0f, Ougi::Floor(-32.0f), -32);
	ftesti("Ougi::Floor", -45.678f, Ougi::Floor(-45.678f), -46);
	
	ftesti("Ougi::Ceiling", 32.0f, Ougi::Ceiling(32.0f), 32);
	ftesti("Ougi::Ceiling", 45.678f, Ougi::Ceiling(45.678f), 46);
	ftesti("Ougi::Ceiling", -32.0f, Ougi::Ceiling(-32.0f), -32);
	ftesti("Ougi::Ceiling", -45.678f, Ougi::Ceiling(-45.678f), -45);
	
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
	
	fftestf("Ougi::Pow", 3, 4, Ougi::Pow(3, 4), 81);
	fftestf("Ougi::Pow", 5.4f, 3, Ougi::Pow(5.4f, 3), 157.464f);
	fftestf("Ougi::Pow", 19.2f, -5, Ougi::Pow(19.2f, -5), 0.00000038326f);
	
	std::cout << std::endl;
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
	fbenchmarkf("Ougi::abs", Ougi::Abs, 4.6f);
	
	fbenchmarkf("std::floor", std::floor, -3.2f);
	fbenchmarki("Ougi::floor", Ougi::Floor, -3.2f);
	
	fbenchmarkf("std::ceil", std::ceil, -3.2f);
	fbenchmarki("Ougi::Ceiling", Ougi::Ceiling, -3.2f);
	
	fffbenchmarkf("Ougi::ModFloat", Ougi::ModFloat, -6.78152f, 9.999f, 21.054f);
	
	dbenchmarkd("std::sin", std::sin, 56.321f);
	fbenchmarkf("Ougi::Sin", Ougi::Sin, 56.321f);
	
	dbenchmarkd("std::cos", std::cos, 56.321f);
	fbenchmarkf("Ougi::Cos", Ougi::Cos, 56.321f);
	
	dbenchmarkd("std::tan", std::tan, 56.321f);
	fbenchmarkf("Ougi::Tan", Ougi::Tan, 56.321f);
	
	dbenchmarkd("std::asin", std::asin, 0.321f);
	fbenchmarkf("Ougi::Arcsin", Ougi::Arcsin, 0.321f);
	
	dbenchmarkd("std::acos", std::acos, 0.321f);
	fbenchmarkf("Ougi::Arccos", Ougi::Arccos, 0.321f);
	
	dbenchmarkd("std::atan", std::atan, 56.321f);
	fbenchmarkf("Ougi::Arctan", Ougi::Arctan, 56.321f);
	
	ddbenchmarkd("std::pow", std::pow, 342.6745f, 4.0f);
	fubenchmarkf("Ougi::Pow(float, unsigned int)", Ougi::Pow, 342.7645f, 4u);
	fibenchmarkf("Ougi::Pow(float, positive int)", Ougi::Pow, 342.7645f, 4);
	fibenchmarkf("Ougi::Pow(float, negative int)", Ougi::Pow, 342.7645f, -4);
	
	ubenchmarku("Ougi::Factorial", Ougi::Factorial, 8u);
	
	std::cout << std::endl;
}

void Ougi::MathTester::ftestf(const char* name, float input, float val, float expected)
{
	std::cout << name << "(" << input << "): " << val << " ~= " << expected << ", ";
	if (Ougi::Abs(val - expected) < FLOAT_TOLERANCE) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void Ougi::MathTester::fftestf(const char* name, float input1, float input2, float val, float expected)
{
	std::cout << name << "(" << input1 << ", " << input2 << "): " << val << " ~= " << expected << ", ";
	if (Ougi::Abs(val - expected) < FLOAT_TOLERANCE) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void Ougi::MathTester::ffftestf(const char* name, float input1, float input2, float input3, float val, float expected)
{
	std::cout << name << "(" << input1 << ", " << input2 << ", " << input3 << "): " << val << " ~= " << expected << ", ";
	if (Ougi::Abs(val - expected) < FLOAT_TOLERANCE) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void Ougi::MathTester::ftesti(const char* name, float input, float val, int expected)
{
	std::cout << name << "(" << input << "): " << val << " == " << expected << ", ";
	if (val == expected) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

double Ougi::MathTester::duration()
{
	return (((end - start) / ((double) CLOCKS_PER_SEC)) * 1000);
}

void Ougi::MathTester::fbenchmarkf(const char* name, float (*func)(float), float input)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fffbenchmarkf(const char* name, float (*func)(float, float, float), float input1, float input2, float input3)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2, input3);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fbenchmarki(const char* name, int (*func)(float), float input)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::dbenchmarkd(const char* name, double (*func)(double), double input)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::ffbenchmarkf(const char* name, float (*func)(float, float), float input1, float input2)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::ddbenchmarkd(const char* name, double (*func)(double, double), double input1, double input2)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fubenchmarkf(const char* name, float (*func)(float, unsigned int), float input1, unsigned int input2)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::fibenchmarkf(const char* name, float (*func)(float, int), float input1, int input2)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}

void Ougi::MathTester::ubenchmarku(const char* name, unsigned int (*func)(unsigned int), unsigned int input)
{
	start = std::clock();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	end = std::clock();
	std::cout << name << ": " << duration() << std::endl;
}