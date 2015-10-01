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
	public:
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
		virtual bool HasNext() const = 0;
		virtual T& Next() = 0;
		virtual const T& Next() const = 0;
		virtual void Remove() = 0;
	};
	
	template<typename T>
	class Iterable
	{
	public:
		virtual Iterator<T> GetIterator() const = 0;
	};
	
	template<typename T>
	class Collection : public Iterable<T>
	{
	public:
		virtual bool Add(const T& item) = 0;
		virtual bool AddAll(const Collection<T>& items) = 0;
		virtual void Clear() = 0;
		virtual bool Contains(const T& item) const = 0;
		virtual bool ContainsAll(const Collection<T>& items) const = 0;
		virtual bool IsEmpty() const = 0;
		virtual Iterator<T> GetIterator() const = 0;
		virtual bool Remove(const T& item) = 0;
		virtual bool RemoveAll(const Collection<T>& items) = 0;
		virtual bool RetainAll(const Collection<T>& items) = 0;
		virtual unsigned int Size() const = 0;
		virtual T* ToArray() const = 0;
	};
}

#endif