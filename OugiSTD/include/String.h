#ifndef OUGI_STRING_H
#define OUGI_STRING_H

//-------------------------------------------------------------------------------------------
// String
//-------------------------------------------------------------------------------------------

#include "Regex.h"

namespace Ougi
{
	class String
	{
	public:
		String();
		String(const char c);
		String(const char* cstring);
		String(const String& other);
		
		~String();
		
		String& operator=(const char c);
		String& operator=(const char* cstring);
		String& operator=(const String& other);
		
		String Clone() const;
		char*  c_String() const;
		
		unsigned int Length() const;
		bool Empty() const;
		void Clear();
		
		char       operator[](const unsigned int index);
		const char operator[](const unsigned int index) const;
		char       At(const unsigned int index);
		const char At(const unsigned int index) const;
		char       Back();
		const char Back() const;
		char       Front();
		const char Front() const;
		
		bool Contains(const char c) const;
		bool Contains(const char* string) const;
		bool Contains(const String& string) const;
		
		String Substring(const unsigned int start, const unsigned int end = length) const;
		
		String operator+(const char addend);
		String operator+(const char* addend);
		String operator+(const String& addend);
		
		String& operator+=(const char addend);
		String& operator+=(const char* addend);
		String& operator+=(const String& addend);
		
		String& Insert(const unsigned int index, const char c);
		String& Insert(const unsigned int index, const char* cstring);
		String& Insert(const unsigned int index, const String& other);
		
		String& Erase(const unsigned int index, const unsigned int count);
		
		bool Match(const char* regex) const;
		bool Match(const String& regex) const;
		
		bool Search(const char* regex) const;
		bool Search(const String& regex) const;
		
		bool Replace(const char* regex) const;
		bool Replace(const String& regex) const;
		
		unsigned int Find(const char c) const;
		unsigned int Find(const char* cstring) const;
		unsigned int Find(const String& string) const;
		
		unsigned int rFind(const char c) const;
		unsigned int rFind(const char* cstring) const;
		unsigned int rFind(const String& string) const;
		
		int operator==(const char c);
		int operator==(const char* cstring);
		int operator==(const String& string);
	
	private:
		char* string;
		unsigned int length;
		
		static const unsigned int npos = -1;
	};
}

inline std::ostream& operator<<(std::ostream& out, const Ougi::String& string)
{
	return out << string.c_str();
}

#endif