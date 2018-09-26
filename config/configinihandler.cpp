#include "configinihandler.h"


#include <string>
#include <vector>


#define MAX_VALUE_LENGTH (200)



ConfiginiHandler::ConfiginiHandler(const std::string &strFile)
{
    m_strPath = strFile;
    LoadFile();
}


int ConfiginiHandler::LoadFile()
{
    m_pCfg = new Config();
	SI_Error status = m_pCfg->LoadFile(m_strPath.c_str());
	if (status == SI_OK)
	{
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
   
}

int ConfiginiHandler::SaveFile()
{
	SI_Error status = m_pCfg->SaveFile(m_strPath.c_str());
	if (status == SI_OK)
	{
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
}

int ConfiginiHandler::SetValue(const std::string &strSection, const std::string &strKey, const std::string &strValue)
{
	SI_Error status = m_pCfg->SetValue(strSection.c_str(),strKey.c_str(), strValue.c_str());
	if (status == SI_OK)
	{
		return CONFIG_IO_OK;
	}
	else
	{
		return CONFIG_IO_FAIL;
	}
}

int ConfiginiHandler::GetValue(const std::string &strSection, const std::string &strKey, std::string &strValue)
{
   strValue = "";

    const char *pszValue = m_pCfg->GetValue(strSection.c_str(),strKey.c_str(), NULL );
    if (pszValue != NULL)
    {
		
        std::string strTemp(pszValue);
		if (strTemp != "")
		{
			strValue = strTemp;
			return CONFIG_IO_OK;
		}

    }
	
	return CONFIG_IO_FAIL;

}

ConfiginiHandler::~ConfiginiHandler()
{
    delete m_pCfg;
}





