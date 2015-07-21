#ifndef OUGI_COMPARABLE_H
#define OUGI_COMPARABLE_H

//-------------------------------------------------------------------------------------------
// Comparable
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	template<typename T>
	class Comparable
	{
		float operator==(const T& rhs) const = 0;
		float Equals(const T& rhs) const = 0;
	}
}

#endif