#include <experimental/filesystem>
#include <string>
#include <vector>
#include <iostream>

namespace fs = std::experimental::filesystem;

namespace dir
{
	// return the filenames of all files that have the specified extension
	// in the specified directory and all subdirectories
	void get_all_file(const fs::path& root,
		const std::string& ext,
		std::vector<fs::path>& ret)
	{
		if (!fs::exists(root) || !fs::is_directory(root)) return;

		fs::recursive_directory_iterator it(root);
		fs::recursive_directory_iterator endit;

		while (it != endit)
		{
			if (fs::is_regular_file(*it) && it->path().extension() == ext)
			{
				ret.push_back(it->path());
			}
			++it;
		}
	}


	int listAllFilesPathsFromDir(const std::string& dirPath,
		const std::string &extension,
		std::vector<std::string> &path)
	{
		path.clear();
		std::vector<fs::path> dataPaths;

		{
			std::vector<fs::path> dataPathsPerExt;

			dataPathsPerExt.clear();
			get_all_file(dirPath,
				extension,
				dataPaths);
			dataPaths.insert(dataPaths.end(), dataPathsPerExt.begin(), dataPathsPerExt.end());

		}
		for (int i = 0; i < dataPaths.size(); ++i)
		{
			std::string dataPath = dataPaths.at(i).string();
			path.push_back(dataPath);
		}

		return 0;
	}

	bool CheckIfFilePathContainSubPath(const std::string& FilePath,
		const std::string &SubPath)
	{
		int wildcard_pos = FilePath.find(SubPath);
		if (wildcard_pos != std::string::npos)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void CreateDir(const std::string &dir)
	{
		if (fs::create_directories(dir))
		{
			std::cerr << "Directory Created: " << dir << std::endl;
		}
	}

	void MakeDefaultDir(const std::string &Rootdir, const std::string &folderName, std::string &Defaultdir)
	{
		int proposeDirIdx = 0;
		std::string strproposeDirIdx = std::to_string(proposeDirIdx);
		std::string proposeDir = Rootdir + "\\" + folderName;

		std::string proposeFullDir = proposeDir + strproposeDirIdx;

		while (fs::exists(proposeFullDir))
		{
			proposeDirIdx++;
			strproposeDirIdx = std::to_string(proposeDirIdx);

			proposeFullDir = proposeDir + strproposeDirIdx;
		}

		std::string NewDir = proposeFullDir;
		CreateDir(NewDir);

		Defaultdir = NewDir;
	}
}