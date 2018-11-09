#include "..\configParaState.h"
#include "..\CfgParaDef.h"
#include "..\configinihandler.h"
#include <iostream>
int main()
{
	
	// test get parameter from file and load it to ram for anytime use
	{
		int pyNum = 0;
		ConfigParaState cfg;
		int status = cfg.LoadCfgPara("..\\common.cfg");
		if (status != 0)
		{
			std::cout << "file not exist\n";
		}
		else
		{
			status = cfg.GetParaState(_PARA_SECTION_SHAPE_ALIGNMENT, _PARA_PYRAMID_NUM, pyNum);
		}

		std::cout << "if this number (" << pyNum << ") is equal to 1 but not 0, this test is passed." << "\n";

		std::cout << "key press to continue...\n";
		getchar();
	}


	{
		ConfiginiHandler cfg("..\\crit_Left.ini");

		std::cout << "Print...\n";

		std::vector<std::string> sections;
		cfg.GetAllSections(sections);
		for (int i = 0; i < sections.size(); ++i)
		{
			std::vector<std::string> keys;
			cfg.GetAllKeys(sections.at(i), keys);
			for (int j = 0; j < keys.size(); ++j)
			{
				std::string value;
				cfg.GetValue(sections.at(i), keys.at(j), value);
				std::cout << sections.at(i) << " " << keys.at(j) << " " << value << "\n";
			}
		}

		std::cout << "key press to continue...\n";
		getchar();
	}
	return 0;
}