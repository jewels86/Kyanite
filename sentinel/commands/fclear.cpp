#include "commands.h"
#include "../package.h"
#include "../console.h"

void fclear_command(const std::vector<std::string>& args, Package* package) {
	system("clear");
}