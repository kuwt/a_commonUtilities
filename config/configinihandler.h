/** @mainpage

	<table>
		<tr><th>Library     <td>configinihandler
		<tr><th>File        <td>configinihandler.h
		<tr><th>Author      <td>kuwingto
	</table>

	Based on SimpleIni, create an easy to use/understand simple api for config read/write. 
	To use this file, you need all configinihandler.h, configinihandler.cpp and SimpleIni.h in your project. 

	e.g.
	
	int pyNum = 0;
	ConfiginiHandler cfg(".\\common.cfg");
	cfg.GetValue("ShapeAlignment", "Pyramid_Number", pyNum);

	std::string strModelparameters;
	ConfiginiHandler cfg(".\\config_Ycylinder.ini");
	cfg.GetValue("Cylinder_Model", "ModelParameters", strModelparameters);
	
**/

#ifndef CONFIGINIHANDLER_H
#define CONFIGINIHANDLER_H
#include <vector>
#include <string>
#include "SimpleIni.h"
class ConfiginiHandler
{
public:
	static const int CONFIG_IO_OK = 0;
	static const int CONFIG_IO_FAIL = -1;

    ConfiginiHandler(const std::string &strFile);
     ~ConfiginiHandler();

	 int SaveDisk();
	 int SetValue(const std::string &strSection, const std::string &strKey, const std::string &strValue);
	 int GetValue(const std::string &strSection, const std::string &strKey, std::string &strValue) const;
	 int GetValue(const std::string &SectionKey, const std::string &strKey, int &iValue) const;   // Value will not be changed if fail
	 int GetValue(const std::string &SectionKey, const std::string &strKey, float &fValue) const;  // Value will not be changed if fail

	 int GetAllSections(std::vector<std::string> &sectionList);
	 int GetAllKeys(const std::string sectionName, std::vector<std::string> &keyList);
	 int PrintAllSectionKeyValue();

private:
	CSimpleIniA *m_pCfg;
    std::string m_strPath;
};

#endif // CONFIGINIHANDLER_H

