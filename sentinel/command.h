#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>

#include "package.h"

class Command
{
	public:
		virtual void execute(std::vector<std::string> command, Package& package) const = 0;

		virtual std::string name() const = 0;
		virtual std::string description() const = 0;
		virtual std::string usage() const = 0;
};

#endif

