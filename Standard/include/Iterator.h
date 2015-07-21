#ifndef OUGI_STANDARD_ITERATOR_H
#define OUGI_STANDARD_ITERATOR_H

//-------------------------------------------------------------------------------------------
// Iterator
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	template<typename T>
	class Iterator
	{
		bool HasNext() const = 0;
		T Next() = 0;
		void Remove() = 0;
	}
}

#endif