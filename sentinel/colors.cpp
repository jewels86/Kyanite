#include "colors.h"

#include <iostream>
#include <regex>
#include <unordered_map>
#include <string>

void print(const std::string& format, const std::unordered_map<std::string, std::string>& variables = {}) {
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

    std::cout << result << std::endl;
}