#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
	dictionary global_dict;  // Global Dict
	char end = '\n';    // To put an \n char in the end of the entered definition
	char* p_end = &end;

    int LoadDictionary(const char* filename)
    {
		dictionary dic = {0 , 0};
		int count_word = 0;    // To count the number of words scanned from the dictionary
		int count_definition;   // To count the number of definitions scanned 
		char scan_word[64];    // To store the scanned word
		char scan_definition[1024];    // To store the scanned defination.

		FILE* dict = NULL;    // New dict in the scope that flushes the old global_dict
		dict = fopen(filename, "r");

        if (dict != NULL)
        {
			while (fgets(scan_word, 64, dict) != NULL)
			{
				int i = 0;    // for forLoop
				int flag_definition = 0;    // For definations loops
				count_definition = 0;

				removeEndOfLine(scan_word, i);    // Puts '\0' instead of '\n\ in the end string
				strcpy(dic.m_word_list[count_word].m_word, scan_word);   // Copies the correct string in the dic struct

				i = 0;

				while (flag_definition == 0)    // Loop to scan all the definations in the string 
				{
					int eof = 0;    // Checks for end of file

					if (fgets(scan_definition, 1024, dict) == NULL)
						eof = 1;    // To check if the end of the file is reaached or not

					if (scan_definition[0] == '\n' || eof == 1)    // T0 dectect a new line which means all the definitons are scanned
						flag_definition = 1;
					else
					{
						count_definition++;   // Keeps track of the number of definitions
						char defi[64] = { 0 };    // Temp string to store the data
						char defi2[64] = { 0 };    // Another string to store the data

						char* place = strchr(scan_definition, ':');    // To get the pointer of the :
						strcpy(dic.m_word_list[count_word].m_definition[count_definition], (place + 2));    // To extract the defination
						strncpy(defi, scan_definition, int(place - scan_definition));    // To extract the type

						int temp = 0; // Flag for the loop
						int j = 0;    // index for the loop
						int k = 0;    // For copy index

						while (temp == 0)
						{
							if (defi[j] != '\t')
							{
								defi2[k] = defi[j];
								k++;
							}
							j++;

							if (defi[j] == '\0')
							{
								temp = 1;
							}
						}
						strcpy(dic.m_word_list[count_word].m_definitions_type[count_definition], defi2);    //Definition type
					}
				}
				dic.m_word_list[count_word].m_number_of_definitions = count_definition;    //Definition number
				dic.m_number_of_words = count_word;    //Total number of words
				count_word++;
			}
            fclose(dict);
			global_dict = dic;    // Updating the global dict (the previous one is discarded)
			return 0;
        }
		global_dict = dic;
        return 1;
    }

	void SaveDictionary(const char* filename)
	{
		FILE* dict = NULL;
		dict = fopen(filename, "w");
		int total_words = global_dict.m_number_of_words;   // Storing the total number of words for readability

		for (int i = 0; i < total_words; i++)
		{
			fputs(global_dict.m_word_list[i].m_word, dict);    // Storing the word
			fputc('\n', dict);
			
			int total_definitions = global_dict.m_word_list[i].m_number_of_definitions;   // The number of definition that the word has

			for (int j = 1; j <= total_definitions; j++)  // Loop to store the definitions
			{
				fputc('\t', dict);
				fputs(global_dict.m_word_list[i].m_definitions_type[j], dict);
				fputc(':', dict);
				fputc(' ', dict);
				fputs(global_dict.m_word_list[i].m_definition[j], dict);
			}
			fputc('\n', dict);
		}
		fclose(dict);
	}

	int UpdateDefinition(const char* word, const char* type, const char* definition)
	{
		int flag_search = 0;    // Flag for the outermost loop
		int i = 0;    // To keep track of the index

		while (flag_search == 0)
		{
			if (i == global_dict.m_number_of_words)    // Condition for if the word is not found
			{
				flag_search = 1;
			}

			if (strcmp(global_dict.m_word_list[i].m_word, word) == 0)    // If the word is found 
			{
				if (global_dict.m_word_list[i].m_number_of_definitions > 1)    // If more than one defintions
				{
					int count = 1;
					cout << "The word [" << word << "] has multiple definitions:\n";

					for (int j = 1; j <= global_dict.m_word_list[i].m_number_of_definitions; j++)    // To print the definitions
					{
						cout << count << ". {" << global_dict.m_word_list[i].m_definitions_type[j] << "} " <<
							global_dict.m_word_list[i].m_definition[j];
						count++;
					}

					int update; // to store the input from the user

					cout << "Which one to update? ";
					cin >> update;
					strcpy(global_dict.m_word_list[i].m_definitions_type[update], type);
					strcpy(global_dict.m_word_list[i].m_definition[update], definition);
					strcat(global_dict.m_word_list[i].m_definition[update], p_end);
				}
				flag_search = 1;
			}
			i++;
		}
		return 0;
	}


	// Student defined function
	void removeEndOfLine(char word[], int i)    // Removes the '\n' from the end of line
	{
		int flag_word = 0;    // For words loop

		while (flag_word == 0)    // WORD loop
		{
			if (word[i] == '\n')
			{
				word[i] = '\0';    // Puts '\0' instead of '\n\ in the end string
				flag_word = 1;
			}
			i++;
		}
	}

	dictionary& getGlobal(void) {
		return global_dict;
	}


	void sendGlobal(dictionary current) {
		global_dict = current;
	}
}