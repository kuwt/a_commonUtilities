// DirectoryTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../directories.h"
#include  <iostream>
int main()
{
	// test 1
	std::vector<std::string> folderPaths;
	dir::GetAllFolderPathInADir("TestDirectories\\src", true, folderPaths);
	std::cout << "print folder paths" << "\n";
	for (unsigned i = 0; i < folderPaths.size(); ++i)
	{
		std::cout << folderPaths.at(i) << "\n";
	}

	std::vector<std::string> folderNames;
	dir::GetAllFolderNameInADir("TestDirectories\\src", true, folderNames);
	std::cout << "print folder names" << "\n";
	for (unsigned i = 0; i < folderNames.size(); ++i)
	{
		std::cout << folderNames.at(i) << "\n";
	}

	//test 2
	dir::CreateDir("TestDirectories\\log");
	dir::CreateDir("TestDirectories\\log\\log");
	dir::CreateDir("TestDirectories\\log\\log\\log");
	dir::CreateDir("TestDirectories\\log1\\log1\\log1");

	std::cout << "press key to continue....\n";
	getchar();
    return 0;
}

