#ifdef _WIN32
#include <windows.h>
#include <bluetoothapis.h>
#pragma comment(lib, "Bthprops.lib")
#else
extern "C" {
	#include <bluetooth/bluetooth.h>
	#include <bluetooth/hci.h>
	#include <bluetooth/hci_lib.h>
}
#endif
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "bluetooth_wrapper.h"
#include "../console.h"
#include "../package.h"

#ifdef _WIN32
std::vector<std::string> BluetoothWrapper::list_devices() {
	std::vector<std::string> devices;

	BLUETOOTH_DEVICE_SEARCH_PARAMS search_params = { sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS),
													 BLUETOOTH_DEVICE_SEARCH_FLAG_RETURN_ALL |
													 BLUETOOTH_DEVICE_SEARCH_FLAG_SHOW_HIDDEN };
	BLUETOOTH_DEVICE_INFO device_info = { sizeof(BLUETOOTH_DEVICE_INFO) };

	HBLUETOOTH_DEVICE_FIND hFind = BluetoothFindFirstDevice(&search_params, &device_info);
	if (hFind) {
		do {
			char name[256];
			char address[18];
			WideCharToMultiByte(CP_UTF8, 0, device_info.szName, -1, name, sizeof(name), NULL, NULL);
			snprintf(address, sizeof(address), "%02X:%02X:%02X:%02X:%02X:%02X",
				device_info.Address.rgBytes[5], device_info.Address.rgBytes[4],
				device_info.Address.rgBytes[3], device_info.Address.rgBytes[2],
				device_info.Address.rgBytes[1], device_info.Address.rgBytes[0]);

			std::stringstream ss;
			ss << name << " (" << address << ")";
			devices.push_back(ss.str());
		} while (BluetoothFindNextDevice(hFind, &device_info));

		BluetoothFindDeviceClose(hFind);
	}
	else {
		devices = {};
	}

	return devices;
}

void BluetoothWrapper::print_device_info(const std::string& address, Package& package) {
	BLUETOOTH_DEVICE_INFO device_info = { sizeof(BLUETOOTH_DEVICE_INFO) };

	int addr_bytes[6];
	if (sscanf_s(address.c_str(), "%x:%x:%x:%x:%x:%x",
		&addr_bytes[5], &addr_bytes[4], &addr_bytes[3],
		&addr_bytes[2], &addr_bytes[1], &addr_bytes[0]) != 6) {
		prints("({{sl}}) >> [red]Invalid address format[/]", quick_map({ "sl" }, { package.stylized_location }));
		return;
	}

	for (int i = 0; i < 6; ++i) {
		device_info.Address.rgBytes[i] = static_cast<unsigned char>(addr_bytes[i]);
	}

	if (BluetoothGetDeviceInfo(NULL, &device_info) == ERROR_SUCCESS) {
		char name[256];
		WideCharToMultiByte(CP_UTF8, 0, device_info.szName, -1, name, sizeof(name), NULL, NULL);

		SYSTEMTIME stSeen, stUsed;
		stSeen = device_info.stLastSeen;
		stUsed = device_info.stLastUsed;

		prints("({{sl}}) \t>> Name: {{name}}", quick_map({ "sl", "name" }, { package.stylized_location, name }));
		prints("({{sl}}) \t>> Address: {{addr}}", quick_map({ "sl", "addr" }, { package.stylized_location, address }));
		prints("({{sl}}) \t>> Connected: {{connected}}", quick_map({ "sl", "connected" }, { package.stylized_location, device_info.fConnected ? "Yes" : "No" }));
		prints("({{sl}}) \t>> Paired: {{paired}}", quick_map({ "sl", "paired" }, { package.stylized_location, device_info.fAuthenticated ? "Yes" : "No" }));
		prints("({{sl}}) \t>> Cached: {{cached}}", quick_map({ "sl", "cached" }, { package.stylized_location, device_info.fRemembered ? "Yes" : "No" }));
		prints("({{sl}}) \t>> Device Class: 0x{{class}}", quick_map({ "sl", "class" }, { package.stylized_location, std::to_string(device_info.ulClassofDevice) }));
		prints("({{sl}}) \t>> Last Seen: {{year}}-{{month}}-{{day}} {{hour}}:{{minute}}:{{second}}",
			quick_map({ "sl", "year", "month", "day", "hour", "minute", "second" },
				{ package.stylized_location, std::to_string(stSeen.wYear), std::to_string(stSeen.wMonth), std::to_string(stSeen.wDay),
				  std::to_string(stSeen.wHour), std::to_string(stSeen.wMinute), std::to_string(stSeen.wSecond) }));
		prints("({{sl}}) >> Last Used: {{year}}-{{month}}-{{day}} {{hour}}:{{minute}}:{{second}}",
			quick_map({ "sl", "year", "month", "day", "hour", "minute", "second" },
				{ package.stylized_location, std::to_string(stUsed.wYear), std::to_string(stUsed.wMonth), std::to_string(stUsed.wDay),
				  std::to_string(stUsed.wHour), std::to_string(stUsed.wMinute), std::to_string(stUsed.wSecond) }));
	}
	else {
		prints("({{sl}}) >> [red]Device not found[/]", quick_map({ "sl" }, { package.stylized_location }));
	}
}

#endif
#ifdef __linux__
std::vector<std::string> BluetoothWrapper::list_devices() {
	std::vector<std::string> devices;
	
	int dev_id = hci_get_route(NULL);
	int sock = hci_open_dev(dev_id);
	inquiry_info* ii = nullptr;
	int max_rsp = 255;
	int len = 8;
	int flags = IREQ_CACHE_FLUSH;

	int num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);

	for (int i = 0; i < num_rsp; i++) {
		char addr[19] = { 0 };
		char name[248] = { 0 };
		ba2str(&(ii[i].bdaddr), addr);
		hci_read_remote_name(sock, &(ii[i].bdaddr), sizeof(name), name, 0);

		std::stringstream ss;
		ss << name << " (" << addr << ")";
		devices.push_back(ss.str());
	}

	free(ii);
	hci_close_dev(sock);

	return devices;
}

void BluetoothWrapper::print_device_info(const std::string& address, Package& package) {
		
}
#endif