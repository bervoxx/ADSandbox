#include "testCase_reverse_words.h"
#include <functional>
#include <vector>
int main(int argc, char** argv)
{
	std::vector<std::function<void(void)>> TestFunctions{
															TestWord,
															TestMultipleWords,
															TestSpecialCharacters,
															TestEscapeCharacters,
															TestExample
														};
	for (auto& it : TestFunctions)
	{
		it();
	}

	return 0;
}