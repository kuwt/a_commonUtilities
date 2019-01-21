
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

	std::cout << "Test 2: Get str value from config file...\n";
	{
		std::string strModelparameters;
		ConfiginiHandler cfg(".\\config_Ycylinder.ini");
		cfg.GetValue("Cylinder_Model", "ModelParameters", strModelparameters);
		
		std::string delimiter = ";";

		bool bSplitAccordingToDelimiter = true;
		std::string strSearchStr = strModelparameters;
		std::vector<std::string> elements;
		while (bSplitAccordingToDelimiter)
		{
			size_t loc = strSearchStr.find(delimiter);
			if (loc != std::string::npos)
			{
				std::string element = strSearchStr.substr(0, loc);
				std::string remainingElement = strSearchStr.substr(loc + 1, strSearchStr.size());
				elements.push_back(element);
				strSearchStr = remainingElement;
			}
			else
			{
				elements.push_back(strSearchStr);
				bSplitAccordingToDelimiter = false;
			}
		}

		std::cout << "Printing...\n";
		for (int i = 0; i < elements.size(); ++i)
		{
			std::cout << elements.at(i) << "\n";
		}

		std::cout << "key press to continue...\n";
		getchar();
	}

	std::cout << "Test 3: Print all entries in config file...\n";
	{
		ConfiginiHandler cfg(".\\crit_Left.ini");

		std::cout << "Printing...\n";
		cfg.PrintAllSectionKeyValue();

		std::cout << "key press to continue...\n";
		getchar();
	}


	return 0;
}