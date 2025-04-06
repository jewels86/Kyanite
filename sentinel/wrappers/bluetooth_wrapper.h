#ifndef BLUETOOTH_WRAPPER_H
#define BLUETOOTH_WRAPPER_H

#ifndef BLUETOOTH_DEVICE_SEARCH_FLAG_RETURN_ALL
#define BLUETOOTH_DEVICE_SEARCH_FLAG_RETURN_ALL 0x00000002
#endif

#ifndef BLUETOOTH_DEVICE_SEARCH_FLAG_SHOW_HIDDEN
#define BLUETOOTH_DEVICE_SEARCH_FLAG_SHOW_HIDDEN 0x00000004
#endif

#include <string>
#include <vector>
#include "../package.h"

class BluetoothWrapper {
public:
	std::vector<std::string> list_devices();
	void print_device_info(const std::string& address, Package &package);
	//bool connect(const std::string& device_address);
	//bool send(const std::string& data);
	//std::string receive();
};

#endif