
#include "..\configinihandler.h"
#include <iostream>
#include<cstdio>
int main()
{

	std::cout << "Test 1: Get value from config file...\n";
	{
		int pyNum = 0;
		ConfiginiHandler cfg(".\\common.cfg");
		cfg.GetValue("ShapeAlignment", "Pyramid_Number", pyNum);
		std::cout << "if this number (" << pyNum << ") is equal to 1 but not 0, this test is passed." << "\n";

		std::cout << "key press to continue...\n";
		getchar();
	}

	std::cout << "Test 2: Print all entries in config file...\n";
	{
		ConfiginiHandler cfg(".\\crit_Left.ini");

		std::cout << "Printing...\n";
		cfg.PrintAllSectionKeyValue();

		std::cout << "key press to continue...\n";
		getchar();
	}

	return 0;
}