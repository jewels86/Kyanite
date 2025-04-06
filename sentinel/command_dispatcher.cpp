#include "command_dispatcher.h"
#include "package.h"
#include "command.h"
#include "console.h"
#include <string>

CommandDispatcher::CommandDispatcher(Package *package) {
	this->package = package;
}

void CommandDispatcher::registerCommand(std::string trigger, const COMMAND_CALLBACK_TYPE callback) {
	commands[trigger] = callback;
}
void CommandDispatcher::unregisterCommand(std::string trigger) {
	commands.erase(trigger);
}

bool CommandDispatcher::dispatch(const std::string command) {
	if (command == "") {
		return false;
	}
	for (const auto& _command : commands) {
		if (command.find(_command.first) == 0) {
			std::vector<std::string> args = split_string(command, ' ');
			_command.second(args, package);
			return true;
		}
	}
	return false;
}