#include "../include/String.h"

Ougi::String::String() 
{
	InitToEmpty();
}

Ougi::String::String(const char c) 
{
	InitFromChar(c);
}

Ougi::String::String(const char cstring[]) 
{
	InitFromCString(cstring);
}

Ougi::String::String(const String& other) 
{
	InitFromOther(other);
}

void Ougi::String::InitToEmpty()
{
	data = new char[1];
	data[0] = 0;
	ownLength = 0;
}

void Ougi::String::InitFromChar(const char c)
{
	data = new char[2];
	data[0] = c;
	data[1] = 0;
	ownLength = 1;
}

void Ougi::String::InitFromCString(const char cstring[])
{
	ownLength = String.Length(cstring);
	data = new char[ownLength + 1];
	for (unsigned int i = 0; i < ownLength; i++)
	{
		data[i] = cstring[i];
	}
	data[ownLength] = 0;
}

void Ougi::String::InitFromOther(const String& other)
{
	InitFromCString(other.CString());
}

Ougi::String::~String()
{
	delete[] data;
	data = 0;
}

Ougi::String& Ougi::String::operator=(const char c)
{
	delete[] data;
	InitFromChar(c);
	return *this;
}

Ougi::String& Ougi::String::operator=(const char cstring[])
{
	if (data != cstring)
	{
		delete[] data;
		InitFromCString(cstring);
	}
	return *this;
}

Ougi::String& Ougi::String::operator=(const String& rhs) 
{
	if (this != &rhs)
	{
		delete[] data;
		InitFromOther(other);
	}
	return *this;
}

Ougi::String Ougi::String::Clone() const
{
	return String(*this);
}

const char const* Ougi::String::CString() const 
{
	return data;
}

unsigned int Ougi::String::Length(const char cstring[])
{
	unsigned int length = 0;
	for (unsigned int i = 0; cstring[i] != 0; i++)
	{
		length++;
	}
	return length;
}

unsigned int Ougi::String::Length() const
{
	return ownLength;
}

bool Ougi::String::Empty() const
{
	return ownLength == 0;
}

void Ougi::String::Clear()
{
	delete[] data;
	InitToEmpty();
}

char Ougi::String::operator[](const unsigned int index) const
{
	return data[index];
}

char Ougi::String::CharAt(const unsigned int index) const
{
	return data[index];
}

Ougi::String Ougi::String::Substring(const unsigned int start, const unsigned int end) const
{
	const char temp = data[end];
	data[end] = 0;
	String substring(data + start);
	data[end] = temp;
	return substring;
}

bool Ougi::String::StartsWith(const char c) const
{
	return data[0] == c;
}
bool Ougi::String::StartsWith(const char cstring[]) const
{
	if (cstring[0] == 0)
	{
		if (data[0] == 0) return true;
		else return false;
	}
	for (unsigned int i = 0; cstring[i] != 0; ++i)
	{
		if (data[i] != cstring[i]) return false;
	}
	return true;
}

bool Ougi::String::StartsWith(const String& other) const
{
	return StartsWith(other.CString());
}

bool Ougi::String::Contains(const char c) const
{
	for (unsigned int = 0; i < ownLength; ++i)
	{
		if (data[i]) == c) return true;
	}
	return false;
}

bool Ougi::String::Contains(const char cstring[]) const
{
	for (unsigned int i = 0; i < ownLength; ++i)
	{
		if (CharAt(i) == cstring[0])
		{
			if (Substring(i, ownLength).StartsWith(cstring))
			{
				return true;
			}
		}
	}
	return false;
}

bool Ougi::String::Contains(const String& other) const
{
	return Contains(other.CString());
}

Ougi::String Ougi::String::operator+(const char addend) const
{
	return String(*this) += addend;
}

Ougi::String Ougi::String::operator+(const char addend[]) const
{
	return String(*this) += addend;
}

Ougi::String Ougi::String::operator+(const String& addend) const
{
	return String(*this) += addend;
}

Ougi::String& Ougi::String::operator+=(const char addend)
{
	char* newData = new char[ownLength + 2];
	for (unsigned int i = 0; i < ownLength; ++i)
	{
		newData[i] = data[i];
	}
	newData[ownLength] = addend;
	newData[ownLength + 1] = 0;
	delete[] data;
	data = newData;
	++ownLength;
	return (*this);
}

Ougi::String& Ougi::String::operator+=(const char addend[])
{
	return addWithLength(addend, String.Length(addend));
}

Ougi::String& Ougi::String::operator+=(const String& addend)
{
	return addWithLength(addend, addend.Length());
}

Ougi::String& Ougi::String::addWithLength(const char addend[], const unsigned int otherLength)
{
	char* newData = new char[ownLength + otherLength + 1];
	for (unsigned int i = 0; i < ownLength; ++i)
	{
		newData[i] = data[i];
	}
	for (unsigned int i = 0; i < otherLength; ++i)
	{
		newData[ownLength + i] = addend[i];
	}
	newData[ownLength + otherLength] = 0;
	delete[] data;
	data = newData;
	ownLength += otherLength;
	return (*this);
}

Ougi::String Ougi::String::Insert(const unsigned int index, const char c) const
{
	char* newData = new char[ownLength + 2];
	for (unsigned int i = 0; i < index; ++i)
	{
		newData[i] = data[i];
	}
	newData[index] = c;
	for (unsigned int i = index + 1; i < ownLength + 1; ++i)
	{
		newData[i] = data[i - 1];
	}
	newData[ownLength + 1] = 0;
	String newString(newData);
	delete[] newData;
	return newString;
}

Ougi::String Ougi::String::Insert(const unsigned int index, const char cstring[]) const
{
	
}

Ougi::String Ougi::String::Insert(const unsigned int index, const String& other) const
{
	
}

Ougi::String Ougi::String::Erase(const unsigned int index, const unsigned int count) const;

bool Ougi::String::Match(const char regex[]) const;
bool Ougi::String::Match(const String& regex) const;

bool Ougi::String::Search(const char regex[]) const;
bool Ougi::String::Search(const String& regex) const;

bool Ougi::String::Replace(const char regex[]) const;
bool Ougi::String::Replace(const String& regex) const;

bool Ougi::String::operator==(const char c) const
{
	return ownLength == 1 && data[0] == c;
}

bool Ougi::String::operator==(const char cstring[]) const
{
	return ownLength == String.Length(cstring) && StartsWith(cstring);
}

virtual bool Ougi::String::operator==(const String& rhs) const override
{
	return ownLength == rhs.Length() && StartsWith(rhs);
}

virtual bool Ougi::String::operator<(const String& rhs) const override
{
	
}