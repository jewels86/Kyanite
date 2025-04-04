#ifndef COLORS_H
#define COLORS_H

#include <string>
#include <unordered_map>
#include <vector>

#ifdef _WIN32
const std::string COLOR_RESET = "\033[0m";
const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_YELLOW = "\033[33m";
const std::string COLOR_BLUE = "\033[34m";
const std::string COLOR_MAGENTA = "\033[35m";
const std::string COLOR_CYAN = "\033[36m";
const std::string COLOR_WHITE = "\033[37m";
const std::string COLOR_BOLD = "\033[1m";
const std::string COLOR_UNDERLINE = "\033[4m";
const std::string COLOR_BOLD_RED = "\033[1;31m";
const std::string COLOR_BOLD_GREEN = "\033[1;32m";
const std::string COLOR_BOLD_YELLOW = "\033[1;33m";
const std::string COLOR_BOLD_BLUE = "\033[1;34m";
const std::string COLOR_BOLD_MAGENTA = "\033[1;35m";
const std::string COLOR_BOLD_CYAN = "\033[1;36m";
const std::string COLOR_BOLD_WHITE = "\033[1;37m";
const std::string COLOR_BACKGROUND_RED = "\033[41m";
const std::string COLOR_BACKGROUND_GREEN = "\033[42m";
const std::string COLOR_BACKGROUND_YELLOW = "\033[43m";
const std::string COLOR_BACKGROUND_BLUE = "\033[44m";
const std::string COLOR_BACKGROUND_MAGENTA = "\033[45m";
const std::string COLOR_BACKGROUND_CYAN = "\033[46m";
const std::string COLOR_BACKGROUND_WHITE = "\033[47m";
#endif

#ifdef __linux__
const std::string COLOR_RESET = "\033[0m";
const std::string COLOR_RED = "\033[31m";
const std::string COLOR_GREEN = "\033[32m";
const std::string COLOR_YELLOW = "\033[33m";
const std::string COLOR_BLUE = "\033[34m";
const std::string COLOR_MAGENTA = "\033[35m";
const std::string COLOR_CYAN = "\033[36m";
const std::string COLOR_WHITE = "\033[37m";
const std::string COLOR_BOLD = "\033[1m";	
const std::string COLOR_UNDERLINE = "\033[4m";
const std::string COLOR_BOLD_RED = "\033[1;31m";
const std::string COLOR_BOLD_GREEN = "\033[1;32m";
const std::string COLOR_BOLD_YELLOW = "\033[1;33m";
const std::string COLOR_BOLD_BLUE = "\033[1;34m";
const std::string COLOR_BOLD_MAGENTA = "\033[1;35m";
const std::string COLOR_BOLD_CYAN = "\033[1;36m";
const std::string COLOR_BOLD_WHITE = "\033[1;37m";
const std::string COLOR_BACKGROUND_RED = "\033[41m";
const std::string COLOR_BACKGROUND_GREEN = "\033[42m";
const std::string COLOR_BACKGROUND_YELLOW = "\033[43m";
const std::string COLOR_BACKGROUND_BLUE = "\033[44m";
const std::string COLOR_BACKGROUND_MAGENTA = "\033[45m";
const std::string COLOR_BACKGROUND_CYAN = "\033[46m";
const std::string COLOR_BACKGROUND_WHITE = "\033[47m";
#endif

void prints(const std::string& format, const std::unordered_map<std::string, std::string>& variables = {});
std::unordered_map<std::string, std::string> quick_map(const std::vector<std::string>& keys, const std::vector<std::string>& values);

#endif