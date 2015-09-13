const float FLOAT_TOLERANCE = 0.1f;

float absoluteValue(float arg)
{
	return arg > 0.0f ? arg : -arg;
}

void ftestf(const char* name, float input, float val, float expected)
{
	std::cout << name << "(" << input << "): " << val << " ~= " << expected << ", ";
	if (absoluteValue(val - expected) < FLOAT_TOLERANCE) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void fftestf(const char* name, float input1, float input2, float val, float expected)
{
	std::cout << name << "(" << input1 << ", " << input2 << "): " << val << " ~= " << expected << ", ";
	if (absoluteValue(val - expected) < FLOAT_TOLERANCE) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}

void ftesti(const char* name, float input, float val, int expected)
{
	std::cout << name << "(" << input << "): " << val << " == " << expected << ", ";
	if (val == expected) std::cout << "PASS";
	else std::cout << "====== ALERT: UNIT TEST FAILED ======";
	std::cout << std::endl;
}