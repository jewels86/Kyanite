#include "console.h"
#include "package.h"
#include <sstream> 
#include <iostream>
#include <regex>
#include <unordered_map>
#include <string>

std::string formats(const std::string& format, const std::unordered_map<std::string, std::string>& variables) {
	std::string result = format;
	std::regex variable_regex(R"(\{\{(\w+)\}\})");
	std::smatch match;

	while (std::regex_search(result, match, variable_regex)) {
		std::string variable_name = match[1].str();
		if (variables.find(variable_name) != variables.end()) {
			result.replace(match.position(0), match.length(0), variables.at(variable_name));
		} else {
			result.replace(match.position(0), match.length(0), "");
		}
	}

	std::regex color_regex(R"(\[([a-zA-Z]+)\](.*?)\[\/\])");
	while (std::regex_search(result, match, color_regex)) {
		std::string color = match[1].str();
		std::string text = match[2].str();
		std::string color_code;

		if (color == "red") {
			color_code = "\033[31m";
		} else if (color == "green") {
			color_code = "\033[32m";
		} else if (color == "yellow") {
			color_code = "\033[33m";
		} else if (color == "blue") {
			color_code = "\033[34m";
		} else if (color == "magenta") {
			color_code = "\033[35m";
		} else if (color == "cyan") {
			color_code = "\033[36m";
		} else {
			color_code = "\033[0m"; // reset color
		}

		result.replace(match.position(0), match.length(0), color_code + text + "\033[0m");
	}

	return result;
}


void prints(const std::string& format, const std::unordered_map<std::string, std::string>& variables) {
	std::cout << formats(format, variables) << std::endl;
}

std::unordered_map<std::string, std::string> quick_map(const std::vector<std::string>& keys, const std::vector<std::string>& values) {
	std::unordered_map<std::string, std::string> variables;
	for (size_t i = 0; i < keys.size() && i < values.size(); ++i) {
		variables[keys[i]] = values[i];
	}
	return variables;
}

std::string input(const std::string prompt) {
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

std::string options(const std::string& prompt, const std::vector<std::string>& options) {
	std::string input;
	std::cout << prompt << std::endl;
	for (size_t i = 0; i < options.size(); ++i) {
		std::cout << i + 1 << ". " << options[i] << std::endl;
	}
	std::cout << "Choose an option (1-" << options.size() << "): ";
	std::getline(std::cin, input);
	int choice = std::stoi(input);
	if (choice > 0 && choice <= options.size()) {
		return options[choice - 1];
	} else {
		return "";
	}
}

std::vector<std::string> split_string(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(str);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}