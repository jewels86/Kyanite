#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <stdbool.h>

struct Package
{
	std::string location;
	std::string stylized_location;
	bool running = false;
};

#endif