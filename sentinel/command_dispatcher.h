#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include <string>
#include <vector>
#include <unordered_map>

#include "command.h"
#include "package.h"

class CommandDispatcher
{
	private:
		std::unordered_map<std::string, Command> commands;
		Package package;

	public:
		CommandDispatcher(Package& package);
		void registerCommand(const Command& command);
		void unregisterCommand(const std::string& commandName);
		void dispatch(const std::string& commandName, const std::vector<std::string>& args);
};

#endif