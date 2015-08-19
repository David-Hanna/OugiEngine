#include <ctime>

const int TIMES = 10000000;
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

void fbenchmarkf(const char* name, float (*func)(float), float input)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}

void dbenchmarkd(const char* name, double (*func)(double), double input)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}

void ffbenchmarkf(const char* name, float (*func)(float, float), float input1, float input2)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}

void ddbenchmarkd(const char* name, double (*func)(double, double), double input1, double input2)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}

void fubenchmarkf(const char* name, float (*func)(float, unsigned int), float input1, unsigned int input2)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}

void fibenchmarkf(const char* name, float (*func)(float, int), float input1, int input2)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input1, input2);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}

void ubenchmarku(const char* name, unsigned int (*func)(unsigned int), unsigned int input)
{
	begin();
	for (int i = 0; i < TIMES; ++i)
	{
		(*func)(input);
	}
	stop();
	std::cout << name << ": " << duration() << std::endl;
}