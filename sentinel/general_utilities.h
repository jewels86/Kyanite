#include <string>

#ifdef _WIN32
	const char* RED = "\x1b[31m";
	const char* GREEN = "\x1b[32m";
	const char* RESET = "\x1b[0m";
#else
	const char* RED = "\033[31m";
	const char* GREEN = "\033[32m";
	const char* RESET = "\033[0m";
#endif
#include <windows.h>

#pragma once
class GeneralUtilities
{
public:
	
};

