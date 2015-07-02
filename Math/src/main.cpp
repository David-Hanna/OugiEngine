#include <iostream>

#include "../include/Functions.h"
#include "../include/Vector2.h"
#include "../include/Vector3.h"
#include "../include/Vector4.h"
#include "../include/Matrix2x2.h"
#include "../include/Matrix3x3.h"
#include "../include/Matrix4x4.h"

int main(int argc, char* argv[])
{
	//=======================
	// Functions
	//=======================
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-                  Functions              -" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Square root of 2 is: " << Ougi::sqrt(2.0f) << std::endl;
	std::cout << "Inverse square root of 2 is: " << Ougi::invsqrt(2.0f) << std::endl;
	std::cout << "Absolute value of 5 is: " << Ougi::abs(5) << std::endl;
	std::cout << "Absolute value of -5 is: " << Ougi::abs(-5) << std::endl;
	std::cout << "Absolute value of 4.6 is: " << Ougi::abs(4.6f) << std::endl;
	std::cout << "Absolute value of -4.6 is: " << Ougi::abs(-4.6f) << std::endl;
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
	std::cout << "a.equals(b, 50.0f): " << (a.equals(b, 50.0f)) << std::endl;
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
	std::cout << "c.equals(d, 50.0f): " << (c.equals(d, 50.0f)) << std::endl;
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
	std::cout << "e.equals(f, 50.0f): " << (e.equals(f, 50.0f)) << std::endl;
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
}