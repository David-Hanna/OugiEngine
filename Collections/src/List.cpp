#include "../include/List.h"

Ougi::List::List() :
first(0),
last(0),
size(0)
{
}

Ougi::List::List(const List& rhs) :
{
	// TODO
}

Ougi::List::~List()
{
	Clear();
}

Ougi::List& Ougi::List::operator=(const List& rhs)
{
	if (this != &rhs)
	{
		Clear();
	}
	return *this;
}

T Ougi::List::operator[](const unsigned int index)
{
	Node* traveller = first;
	for (unsigned int i = 0; i < index; ++i)
	{
		traveller = traveller->next;
	}
	return (*traveller);
}

const T Ougi::List::operator[](const unsigned int index) const
{
	// TODO: one version of this function calls the other... which?
}

bool Ougi::List::Add(T item)
{
	Node* traveller = handle;
	for (unsigned int i = 0; i < size; ++i)
	{
		traveller = traveller->next;
	}
	traveller->next = new Node;
	traveller->next->data = item;
}

T Ougi::List::GetFromFirst(const unsigned int index)
{
	Node* traveller = first;
	for (unsigned int i = 0; i < index; ++i)
	{
		traveller = traveller->next;
	}
	return (*traveller);
}

const T Ougi::List::GetFromFirst(const unsigned int index) const
{
	// TODO: one version of this function calls the other... which?
}