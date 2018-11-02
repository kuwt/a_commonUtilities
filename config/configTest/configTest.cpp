#include "..\configParaState.h"
#include "..\CfgParaDef.h"
#include <iostream>
int main()
{
	// test get parameter from file
	int pyNum = 0;
	{
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
	}
	std::cout << "if this number (" << pyNum <<") is equal to 1 but not 0, this test is passed." << "\n";

	std::cout << "key press to continue...\n";
	getchar();
	return 0;
}