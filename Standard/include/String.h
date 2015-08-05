#ifndef OUGI_STANDARD_STRING_H
#define OUGI_STANDARD_STRING_H

//-------------------------------------------------------------------------------------------
// String
//-------------------------------------------------------------------------------------------

#include "Interfaces.h"

namespace Ougi
{
	class String : Comparable<String>
	{
	public:
		String();
		String(const char c);
		String(const char cstring[]);
		String(const String& other);
		
		virtual ~String();
		
		String& operator=(const char c);
		String& operator=(const char cstring[]);
		String& operator=(const String& rhs);
		
		String Clone() const;
		
		const char const* CString() const;
		
		static unsigned int Length(const char cstring[]);
		unsigned unsigned int Length() const;
		bool Empty() const;
		void Clear();
		
		char operator[](const unsigned int index) const;
		char CharAt(const unsigned int index) const;
		String Substring(const unsigned int start, const unsigned int end = ownLength) const;
		
		bool StartsWith(const char c) const;
		bool StartsWith(const char cstring[]) const;
		bool StartsWith(const String& other) const;
		
		bool Contains(const char c) const;
		bool Contains(const char cstring[]) const;
		bool Contains(const String& other) const;
		
		String operator+(const char addend) const;
		String operator+(const char addend[]) const;
		String operator+(const String& addend) const;
		
		String& operator+=(const char addend);
		String& operator+=(const char addend[]);
		String& operator+=(const String& addend);
		
		String& Insert(const unsigned int index, const char c);
		String& Insert(const unsigned int index, const char cstring[]);
		String& Insert(const unsigned int index, const String& other);
		
		String& Erase(const unsigned int index, const unsigned int count);
		
		bool Match(const char regex[]) const;
		bool Match(const String& regex) const;
		
		bool Search(const char regex[]) const;
		bool Search(const String& regex) const;
		
		bool Replace(const char regex[]) const;
		bool Replace(const String& regex) const;
		
		bool operator==(const char c) const;
		bool operator==(const char cstring[]) const;
		virtual bool operator==(const String& rhs) const override;
		
		bool operator!=(const char c) const;
		bool operator!=(const char cstring[]) const;
		
		bool operator<(const char c) const;
		bool operator<(const char cstring[]) const;
		virtual bool operator<(const String& rhs) const override;
			
		bool operator<=(const char c) const;
		bool operator<=(const char cstring[]) const;
		
		bool operator>(const char c) const;
		bool operator>(const char cstring[]) const;
		
		bool operator>=(const char c) const;
		bool operator>=(const char cstring[]) const;
	
	protected:
		unsigned int ownLength;
		char* data;
		
		void InitToEmpty();
		void InitFromChar(const char c);
		void InitFromCString(const char cstring[]);
		void InitFromOther(const String& other);
		
		bool ContainsWithLength(const char cstring[], const unsigned int length) const;
	};
}

inline std::ostream& operator<<(std::ostream& out, const Ougi::String& string)
{
	return out << string.CString();
}

#endif