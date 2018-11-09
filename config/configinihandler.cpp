#include "configinihandler.h"


#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
ConfiginiHandler::ConfiginiHandler(const std::string &strFile)
{
    m_strPath = strFile;
	m_pCfg = new CSimpleIniA();
	SI_Error status = m_pCfg->LoadFile(m_strPath.c_str());
	if (status != SI_OK)
	{
		std::cout << "Fail to load config. File does not exist." << "\n";
	}
}


int ConfiginiHandler::SaveDisk()
{
	if (m_pCfg)
	{
		SI_Error status = m_pCfg->SaveFile(m_strPath.c_str());
		if (status == SI_OK)
		{
			return CONFIG_IO_OK;
		}
	}

	return CONFIG_IO_FAIL;
}

int ConfiginiHandler::SetValue(const std::string &strSection, const std::string &strKey, const std::string &strValue)
{
	if (m_pCfg)
	{
		SI_Error status = m_pCfg->SetValue(strSection.c_str(), strKey.c_str(), strValue.c_str());
		if (status == SI_OK)
		{
			return CONFIG_IO_OK;
		}
	}

	return CONFIG_IO_FAIL;
}


int ConfiginiHandler::GetValue(const std::string &strSection, const std::string &strKey, std::string &strValue) const
{
	strValue = "";
	if (m_pCfg)
	{
		const char *pszValue = m_pCfg->GetValue(strSection.c_str(), strKey.c_str(), NULL);
		if (pszValue != NULL)
		{

			std::string strTemp(pszValue);
			if (strTemp != "")
			{
				strValue = strTemp;
				return CONFIG_IO_OK;
			}

		}
	}
	return CONFIG_IO_FAIL;
}

bool isNumeric(std::string isItNumeric)
{
	char* p;
	strtol(isItNumeric.c_str(), &p, 10);
	return *p == 0;
}

int ConvertStringToFloat(const std::string &str, float &f)
{
	f = 0;
	if (isNumeric(str))
	{
		f = std::stof(str);
		return 0;
	}

	return -1;
}

int ConfiginiHandler::GetValue(const std::string &strSection, const std::string &strKey, float &fValue) const
{
	fValue = 0;
	if (m_pCfg)
	{
		const char *pszValue = m_pCfg->GetValue(strSection.c_str(), strKey.c_str(), NULL);
		if (pszValue != NULL)
		{

			std::string strTemp(pszValue);
			if (strTemp != "")
			{
				if (ConvertStringToFloat(strTemp, fValue) == 0)
				{
					return CONFIG_IO_OK;
				}
			}
		}
	}
	return CONFIG_IO_FAIL;
}

int ConfiginiHandler::GetValue(const std::string &strSection, const std::string &strKey, int &iValue) const
{
	iValue = 0;
	if (m_pCfg)
	{
		const char *pszValue = m_pCfg->GetValue(strSection.c_str(), strKey.c_str(), NULL);
		if (pszValue != NULL)
		{

			std::string strTemp(pszValue);
			if (strTemp != "")
			{
				float value = 0;
				ConvertStringToFloat(strTemp, value);
				iValue = int(value + 0.5);
				return CONFIG_IO_OK;
			}
		}
	}
	return CONFIG_IO_FAIL;
}
int ConfiginiHandler::GetAllSections(std::vector<std::string> &sectionList)
{
	sectionList.clear();
	if (m_pCfg)
	{
		CSimpleIniA::TNamesDepend sections;
		m_pCfg->GetAllSections(sections);
		sections.sort(CSimpleIniA::Entry::LoadOrder());
		for (auto i : sections)
		{
			const char *pszSections = i.pItem;
			std::string strTemp(pszSections);
			if (strTemp != "")
			{
				sectionList.push_back(strTemp);
			}
		}
		return CONFIG_IO_OK;
	}
	return CONFIG_IO_FAIL;
}

int ConfiginiHandler::GetAllKeys(const std::string sectionName, std::vector<std::string> &keyList)
{
	keyList.clear();
	if (m_pCfg)
	{
		CSimpleIniA::TNamesDepend keys;
		m_pCfg->GetAllKeys(sectionName.c_str(), keys);
		keys.sort(CSimpleIniA::Entry::LoadOrder());
		for (auto i : keys)
		{
			const char *pszKeys = i.pItem;
			std::string strTemp(pszKeys);
			if (strTemp != "")
			{
				keyList.push_back(strTemp);
			}
		}
		return CONFIG_IO_OK;
	}

	return CONFIG_IO_FAIL;
}

ConfiginiHandler::~ConfiginiHandler()
{
	SaveDisk();
	if (m_pCfg != NULL)
	{
		delete m_pCfg;
		m_pCfg = NULL;
	}
}

int ConfiginiHandler::PrintAllSectionKeyValue()
{
	if (m_pCfg)
	{
		std::cout << std::setw(30) << std::setfill(' ') << "section";
		std::cout << std::setw(30) << std::setfill(' ') << "key";
		std::cout << std::setw(30) << std::setfill(' ') << "value";
		std::cout << "\n";
		std::vector<std::string> sections;
		int status = GetAllSections(sections);
		for (int i = 0; i < sections.size(); ++i)
		{
			std::vector<std::string> keys;
			status = GetAllKeys(sections.at(i), keys);
			for (int j = 0; j < keys.size(); ++j)
			{
				std::string value;
				GetValue(sections.at(i), keys.at(j), value);
				std::cout << std::setw(30) << std::setfill(' ') << sections.at(i);
				std::cout << std::setw(30) << std::setfill(' ') << keys.at(j);
				std::cout << std::setw(30) << std::setfill(' ') << value;
				std::cout << "\n";
			}
		}
		return CONFIG_IO_OK;
	}

	return CONFIG_IO_FAIL;
}


