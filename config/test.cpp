#include "ConfigParaState.h"
#include "CfgParaDef.h"
#include <iostream>
int main()
{
	int imageNum = 0;
	{
		ConfigParaState cfg;
		cfg.LoadCfgPara("common.cfg");
		cfg.GetParaState(_PARA_SECTION_CAMERA, _PARA_BATCH_IMG_NUM, imageNum);
	}
	std::cout << imageNum << "\n";
	getchar();
	return 0;
}