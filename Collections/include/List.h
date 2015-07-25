#ifndef OUGI_COLLECTIONS_LIST_H
#define OUGI_COLLECTIONS_LIST_H

//-------------------------------------------------------------------------------------------
// Linked List
//-------------------------------------------------------------------------------------------
s
#include "../Standard/include/Interfaces.h"

namespace Ougi
{
	template<typename T>
	class List : public Collection
	{
	public:
		List();
		List(const List& rhs);
		virtual ~List();
		
		List& operator=(const List& rhs);
		T& operator[](const unsigned int index);
		const T& operator[](const unsigned int index) const;
	
		bool Add(T item);
		bool AddAll(Collection<T> items);
		void Clear();
		bool Contains(T item) const;
		bool ContainsAll(Collection<T> items) const;
		T& First();
		const T& First() const;
		bool IsEmpty() const;
		Iterator<T> Iterator();
		const Iterator<T> Iterator() const;
		T& Last();
		const T& Last() const;
		bool Remove(T item);
		bool RemoveAll(Collection<T> items);
		bool RetainAll(Collection<T> items);
		unsigned int Size() const;
		T[] ToArray() const;
	
	protected:
		class Node
		{
		public:
			Node() {}
			Node(const Node& rhs); // not implemented
			~Node() { delete data; data = 0; }
			Node& operator=(const Node& rhs); // not implemented
		
			T data;
			Node* next;
		}
		
		class ListIterator : public Iterator<T>
		{
		public:
			explicit ListIterator(List* _list): list(_list) {}
			ListIterator(const ListIterator& rhs); // not implemented
			~ListIterator() {}
			ListIterator& operator=(const ListIterator& rhs); // not implemented
		
			bool HasNext() const;
			T& Next();
			const T& Next() const;
			void Remove();
			
		private:
			List* list;
		}
		
		Node* first;
		Node* last;
		unsigned int size;
		
		T GetFromFirst(const unsigned int index);
		const T GetFromFirst(const unsigned int index) const;
		T GetFromLast(const unsigned int index);
		const T GetFromLast(const unsigned int index) const;
	};
}

#endif