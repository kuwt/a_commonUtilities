#ifndef CONFIGPARASTATE_H
#define CONFIGPARASTATE_H
#include <map>
#include <string>
#include <vector>

class ConfigParaState
{
public:
    ConfigParaState();

    // Data exchange between cache and config file

	// File Interaction
    void LoadCfgPara(const std::string &CfgFilePath); 
    void SaveCfgPara(const std::string &CfgFilePath);  // currently Disable
	
													   // RAM interaction
	void SetParaState(const std::string &SectionKey, const std::string &strKey, const std::string &strValue);
	int GetParaState(const std::string &SectionKey, const std::string &strKey, std::string &strValue) const;  // Value will not be changed if fail

	int GetParaState(const std::string &SectionKey, const std::string &strKey, int &iValue) const;   // Value will not be changed if fail
	int GetParaState(const std::string &SectionKey, const std::string &strKey, double &dValue) const;  // Value will not be changed if fail
	int GetParaState(const std::string &SectionKey, const std::string &strKey, float &fValue) const;  // Value will not be changed if fail


private:
    std::string m_strCfgFilePath;
    std::map<std::string,std::string> m_mapParaState;

};



#endif // CONFIGPARASTATE_H
