#include "commands.h"
#include "../package.h"
#include "../console.h"

void use_command(const std::vector<std::string>& args, Package* package) {
	if (args.size() < 2) {
		prints("({{sl}}) >> [red]Usage[/]: \"{{c}}\"", quick_map({ "sl", "c" }, { package->stylized_location, "use <module>" }));
		return;
	}
	if (package->modules->find(args[1]) != package->modules->end()) {
		prints("({{sl}}) >> [green]Loading module[/]: \"{{m}}\"", quick_map({ "sl", "m" }, { package->stylized_location, args[1] }));
		package->modules->at(args[1])(package);
	}
	else {
		prints("({{sl}}) >> [red]Module not found[/]: \"{{m}}\"", quick_map({ "sl", "m" }, { package->stylized_location, args[1] }));
	}
}