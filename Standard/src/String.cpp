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
	data[0] = '\0';
	length = 0;
}

void Ougi::String::InitFromChar(const char c)
{
	length = 1;
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
}

void Ougi::String::InitFromCString(const char cstring[])
{
	length = String.Length(cstring);
	data = new char[length + 1];
	for (unsigned int i = 0; i < length; i++)
	{
		data[i] = cstring[i];
	}
	data[length] = '\0';
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
	delete[] data;
	InitFromCString(cstring);
	return *this;
}

Ougi::String& Ougi::String::operator=(const String& rhs) 
{
	delete[] data;
	InitFromOther(other);
	return *this;
}

Ougi::String Ougi::String::Clone() const
{
	return String(*this);
}

char* Ougi::String::CString() const 
{
	return data;
}

unsigned int Ougi::String::Length(const char cstring[])
{
	unsigned int length = 0;
	for (unsigned int i = 0; cstring[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

unsigned int Ougi::String::Length() const
{
	return length;
}

bool Ougi::String::Empty() const
{
	return length == 0;
}

void Ougi::String::Clear()
{
	delete[] data;
	InitToEmpty();
}

char Ougi::String::operator[](const unsigned int index);
const char Ougi::String::operator[](const unsigned int index) const;
char Ougi::String::At(const unsigned int index);
const char Ougi::String::At(const unsigned int index) const;
char Ougi::String::Back();
const char Ougi::String::Back() const;
char Ougi::String::Front();
const char Ougi::String::Front() const;

bool Ougi::String::Contains(const char c) const;
bool Ougi::String::Contains(const char cstring[]) const;
bool Ougi::String::Contains(const String& other) const;

Ougi::String Ougi::String::Substring(const unsigned int start, const unsigned int end = length) const;

Ougi::String Ougi::String::operator+(const char addend);
Ougi::String Ougi::String::operator+(const char addend[]);
Ougi::String Ougi::String::operator+(const String& addend);

Ougi::String& Ougi::String::operator+=(const char addend);
Ougi::String& Ougi::String::operator+=(const char addend[]);
Ougi::String& Ougi::String::operator+=(const String& addend);

Ougi::String& Ougi::String::Insert(const unsigned int index, const char c);
Ougi::String& Ougi::String::Insert(const unsigned int index, const char cstring[]);
Ougi::String& Ougi::String::Insert(const unsigned int index, const String& other);

Ougi::String& Ougi::String::Erase(const unsigned int index, const unsigned int count);

bool Ougi::String::Match(const char regex[]) const;
bool Ougi::String::Match(const String& regex) const;

bool Ougi::String::Search(const char regex[]) const;
bool Ougi::String::Search(const String& regex) const;

bool Ougi::String::Replace(const char regex[]) const;
bool Ougi::String::Replace(const String& regex) const;

bool Ougi::String::operator==(const char c);
bool Ougi::String::operator==(const char cstring[]);
virtual bool Ougi::String::operator==(const String& rhs) const override;
virtual bool Ougi::String::operator<(const String& rhs) const override;