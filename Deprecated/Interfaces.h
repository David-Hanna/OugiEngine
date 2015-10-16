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
	 
	// A generic form of collection which simply stores items
	// without assuming anything about either the key to access
	// that item, or the item's type. Such a collection means items
	// cannot be compared to each other and the order is arbitrary.
	// i.e. hash-tables, heaps, etc.
	template<typename KeyType, typename ItemType>
	class Collection : public Iterable<ItemType>
	{
	public:
		virtual ItemType& operator[](const KeyType& key) = 0;
	
		virtual bool Add(const ItemType& item) = 0;
		virtual bool Insert(const KeyType& index, const ItemType& item) = 0;
		virtual bool Remove(const KeyType& key) = 0;
		
		virtual void Clear() = 0;
		virtual bool IsEmpty() const = 0;
		virtual bool ContainsKey(const KeyType& key) const = 0;
		
		virtual Iterator<ItemType> GetIterator() const = 0;
		
		virtual unsigned int Size() const = 0;
		virtual ItemType* ToArray() const = 0;
	};
	
	
	// A form of collection in which items are comparable, leading to the
	// ability to remove by value, check if the collection contains a value,
	// sort the collection, and do fast searches.
	// i.e. indexed-lists, sorted binary trees, etc.
	template <typename ItemType>
	class OrderableCollection : public Collection<unsigned int, Comparable<ItemType>>
	{
		virtual bool RemoveItem(const Comparable<ItemType>& item) = 0;
		virtual bool Contains(const Comparable<ItemType>& item) const = 0;
		
		virtual void Sort() = 0;
	};
	
	template <typename ItemType>
	void Sort(Collection<ItemType>, int (*compareFunction)(ItemType a, ItemType b));
	
	template <typename ItemType>
	void Search(Collection<ItemType>, int (*compareFunction)(ItemType a, ItemType b));
}

#endif