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
	ownLength = String::Length(cstring);
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
	if (ownLength == 1)
	{
		data[0] = c;
	}
	else
	{
		delete[] data;
		InitFromChar(c);
	}
	return *this;
}

Ougi::String& Ougi::String::operator=(const char cstring[])
{
	if (data != cstring)
	{
		if (ownLength == String::Length(cstring))
		{
			for (int i = 0; i < ownLength; ++i)
			{
				data[i] = cstring[i];
			}
		}
		else
		{
			delete[] data;
			InitFromCString(cstring);
		}
	}
	return *this;
}

Ougi::String& Ougi::String::operator=(const String& rhs) 
{
	if (this != &rhs)
	{
		if (ownLength == rhs.Length())
		{
			for (int i = 0; i < ownLength; ++i)
			{
				data[i] = rhs[i];
			}
		}
		else
		{
			delete[] data;
			InitFromOther(rhs);
		}
	}
	return *this;
}

Ougi::String Ougi::String::Clone() const
{
	return String(*this);
}

const char* Ougi::String::CString() const 
{
	return data;
}

unsigned int Ougi::String::Length(const char cstring[])
{
	// unsigned int length = 0;
	// for (unsigned int i = 0; cstring[i] != 0; i++)
	// {
	// 	length++;
	// }
	// return length;
	
	const char *char_ptr;
    const unsigned long int *longword_ptr;
    unsigned long int longword, magic_bits, himagic, lomagic;
  
    // Handle the first few characters by reading one character at a time.
    // Do this until CHAR_PTR is aligned on a longword boundary.
    for (char_ptr = cstring; ((unsigned long int) char_ptr& (sizeof (longword) - 1)) != 0; ++char_ptr)
	{
    	if (*char_ptr == '\0')
		{
    		return char_ptr - cstring;
		}
	}
  
    // All these elucidatory comments refer to 4-byte longwords,
    // but the theory applies equally well to 8-byte longwords.
  
    longword_ptr = (unsigned long int *) char_ptr;
  
    // Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
    // the "holes."  Note that there is a hole just to the left of
    // each byte, with an extra at the end:
	//
    // bits:  01111110 11111110 11111110 11111111
    // bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
	//
    // The 1-bits make sure that carries propagate to the next 0-bit.
    // The 0-bits provide holes for carries to fall into.
    magic_bits = 0x7efefeffL;
    himagic = 0x80808080L;
    lomagic = 0x01010101L;
    if (sizeof (longword) > 4)
	{
        // 64-bit version of the magic.
        // Do the shift in two steps to avoid a warning if long has 32 bits.
		magic_bits = ((0x7efefefeL << 16) << 16) | 0xfefefeffL;
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
  
    // Instead of the traditional loop which tests each character,
    // we will test a longword at a time.  The tricky part is testing
    // if *any of the four* bytes in the longword in question are zero.
    for (;;)
	{
       // We tentatively exit the loop if adding MAGIC_BITS to
       // LONGWORD fails to change any of the hole bits of LONGWORD.
  
       // 1) Is this safe?  Will it catch all the zero bytes?
       // Suppose there is a byte with all zeros.  Any carry bits
       // propagating from its left will fall into the hole at its
       // least significant bit and stop.  Since there will be no
       // carry from its most significant bit, the LSB of the
       // byte to the left will be unchanged, and the zero will be
       // detected.
  
       // 2) Is this worthwhile?  Will it ignore everything except
       // zero bytes?  Suppose every byte of LONGWORD has a bit set
       // somewhere.  There will be a carry into bit 8.  If bit 8
       // is set, this will carry into bit 16.  If bit 8 is clear,
       // one of bits 9-15 must be set, so there will be a carry
       // into bit 16.  Similarly, there will be a carry into bit
       // 24.  If one of bits 24-30 is set, there will be a carry
       // into bit 31, so all of the hole bits will be changed.
  
       // The one misfire occurs when bits 24-30 are clear and bit
       // 31 is set; in this case, the hole at bit 31 is not
       // changed.  If we had access to the processor carry flag,
       // we could close this loophole by putting the fourth hole
       // at bit 32!
 
       // So it ignores everything except 128's, when they're aligned properly.
 
       longword = *longword_ptr++;
 
       if (
#if 0
         // Add MAGIC_BITS to LONGWORD.
         (((longword + magic_bits)
 
         // Set those bits that were unchanged by the addition.
         ^ ~longword)
 
         // Look at only the hole bits.  If any of the hole bits
         // are unchanged, most likely one of the bytes was a zero.
         & ~magic_bits)
#else
         ((longword - lomagic) & himagic)
#endif
         != 0)
		{
			// Which of the bytes was the zero?  If none of them were, it was
			// a misfire; continue the search.
		
			const char *cp = (const char *) (longword_ptr - 1);
		
			if (cp[0] == 0)
				return cp - cstring;
			if (cp[1] == 0)
				return cp - cstring + 1;
			if (cp[2] == 0)
				return cp - cstring + 2;
			if (cp[3] == 0)
				return cp - cstring + 3;
			if (sizeof (longword) > 4)
			{
				if (cp[4] == 0)
				return cp - cstring + 4;
				if (cp[5] == 0)
				return cp - cstring + 5;
				if (cp[6] == 0)
				return cp - cstring + 6;
				if (cp[7] == 0)
				return cp - cstring + 7;
			}
		}
    }
}

unsigned int Ougi::String::Length() const
{
	return ownLength;
}

bool Ougi::String::Any() const
{
	return ownLength > 0;
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

Ougi::String Ougi::String::Substring(const unsigned int start) const
{
	return Substring(start, ownLength);
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
	return ownLength > 0 && data[0] == c;
}

bool Ougi::String::StartsWith(const char cstring[]) const
{
	if (ownLength == 0) return false;
	
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
	for (unsigned int i = 0; i < ownLength; ++i)
	{
		if (data[i] == c) return true;
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
	return addWithLength(addend, String::Length(addend));
}

Ougi::String& Ougi::String::operator+=(const String& addend)
{
	return addWithLength(addend.CString(), addend.Length());
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

Ougi::String Ougi::String::Insert(const char c, const unsigned int index) const
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

Ougi::String Ougi::String::Insert(const char cstring[], const unsigned int index) const
{
	// TODO
	return String();
}

Ougi::String Ougi::String::Insert(const String& other, const unsigned int index) const
{
	// TODO
	return String();
}

Ougi::String Ougi::String::Erase(const unsigned int index, const unsigned int count) const
{
	// TODO
	return String();
}

bool Ougi::String::Match(const char regex[]) const
{
	// TODO
	return false;
}

bool Ougi::String::Match(const String& regex) const
{
	// TODO
	return false;
}

bool Ougi::String::Search(const char regex[]) const
{
	// TODO
	return false;
}

bool Ougi::String::Search(const String& regex) const
{
	// TODO
	return false;
}

bool Ougi::String::Replace(const char regex[]) const
{
	// TODO
	return false;
}

bool Ougi::String::Replace(const String& regex) const
{
	// TODO
	return false;
}

bool Ougi::String::operator==(const char c) const
{
	return ownLength == 1 && data[0] == c;
}

bool Ougi::String::operator==(const char cstring[]) const
{
	return ownLength == String::Length(cstring) && StartsWith(cstring);
}

bool Ougi::String::operator==(const String& rhs) const
{
	return ownLength == rhs.Length() && StartsWith(rhs);
}

bool Ougi::String::operator<(const String& rhs) const
{
	for (unsigned int i = 0; i < ownLength; ++i)
	{
		if (CharAt(i) < rhs[i]) return true;
		if (CharAt(i) > rhs[i]) return false;
	}
	if (ownLength < rhs.Length()) return true;
	return false;
}