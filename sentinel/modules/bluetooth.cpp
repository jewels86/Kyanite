#include "modules.h"
#include "../package.h"
#include "../console.h"
#include "../commands/commands.h"

void bluetooth_module_exit(const std::vector<std::string>& args, Package* package) {
	prints("({{sl}}) >> [red]Exiting Bluetooth module[/]...", quick_map({ "sl" }, { package->stylized_location }));
	package->environment->erase("module_commands");
	package->unregister_func("exit");
	package->register_func("exit", standard_exit_command);
	package->location = "sentinel";
	package->stylized_location = "[blue]sentinel[/]";
}

void bluetooth_module(Package* package) {
	package->unregister_func("exit");
	package->register_func("exit", bluetooth_module_exit);
	package->location = "sentinel/bluetooth";
	package->stylized_location = "[blue]sentinel[/]/[magenta]bluetooth[/]";
	package->environment->insert({ "module_commands", "exit" });
	prints("({{sl}}) >> Bluetooth module loaded!", quick_map({ "sl" }, { package->stylized_location }));
}
