#pragma once

#include "reverse_words.h"
#include <cassert>
#include <iostream>

void TestWord(void)
{
	std::cout << "Testing words: ";
	std::string testString = "";
	assert(reverse_words(testString) == "");
	testString = "abcde";
	assert(reverse_words(testString) == "edcba");
	testString = "12345";
	assert(reverse_words(testString) == "54321");
	testString = "abc123";
	assert(reverse_words(testString) == "321cba");
	std::cout << "success" << std::endl;
}

void TestMultipleWords(void)
{
	std::cout << "Testing multiple words: ";
	std::string testString = "abcde edcba qwert";
	assert(reverse_words(testString) == "edcba abcde trewq");
	testString = "12345,!@#$%^&*/54321";
	assert(reverse_words(testString) == "54321,!@#$%^&*/12345");
	testString = "abc//nbvcxz";
	assert(reverse_words(testString) == "cba//zxcvbn");
	std::cout << "success" << std::endl;
}

void TestSpecialCharacters(void)
{
	std::cout << "Testing special characters: ";
	std::string testString = "12345,!@#$%^&*/?><,.;:[]{}|-=54321";
	assert(reverse_words(testString) == "54321,!@#$%^&*/?><,.;:[]{}|-=12345");
	testString = "$%^";
	assert(reverse_words(testString) == "$%^");
	std::cout << "success" << std::endl;
}

void TestEscapeCharacters(void)
{
	std::cout << "Testing escape characters: ";
	std::string testString = "abc\nbvcxz";
	assert(reverse_words(testString) == "cba\nzxcvb");
	testString = "abc\'nbvcxz";
	assert(reverse_words(testString) == "cba\'zxcvbn");
	std::cout << "success" << std::endl;
}

void TestExample(void)
{
	std::cout << "Testing example: ";
	std::string testString = "String:  2be reversed...";
	assert(reverse_words(testString) == "gnirtS:  eb2 desrever...");
	std::cout << "success" << std::endl;
}