#pragma once 

#include <string>
#include <vector>

namespace dir
{
	int listAllFilesPathsFromDir(const std::string& dirPath,
		const std::string &extension,
		std::vector<std::string> &path);

	bool CheckIfFilePathContainSubPath(const std::string& FilePath,
		const std::string &SubPath);

	void CreateDir(const std::string &dir);

	void MakeDefaultDir(const std::string &Rootdir, const std::string &folderName, std::string &Defaultdir);
}