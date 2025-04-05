#include "commands.h"
#include "../package.h"
#include "../console.h"

void standard_exit_command(const std::vector<std::string>& args, Package *package) {
	package->running = false;

	return;
}