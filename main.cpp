#define UNIT_TEST
//#define BENCHMARK

#define MATH
#define STANDARD

#ifdef MATH
#include "Math/include/MathTester.h"
#endif

#ifdef STANDARD
#endif

int main(int argc, char* argv[])
{
#ifdef UNIT_TEST
	Ougi::MathTester::Test();
#endif

#ifdef BENCHMARK
	Ougi::MathTester::Benchmark();
#endif
	return 0;
}