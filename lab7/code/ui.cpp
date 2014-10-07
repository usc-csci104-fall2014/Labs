#include <iostream>
#include <string>
#include "StackGame.h"

int main(int argv, char* argc[])
{
	//test to see if there are enough arguments
	if (argv != 2)
	{
		std::cout << "Error: Not enough arguments" << std::endl;
		std::cout << "       Run the program with: \"StackGame <sequence>\"" << std::endl;
		return -1;
	}

	try
	{
		StackGame g(argc[1]);
		int point = g.Run();
		std::cout << "Game ended. Point = " << point << std::endl;
	}
	catch(const std::exception & ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
	}

	return 0;
}
