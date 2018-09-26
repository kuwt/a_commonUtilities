#ifndef CONFIGINIHANDLER_H
#define CONFIGINIHANDLER_H

#include "SimpleIni.h"
typedef CSimpleIniA  Config;

typedef int CfgStatus;
#define CONFIG_IO_OK (1)
#define CONFIG_IO_FAIL (0) 

class ConfiginiHandler
{
public:
    ConfiginiHandler(const std::string &strFile);
     ~ConfiginiHandler();
	 CfgStatus LoadFile();
	 CfgStatus SaveFile();
	 CfgStatus SetValue(const std::string &strSection, const std::string &strKey, const std::string &strValue);
	 CfgStatus GetValue(const std::string &strSection, const std::string &strKey, std::string &strValue);

private:
    Config *m_pCfg;
    std::string m_strPath;
};

#endif // CONFIGINIHANDLER_H

