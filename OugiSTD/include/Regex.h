#ifndef OUGI_REGEX_H
#define OUGI_REGEX_H

//-------------------------------------------------------------------------------------------
// Regex
//-------------------------------------------------------------------------------------------

namespace Ougi
{
	namespace Regex
	{
		bool Match(const char* string, const char* regex);
		bool Search(const char* string, const char* regex);
		const char* Replace(const char* string, const char* regex);
	}
}

#endif OUGI_REGEX_H