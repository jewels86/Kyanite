#include "command_dispatcher.h"
#include "package.h"
#include "command.h"
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

bool CommandDispatcher::dispatch(const std::vector<std::string>& args) {
	if (args.empty()) {
		return false;
	}
	std::string command = args[0];
	if (commands.find(command) != commands.end()) {
		commands[command](args, package);
		return true;
	}
	else {
		return false;
	}
}