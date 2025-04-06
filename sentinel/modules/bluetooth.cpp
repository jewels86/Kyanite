#include "modules.h"
#include "../package.h"
#include "../console.h"
#include "../commands/commands.h"
#include "../wrappers/bluetooth_wrapper.h"

void bluetooth_module_exit(const std::vector<std::string>& args, Package* package) {
	prints("({{sl}}) >> [red]Exiting Bluetooth module[/]...", quick_map({ "sl" }, { package->stylized_location }));
	package->environment->erase("module_commands");
	package->unregister_func("exit");
	package->register_func("exit", standard_exit_command);
	package->location = "sentinel";
	package->stylized_location = "[blue]sentinel[/]";
}

void bluetooth_module_list_devices(const std::vector<std::string>& args, Package* package) {
	BluetoothWrapper bluetooth;
	std::vector<std::string> devices = bluetooth.list_devices();
	if (devices.empty()) {
		prints("({{sl}}) >> [red]No Bluetooth devices found[/]", quick_map({ "sl" }, { package->stylized_location }));
	}
	else {
		prints("({{sl}}) >> [green]Bluetooth devices found:[/]", quick_map({ "sl" }, { package->stylized_location }));
		for (const auto& device : devices) {
			prints("({{sl}}) >> - {{device}}", quick_map({ "sl", "device" }, { package->stylized_location, device }));
		}
	}
#ifdef _WIN32
	prints("({{sl}}) >> [magenta]Beware[/]: Bluetooth scanning on Windows will ONLY get previously paired or cached devices!", quick_map({"sl"}, {package->stylized_location}));
#endif // _WIN32

}

void bluetooth_module_print_device_info(const std::vector<std::string>& args, Package* package) {
	if (args.size() < 2) {
		prints("({{sl}}) >> [red]Usage: list devices <device_address>[/]", quick_map({ "sl" }, { package->stylized_location }));
		return;
	}
	BluetoothWrapper bluetooth;
	bluetooth.print_device_info(args[1], *package);
}

void bluetooth_module(Package* package) {
	package->unregister_func("exit");
	package->register_func("exit", bluetooth_module_exit);
	package->register_func("list devices", bluetooth_module_list_devices);
	package->register_func("info", bluetooth_module_print_device_info);
	package->location = "sentinel/bluetooth";
	package->stylized_location = "[blue]sentinel[/]/[magenta]bluetooth[/]";
	package->environment->insert({ "module_commands", "exit" });
	prints("({{sl}}) >> Bluetooth module loaded!", quick_map({ "sl" }, { package->stylized_location }));
}
