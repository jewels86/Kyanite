#include "console.h"
#include <sstream> 
#include <iostream>
#include <regex>
#include <unordered_map>
#include <string>

std::string formats(const std::string& format, const std::unordered_map<std::string, std::string>& variables) {
	std::regex color_regex(R"(\[([a-zA-Z]+)\](.*?)\[\/\])");
	std::regex var_regex(R"(\{\{(\w+)\}\})");
	std::smatch match;
	std::string result = format;
	std::string::const_iterator searchStart(result.cbegin());

	while (std::regex_search(searchStart, result.cend(), match, var_regex)) {
		std::string var_name = match[1].str();
		std::string var_value = variables.at(var_name);
		result.replace(match.position(0), match.length(0), var_value);
		searchStart = result.cbegin() + match.position(0) + var_value.length();
	}

	searchStart = result.cbegin();

	while (std::regex_search(searchStart, result.cend(), match, color_regex)) {
		std::string color = match[1].str();
		std::string text = match[2].str();
		std::string color_code;

		if (color == "blue") {
			color_code = COLOR_BLUE;
		} else if (color == "red") {
			color_code = COLOR_RED;
		} else if (color == "green") {
			color_code = COLOR_GREEN;
		} else if (color == "yellow") {
			color_code = COLOR_YELLOW;
		} else if (color == "bold") {
			color_code = COLOR_BOLD;
		} else if (color == "underline") {
			color_code = COLOR_UNDERLINE;
		} else {
			color_code = COLOR_RESET;
		}

		std::string colored_text = color_code + text + COLOR_RESET;
		result.replace(match.position(0), match.length(0), colored_text);
		searchStart = result.cbegin() + match.position(0) + colored_text.length();
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