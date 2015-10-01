//--------------------------------------------------------------------------------
// SinglyLinkedList.cpp
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
//--------------------------------------------------------------------------------

#include "../include/SinglyLinkedList.h"

template <typename T>
Ougi::SinglyLinkedList<T>::SinglyLinkedList() :
first(0),
size(0)
{
}

template <typename T>
void Ougi::SinglyLinkedList<T>::InitFromOther(const Ougi::SinglyLinkedList<T>& other)
{
	Clear();
	Iterator<T> iterator = other.GetIterator();
	if (iterator.HasNext())
	{
		first = new Node;
		first.item = iterator.Next();
	}
	else
	{
		return;
	}
	Node* current = first;
	while (iterator.HasNext())
	{
		current.next = new Node;
		current.next.item = iterator.Next();
		current = current.next;
	}
	current.next = 0;
}

template <typename T>
Ougi::SinglyLinkedList<T>::SinglyLinkedList(const Ougi::SinglyLinkedList<T>& other)
{
	InitFromOther(other);
}

template <typename T>
Ougi::SinglyLinkedList<T>& Ougi::SinglyLinkedList<T>::operator=(const Ougi::SinglyLinkedList<T>& other)
{
	InitFromOther(other);
}

template <typename T>
Ougi::SinglyLinkedList<T>::~SinglyLinkedList()
{
	Clear();
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::Add(const T& item)
{
	Node* current = first;
	if (current == 0)
	{
		first = new Node;
		first.item = item;
		first.next = 0;
	}
	else
	{
		while (current.next != 0)
		{
			current = current.next;
		}
		current.next = new Node;
		current.next.item = item;
		current.next.next = 0;
	}
	return true;
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::AddAll(const Ougi::Collection<T>& items)
{
	Iterator<T> iterator = items.GetIterator();
	Node* current = first;
	if (current == 0)
	{
		if (iterator.HasNext())
		{
			first = new Node;
			first.item = iterator.Next();
			first.next = 0;
		}
	}
	while (iterator.HasNext())
	{
		current.next = new Node;
		current.next.item = iterator.Next();
		current = current.next;
	}
	current.next = 0;
	return true;
}

template <typename T>
void Ougi::SinglyLinkedList<T>::Clear()
{
	size = 0;
	Node* current = first;
	Node* previous;
	while (current != 0)
	{
		previous = current;
		current = current->Next();
		previous = 0;
		delete previous;
	}
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::Contains(const T& item) const
{
	Node* current = first;
	while (current != 0)
	{
		if (current.item == item)
		{
			return true;
		}
		current = current.next;
	}
	return false;
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::ContainsAll(const Ougi::Collection<T>& items) const
{
	bool containsAll = true;
	Iterator<T> iterator = items.GetIterator();
	while (containsAll && iterator.HasNext())
	{
		containsAll = Contains(iterator.Next());
	}
	return containsAll;
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::IsEmpty() const
{
	return size == 0;
}

// template <typename T>
// Ougi::Iterator<T> Ougi::SinglyLinkedList::GetIterator() const
// {
// 	// TODO
// }

template <typename T>
bool Ougi::SinglyLinkedList<T>::Remove(const T& item)
{
	// TODO
	return true;
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::RemoveAll(const Ougi::Collection<T>& items)
{
	// TODO
	return true;
}

template <typename T>
bool Ougi::SinglyLinkedList<T>::RetainAll(const Ougi::Collection<T>& items)
{
	// TODO
	return true;
}

template <typename T>
unsigned int Ougi::SinglyLinkedList<T>::Size() const
{
	return size;
}

template <typename T>
T* Ougi::SinglyLinkedList<T>::ToArray() const
{
	T tarray[size];
	Node* current = first;
	unsigned int i = 0;
	while (current != 0)
	{
		tarray[i] = current.item;
		i++;
	}
	return tarray;
}