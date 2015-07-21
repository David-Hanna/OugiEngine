#ifndef OUGI_LIST_H
#define OUGI_LIST_H

//-------------------------------------------------------------------------------------------
// Linked List
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	template<typename T>
	class List
	{
	public:
		List();
		~List();
		
	public:
		class Iterator
		{
		public:
			Iterator();
			~Iterator();
			
			T operator*();
			T operator->();
			T operator++();
			T operator+(const unsigned int index);
			T operator+=(const unsigned int index);
			
		private:
			T* contents;
		};
		
	private:
		class Node
		{
		public:
			Node(_data, _next);
		
		public:
			T* data;
			Node* next;
		};
	};
}

#endif