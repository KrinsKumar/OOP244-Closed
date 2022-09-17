//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-Sept=2022
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
	void DisplayWord(const char* word)
	{
		search_print(word);
	}

	void AddWord(const char* word, const char* type, const char* definition)
	{
		add_word(word, type, definition);
	}
}