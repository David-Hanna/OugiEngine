//-------------------------------------------------------------------------------------------
// Interfaces.h
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
//-------------------------------------------------------------------------------------------

#ifndef OUGI_STANDARD_INTERFACES_H
#define OUGI_STANDARD_INTERFACES_H

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
	};
	
	template<typename T>
	class Iterator
	{
	public:
		bool HasNext() const = 0;
		T& Next() = 0;
		const T& Next() const = 0;
		void Remove() = 0;
	};
	
	template<typename T>
	class Iterable
	{
		Iterator<T> Iterator() const = 0;
	};
	
	template<typename T>
	class Collection : public Iterable<T>
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
		T* ToArray() const = 0;
	};
}

#endif