#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <stdbool.h>
#include <unordered_map>

struct Package
{
	std::string location;
	std::string stylized_location;
	bool running = false;
	int lines = 0;

	std::unordered_map<std::string, std::string> *environment;
};

#endif