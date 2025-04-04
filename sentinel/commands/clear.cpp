#include "commands.h"
#include "../package.h"
#include "../console.h"

void clear_command(const std::vector<std::string>& args, Package* package) {
	system("clear");
}
