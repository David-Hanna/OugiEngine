//--------------------------------------------------------------------------------
// MathTester.h
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

#include <iostream>
#include <cmath>
#include <limits>
#include <ctime>

#include "Functions.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Ougi
{
	class MathTester
	{
	public:
		static void Test();
		static void Benchmark();
		
	private:
		// Unit Testing
		static float FLOAT_TOLERANCE;
		
		static void ftestf(const char* name, float input, float val, float expected);
		static void fftestf(const char* name, float input1, float input2, float val, float expected);
		static void ftesti(const char* name, float input, float val, int expected);
	
		// Benchmarking
		static unsigned int TIMES;
		static std::clock_t start;
		static std::clock_t end;

		static double duration();
		
		static void fbenchmarkf(const char* name, float (*func)(float), float input);
		static void fbenchmarki(const char* name, int (*func)(float), float input);
		static void dbenchmarkd(const char* name, double (*func)(double), double input);
		static void ffbenchmarkf(const char* name, float (*func)(float, float), float input1, float input2);
		static void ddbenchmarkd(const char* name, double (*func)(double, double), double input1, double input2);
		static void fubenchmarkf(const char* name, float (*func)(float, unsigned int), float input1, unsigned int input2);
		static void fibenchmarkf(const char* name, float (*func)(float, int), float input1, int input2);
		static void ubenchmarku(const char* name, unsigned int (*func)(unsigned int), unsigned int input);
	};
}