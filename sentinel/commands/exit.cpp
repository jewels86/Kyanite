#include "commands.h"
#include "../package.h"
#include "../console.h"

void exit_command(const std::vector<std::string>& args, Package *package) {
	package->running = false;
	prints("({{sl}}) >> is exiting...", quick_map({ "sl" }, { package->stylized_location }));

	return;
}