#include "modules.h"
#include "../package.h"
#include "../console.h"
#include "../commands/commands.h"
#include <iostream>

void wifi_module_networks_command(const std::vector<std::string>& args, Package* package) {
	
}

void wifi_module_exit(const std::vector<std::string>& args, Package* package) {
	prints("({{sl}}) >> [red]Exiting WiFi module[/]...", quick_map({ "sl" }, { package->stylized_location }));
	package->environment->erase("module_commands");
	package->unregister_func("networks");
	package->register_func("exit", standard_exit_command);
	package->location = "sentinel";
	package->stylized_location = "[blue]sentinel[/]";
}

void wifi_module(Package *package) {
	package->unregister_func("exit");
	package->register_func("list networks", wifi_module_networks_command);
	package->register_func("exit", wifi_module_exit);
	package->location = "sentinel/wifi";
	package->stylized_location = "[blue]sentinel[/]/[green]wifi[/]";
	package->environment->insert({ "module_commands", "networks" });
	prints("({{sl}}) >> WiFi module loaded!", quick_map({"sl"}, {package->stylized_location}));
}