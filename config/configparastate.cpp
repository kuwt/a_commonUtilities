#include "configparastate.h"
#include "configinihandler.h"
#include "CfgParaDef.h"

// bad implementation, no numeric checking fo rstring
int ConvertStringToFloat(const std::string &str, float &f)
{
	f = std::stof(str);
	return CONFIG_IO_OK;
}

ConfigParaState::ConfigParaState()
{
    m_strCfgFilePath = "";


}

void ConfigParaState::SetParaState(const std::string &SectionKey, const std::string &strKey, const std::string &strValue)
{
	std::string wholekey = SectionKey + "." + strKey;
    m_mapParaState[wholekey] = strValue;
}
int ConfigParaState::GetParaState(const std::string &SectionKey, const std::string &strKey, std::string &strValue) const
{
	std::string wholekey = SectionKey + "." + strKey;
	std::map<std::string, std::string>::const_iterator it = m_mapParaState.find(wholekey);

	if (it != m_mapParaState.end())
	{
		strValue = it->second;
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
}

int ConfigParaState::GetParaState(const std::string &SectionKey, const std::string &strKey, float &fValue) const
{
	std::string strValue;
	std::string wholekey = SectionKey + "." + strKey;
	std::map<std::string, std::string>::const_iterator it = m_mapParaState.find(wholekey);

	if (it != m_mapParaState.end())
	{
		strValue = it->second;
		float f;
		ConvertStringToFloat(strValue, f);
		fValue = f;
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
}
int ConfigParaState::GetParaState(const std::string &SectionKey, const std::string &strKey, int &iValue) const
{
	float f;
	if (GetParaState(SectionKey, strKey, f) == CONFIG_IO_OK)
	{
		iValue = (int)f;
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
}
int ConfigParaState::GetParaState(const std::string &SectionKey, const std::string &strKey, double &dValue) const
{
	float f;
	if (GetParaState(SectionKey, strKey, f) == CONFIG_IO_OK)
	{
		dValue = (double)f;
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
}


void ConfigParaState::LoadCfgPara(const std::string &CfgFilePath)
{
	ConfiginiHandler config(CfgFilePath);

	CfgStatus status = config.LoadFile();
	std::string strValue = "";

	std::map < std::string, std::vector<std::string>> ParaNameTree;
	BuildParamNameTree(ParaNameTree);

	typedef std::map < std::string, std::vector<std::string>>::iterator it_type;
	for (it_type iterator = ParaNameTree.begin(); iterator != ParaNameTree.end(); iterator++)
	{
		std::string SectionName = iterator->first;
		std::vector<std::string> ParamNames = iterator->second;

		for (int i = 0; i < ParamNames.size(); ++i)
		{
			std::string &ParamName = ParamNames.at(i);
			status = config.GetValue(SectionName, ParamName, strValue);
			if (CONFIG_IO_OK == status)
			{
				SetParaState(SectionName, ParamName, strValue);
			}
		}
	}
}


void ConfigParaState::SaveCfgPara(const std::string &CfgFilePath)
{
	
    ConfiginiHandler config(CfgFilePath);
	CfgStatus status;

	std::map < std::string, std::vector<std::string>> ParaNameTree;
	BuildParamNameTree(ParaNameTree);
	/***********
	
	To do 
	
	
	*************/
  
    status = config.SaveFile();
	
}

