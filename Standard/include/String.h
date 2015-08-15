#ifndef OUGI_STANDARD_STRING_H
#define OUGI_STANDARD_STRING_H

//-------------------------------------------------------------------------------------------
// String
//-------------------------------------------------------------------------------------------

#ifdef DEBUG
#include <ostream>
#endif

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
		
		const char* CString() const;
		
		static unsigned int Length(const char cstring[]);
		unsigned int Length() const;
		bool Any() const;
		bool Empty() const;
		void Clear();
		
		char operator[](const unsigned int index) const;
		char CharAt(const unsigned int index) const;
		String Substring(const unsigned int start) const;
		String Substring(const unsigned int start, const unsigned int end) const;
		
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
		
		String Insert(const char c, const unsigned int index) const;
		String Insert(const char cstring[], const unsigned int index) const;
		String Insert(const String& other, const unsigned int index) const;
		
		String Erase(const unsigned int index, const unsigned int count) const;
		
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
		char* data;
		unsigned int ownLength;
		
		void InitToEmpty();
		void InitFromChar(const char c);
		void InitFromCString(const char cstring[]);
		void InitFromOther(const String& other);
		
		bool ContainsWithLength(const char cstring[], const unsigned int length) const;
		String& addWithLength(const char addend[], const unsigned int length);
	};
}

#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& out, const Ougi::String& string)
{
	return out << string.CString();
}
#endif

#endif