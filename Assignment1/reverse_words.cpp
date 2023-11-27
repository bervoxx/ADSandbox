#include "reverse_words.h"
#include <cctype>
#include <stack>

typedef std::stack<char> WORD_CONT;

std::string reverse_word(WORD_CONT& word)
{
	std::string result("");
	while (!word.empty())
	{
		result += word.top();
		word.pop();
	}
	return result;
}

std::string reverse_words(const std::string& str)
{
	std::string result("");
	WORD_CONT word;
	for (auto it : str)
	{
		if (std::isalnum(it))
		{
			word.push(it);
		}
		else
		{
			if (!word.empty())
			{
				result+=reverse_word(word);
			}
			result += it;		
		}
	}
	if(!word.empty())
	{
		result+=reverse_word(word);
	}

	return result;
}