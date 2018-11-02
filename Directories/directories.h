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


	void MakeDirByName(const std::string &Rootdir, const std::string &folderName, std::string &dirCreated);

	bool CheckFileExist(const std::string &FilePath);

	int GetAllFolderInADir(const std::string &Directory, std::vector<std::string> &vfolderpaths);
	int FileCopy(const std::string &FromFilePath, const std::string &ToFilePath);
}