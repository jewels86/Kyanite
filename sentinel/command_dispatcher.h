#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

#include "package.h"

#define COMMAND_CALLBACK_TYPE std::function<void(const std::vector<std::string>&, Package&)>

class CommandDispatcher
{
	private:
		std::unordered_map<std::string, COMMAND_CALLBACK_TYPE> commands;
		Package package;

	public:
		CommandDispatcher(Package& package);
		void registerCommand(std::string trigger, const COMMAND_CALLBACK_TYPE callback);
		void unregisterCommand(std::string trigger);
		void dispatch(const std::vector<std::string>& args);
};

#endif