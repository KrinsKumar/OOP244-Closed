#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
	

	void DisplayWord(const char* word)
	{
		int flag_search = 0;    // Flag for the outermost loop
		int i = 0;    // To keep track of the index

		while (flag_search == 0)
		{
			if (strcmp(global_dict.m_word_list[i].m_word, word) == 0)
			{
				int count = 0;
				for (int i = 0; i < global_dict.m_word_list[i].m_number_of_definitions; i++)
				{
					cout << count << ". {" << global_dict.m_word_list[i].m_definitions_type[count] << "} " <<
					    global_dict.m_word_list[i].m_definition;
				}

			}

			i++;

			if (i == global_dict.m_number_of_words)
			{
				cout << "NOT FOUND : word [" << word << "] is not in the dictionary.";
				flag_search = 1; 
			}
			
		}
	}

	void AddWord(const char* word, const char* type, const char* definition)
	{

	}
}