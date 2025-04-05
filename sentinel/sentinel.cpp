#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "console.h"
#include "command_dispatcher.h"
#include "sentinel.h"
#include "commands/commands.h"
#include "modules/modules.h"

int main()
{
	prints("Welcome to [blue]Kyanite Sentinel[/]!");

	Package package = Package();
	package.location = "sentinel";
	package.stylized_location = "[blue]sentinel[/]";
	package.running = true;
	package.lines = 2;
	package.environment = new std::unordered_map<std::string, std::string>();
	package.modules = new std::unordered_map<std::string, MODULE_TYPE>();
	Package* package_ptr = &package;

	CommandDispatcher dispatch = CommandDispatcher(package_ptr);
	dispatch.registerCommand("exit", standard_exit_command);
	dispatch.registerCommand("clear", clear_command);
	dispatch.registerCommand("use", use_command);

	package.register_func = [&](const std::string trigger, const COMMAND_CALLBACK_TYPE callback) {
		dispatch.registerCommand(trigger, callback);
	};
	package.unregister_func = [&](const std::string trigger) {
		dispatch.unregisterCommand(trigger);
	};

	package.modules->insert({ "wifi", wifi_module });
	
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