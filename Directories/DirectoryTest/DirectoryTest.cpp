// DirectoryTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../directories.h"
#include  <iostream>
int main()
{
	// test 1
	std::vector<std::string> folderPaths;
	dir::GetAllFolderInADir("TestDirectories\\src",folderPaths);
	std::cout << "print folder paths" << "\n";
	for (unsigned i = 0; i < folderPaths.size(); ++i)
	{
		std::cout << folderPaths.at(i) << "\n";
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

