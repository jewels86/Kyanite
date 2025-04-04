#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "console.h"
#include "command_dispatcher.h"
#include "sentinel.h"

int main()
{
	prints("Welcome to [blue]Kyanite Sentinel[/]!");

	Package package = Package();
	package.location = "sentinel";
	package.stylized_location = "[blue]sentinel[/]";
	package.running = true;
	CommandDispatcher dispatch = CommandDispatcher(package);
	
	while (package.running) {
		std::string input = ::input(formats("({{sl}}) >> ", quick_map({ "sl" }, { package.stylized_location })));
		std::vector<std::string> args = split_string(input, ' ');
		std::string command = args[0];

		prints(command);
	}

	return 0;
}