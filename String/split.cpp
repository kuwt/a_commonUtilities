
#include <vector>
#include <string>

unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	int pos = txt.find(ch);
	int initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	int temp = (pos < txt.size()) ? pos : txt.size();
	// Add the last one
	strs.push_back(txt.substr(initialPos, temp - initialPos + 1));
	return strs.size();
}