
#include "split.h"


int main()
{
	std::vector<std::string> paths;
	split("D:\\temp\\test3D\\IH_027.txt", paths, ';');
	split("D:\\temp\\test3D\\IH_027.txt;asdasf", paths, ';');
	split("D:\\temp\\test3D\\IH_027.txt;asdasf;aaa", paths, ';');
    return 0;
}
