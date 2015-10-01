//--------------------------------------------------------------------------------
// SinglyLinkedList.h
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

//--------------------------------------------------------------------------------
// PROS:
//
// CONS:
//
//--------------------------------------------------------------------------------

#ifndef OUGI_COLLECTIONS_SINGLYLINKEDLIST_H
#define OUGI_COLLECTIONS_SINGLYLINKEDLIST_H

#include "../../Standard/include/Interfaces.h"

namespace Ougi
{
	template <typename T>
	class SinglyLinkedList : public Collection<T>
	{
	public:
		SinglyLinkedList();
		SinglyLinkedList(const SinglyLinkedList& other);
		SinglyLinkedList& operator=(const SinglyLinkedList& other);
		
		~SinglyLinkedList();
		
		virtual bool Add(const T& item) override;
		virtual bool AddAll(const Collection<T>& items) override;
		virtual void Clear() override;
		virtual bool Contains(const T& item) const override;
		virtual bool ContainsAll(const Collection<T>& items) const override;
		virtual bool IsEmpty() const override;
		virtual Iterator<T> GetIterator() const override;
		virtual bool Remove(const T& item) override;
		virtual bool RemoveAll(const Collection<T>& items) override;
		virtual bool RetainAll(const Collection<T>& items) override;
		virtual unsigned int Size() const override;
		virtual T* ToArray() const override;
	
	protected:
		T* first;
		unsigned int size;

		struct Node
		{
			T* item;
			T* next;
		};
		
		void InitFromOther(const SinglyLinkedList<T>& other);
	};
}

#endif