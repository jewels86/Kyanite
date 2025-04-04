#include <iostream>
#include <string>
#include <vector>

#include "colors.h"

int main()
{
	std::cout << COLOR_BOLD << COLOR_GREEN << "Hello, World!" << COLOR_RESET << std::endl;
	std::cout << COLOR_BOLD_RED << "This is a bold red text." << COLOR_RESET << std::endl;
	std::cout << COLOR_UNDERLINE << "This is an underlined text." << COLOR_RESET << std::endl;
	std::cout << COLOR_BACKGROUND_BLUE << "This text has a blue background." << COLOR_RESET << std::endl;
	return 0;
};