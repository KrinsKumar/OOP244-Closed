//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-Sept=2022
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "dictionary.h"

using namespace std; 

namespace sdds
{
	char charEnd = '\n';    // To put an \n char in the end of the entered definition
	char* p_charEnd = &charEnd;

	void DisplayWord(const char* word)
	{
		dictionary& currentDict =  getGlobal();
		int flag_search = 0;    // Flag for the outermost loop
		int i = 0;    // To keep track of the index

		while (flag_search == 0)
		{
			if (strcmp(currentDict.m_word_list[i].m_word, word) == 0)
			{
				cout << "FOUND: [" << word << "] has [" << currentDict.m_word_list[i].m_number_of_definitions << "] definitions:\n";
				int count = 1;

				for (int j = 1; j <= currentDict.m_word_list[i].m_number_of_definitions; j++)
				{
					cout << count << ". {" << currentDict.m_word_list[i].m_definitions_type[j] << "} " <<
						currentDict.m_word_list[i].m_definition[j];
					count++;
				}
				flag_search = 1;
			}
			else if (i == currentDict.m_number_of_words)
			{
				cout << "NOT FOUND: word [" << word << "] is not in the dictionary.\n";
				flag_search = 1;
			}
			i++;
		}
		sendGlobal(currentDict);
	}

	void AddWord(const char* word, const char* type, const char* definition)
	{
		dictionary& currentDict = getGlobal();

		int flag_search = 0;    // Flag for the outermost loop
		int i = 0;    // To keep track of the index

		while (flag_search == 0)
		{
			if (strcmp(currentDict.m_word_list[i].m_word, word) == 0)  // To add to the definitions of the existing words
			{
				currentDict.m_word_list[i].m_number_of_definitions++;
				int place = currentDict.m_word_list[i].m_number_of_definitions;
				strcpy(currentDict.m_word_list[i].m_definitions_type[place], type);
				strcpy(currentDict.m_word_list[i].m_definition[place], definition);
				strcat(currentDict.m_word_list[i].m_definition[place], p_charEnd);
				flag_search = 1;
			}

			if (i == currentDict.m_number_of_words)  // To create a brand new word and its definition
			{
				i++;
				currentDict.m_number_of_words++;
				currentDict.m_word_list[i].m_number_of_definitions = 1;
				strcpy(currentDict.m_word_list[i].m_word, word);
				strcpy(currentDict.m_word_list[i].m_definitions_type[1], type);
				strcpy(currentDict.m_word_list[i].m_definition[1], definition);
				strcat(currentDict.m_word_list[i].m_definition[1], p_charEnd);
				flag_search = 1;
			}
			i++;
		}
		sendGlobal(currentDict);
	}
}
