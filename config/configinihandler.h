#ifndef CONFIGINIHANDLER_H
#define CONFIGINIHANDLER_H

#include "SimpleIni.h"
typedef CSimpleIniA  Config;

typedef int CfgStatus;
#define CONFIG_IO_OK (1)
#define CONFIG_IO_FAIL (0) 

#include <vector>
#include <string>
class ConfiginiHandler
{
public:
    ConfiginiHandler(const std::string &strFile);
     ~ConfiginiHandler();
	 CfgStatus LoadFile();
	 CfgStatus SaveFile();
	 CfgStatus SetValue(const std::string &strSection, const std::string &strKey, const std::string &strValue);
	 CfgStatus GetValue(const std::string &strSection, const std::string &strKey, std::string &strValue);
	 CfgStatus GetAllSections(std::vector<std::string> &sectionList);
	 CfgStatus GetAllKeys(const std::string sectionName, std::vector<std::string> &keyList);
private:
    Config *m_pCfg;
    std::string m_strPath;
};

#endif // CONFIGINIHANDLER_H

