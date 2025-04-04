#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "console.h"
#include "command_dispatcher.h"
#include "sentinel.h"
#include "commands/commands.h"

int main()
{
	prints("Welcome to [blue]Kyanite Sentinel[/]!");

	Package package = Package();
	package.location = "sentinel";
	package.stylized_location = "[blue]sentinel[/]";
	package.running = true;
	package.lines = 2;
	package.environment = new std::unordered_map<std::string, std::string>();
	Package* package_ptr = &package;

	CommandDispatcher dispatch = CommandDispatcher(package_ptr);
	dispatch.registerCommand("exit", exit_command);
	dispatch.registerCommand("clear", clear_command);
	
	while (package.running) {
		std::string input = ::input(formats("({{sl}}) << ", quick_map({ "sl" }, { package.stylized_location })));
		if (input.empty()) {
			continue;
		}

		std::vector<std::string> args = split_string(input, ' ');
		package.lines += 1;
		
		if (!dispatch.dispatch(args)) {
			prints("({{sl}}) >> [red]Command not found[/]: \"{{c}}\"", quick_map({ "sl", "c"}, {package.stylized_location, args[0]}));
		}
	}

	return 0;
}