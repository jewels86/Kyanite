#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <stdbool.h>
#include <unordered_map>
#include <functional>

#define MODULE_TYPE std::function<void(Package*)>
#define COMMAND_CALLBACK_TYPE std::function<void(const std::vector<std::string>&, Package*)>
#define REGISTER_COMMAND_TYPE std::function<void(const std::string, const COMMAND_CALLBACK_TYPE)>
#define UNREGISTER_COMMAND_TYPE std::function<void(const std::string)>
#define DISPATCH_COMMAND_TYPE std::function<bool(const std::string)>

struct Package
{
	std::string location;
	std::string stylized_location;
	bool running = false;
	int lines = 0;

	std::unordered_map<std::string, std::string> *environment = nullptr;
	std::unordered_map<std::string, MODULE_TYPE> *modules = nullptr;

	REGISTER_COMMAND_TYPE register_func;
	UNREGISTER_COMMAND_TYPE unregister_func;
	DISPATCH_COMMAND_TYPE dispatch_func;
};

#endif