#include "Utility.h"

std::string Utility::toLowerStr(std::string str) {
	for (std::string::iterator charIt = str.begin(); charIt != str.end(); charIt++)
		*charIt = std::tolower(*charIt);

	return str;
}
