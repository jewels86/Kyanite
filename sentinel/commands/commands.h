#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>
#include "../package.h"

void standard_exit_command(const std::vector<std::string>& args, Package *package);
void clear_command(const std::vector<std::string>& args, Package* package);
void use_command(const std::vector<std::string>& args, Package* package);

#endif