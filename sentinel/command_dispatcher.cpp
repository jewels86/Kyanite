#include "command_dispatcher.h"
#include "package.h"
#include "command.h"
#include <string>

CommandDispatcher::CommandDispatcher(Package& package) {
	this->package = package;
}

void CommandDispatcher::registerCommand(const Command& command) {
	commands[command.name()] = command;
}
void CommandDispatcher::unregisterCommand(const std::string& commandName) {
	commands.erase(commandName);
}
void CommandDispatcher::dispatch(const std::string& commandName, const std::vector<std::string>& args) {
	if (commands.find(commandName) != commands.end()) {
		commands[commandName].execute(args, package);
	}
	else {
		std::cerr << "Command not found: " << commandName << std::endl;
	}
}
