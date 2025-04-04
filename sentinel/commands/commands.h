#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>
#include "../package.h"

void exit_command(const std::vector<std::string>& args, Package *package);
void clear_command(const std::vector<std::string>& args, Package* package);
void fclear_command(const std::vector<std::string>& args, Package* package);

#endif