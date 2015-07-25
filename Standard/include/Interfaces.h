#ifndef OUGI_STANDARD_INTERFACES_H
#define OUGI_STANDARD_INTERFACES_H

//-------------------------------------------------------------------------------------------
// Interfaces
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	template<typename T>
	class Comparable
	{
		virtual bool operator==(const T& rhs) const = 0;
		bool operator!=(const T& rhs) const { return !operator==(rhs); }
		virtual bool operator<(const T& rhs) const = 0;
		bool operator>(const T& rhs) const { return rhs < (*this); }
		bool operator<=(const T& rhs) const { return !operator>(rhs); }
		bool operator>=(const T& rhs) const { return !operator<(rhs); }
	}
	
	template<typename T>
	class Iterator
	{
	public:
		bool HasNext() const = 0;
		T& Next() = 0;
		const T& Next() const = 0;
		void Remove() = 0;
	}
	
	template<typename T>
	class Iterable
	{
		Iterator<T> Iterator() const = 0;
	}
	
	template<typename T>
	class Collection : public Iterable
	{
		bool Add(T item) = 0;
		bool AddAll(Collection<T> items) = 0;
		void Clear() = 0;
		bool Contains(T item) const = 0;
		bool ContainsAll(Collection<T> items) const = 0;
		bool IsEmpty() const = 0;
		Iterator<T> Iterator() const = 0;
		bool Remove(T item) = 0;
		bool RemoveAll(Collection<T> items) = 0;
		bool RetainAll(Collection<T> items) = 0;
		unsigned int Size() const = 0;
		T[] ToArray() const = 0;
	} 
}

#endif