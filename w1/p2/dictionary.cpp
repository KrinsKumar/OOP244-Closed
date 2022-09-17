#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
	dictionary global_dict;
	char end = '\n';
	char* p_end = &end;

    int LoadDictionary(const char* filename)
    {
		dictionary dic = {0 , NULL};
		int count_word = 0;    // To count the number of words scanned from the dictionary
		int count_definition;   // To count the number of definitions scanned 
        
        FILE* dict = NULL;
        dict = fopen(filename, "r");

		char scan_word[64];    // To store the scanned word
		char scan_definition[1024];    // To store the scanned defination.

        if (dict != NULL)
        {

			while (fgets(scan_word, 64, dict) != NULL)
			{
				int i = 0;    // for forLoop
				int flag_word = 0;    // For words loop
				int flag_definition = 0;    // For definations loops
				int flag_type = 0;
				count_definition = 0;

				while (flag_word == 0)    // WORD loop
				{
					if (scan_word[i] == '\n')
					{
						scan_word[i] = '\0';
						flag_word = 1;
					}
					i++;
				}
				strcpy(dic.m_word_list[count_word].m_word, scan_word);

				i = 0;

				while (flag_definition == 0)    // Loop to scan all the definations in the string 
				{
					char defi[64] = {NULL};    // Temp string to store the data
					char defi2[64] = {NULL};    // Another string to store the data
					int eof = 0;    // Checks for end of file

					if (fgets(scan_definition, 1024, dict) == NULL)
					{
						eof = 1;
					}

					if (scan_definition[0] == '\n' || eof == 1)    // TO dectect a new line
					{
						flag_definition = 1;
					}
					else
					{
						count_definition++;   // Keeps track of the number of definitions
						char* place = strchr(scan_definition, ':');    // To get the pointer of the :
						strcpy(dic.m_word_list[count_word].m_definition[count_definition], (place + 2));    // To extract the defination
						strncpy(defi, scan_definition, int(place-scan_definition));    // To extract the type

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
			global_dict = dic;
			return 0;
        }
		global_dict = dic;
        return 1;
    }

	void SaveDictionary(const char* filename)
	{
		FILE* dict = NULL;
		dict = fopen(filename, "w");

		int total_words = global_dict.m_number_of_words;
		

		for (int i = 0; i < total_words; i++)
		{
			fputs(global_dict.m_word_list[i].m_word, dict);
			fputc('\n', dict);
			
			int total_definitions = global_dict.m_word_list[i].m_number_of_definitions;

			for (int j = 1; j <= total_definitions; j++)
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

			if (i == global_dict.m_number_of_words)
			{
				flag_search = 1;
			}

			if (strcmp(global_dict.m_word_list[i].m_word, word) == 0)
			{
				if (global_dict.m_word_list[i].m_number_of_definitions > 1)
				{
					cout << "The word [" << word << "] has multiple definitions:\n";

					int count = 1;

					for (int j = 1; j <= global_dict.m_word_list[i].m_number_of_definitions; j++)
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

	void search_print(const char* word)
	{
		int flag_search = 0;    // Flag for the outermost loop
		int i = 0;    // To keep track of the index

		while (flag_search == 0)
		{

			if (i == global_dict.m_number_of_words)
			{
				cout << "NOT FOUND : word [" << word << "] is not in the dictionary.\n";
				flag_search = 1;
			}

			if (strcmp(global_dict.m_word_list[i].m_word, word) == 0)
			{
				cout << "FOUND: [" << word << "] has [" << global_dict.m_word_list[i].m_number_of_definitions << "] definitions:\n";
				int count = 1;

				for (int j = 1; j <= global_dict.m_word_list[i].m_number_of_definitions; j++)
				{
					cout << count << ". {" << global_dict.m_word_list[i].m_definitions_type[j] << "} " <<
						global_dict.m_word_list[i].m_definition[j];
					count++;
				}

				flag_search = 1;
			}

			i++;

		}
	}

	void add_word(const char* word, const char* type, const char* definition)
	{
		int flag_search = 0;    // Flag for the outermost loop
		int i = 0;    // To keep track of the index

		while (flag_search == 0)
		{

			if (strcmp(global_dict.m_word_list[i].m_word, word) == 0)  // To add to the definitions of the existing words
			{
				global_dict.m_word_list[i].m_number_of_definitions++;
				int place = global_dict.m_word_list[i].m_number_of_definitions;
				strcpy(global_dict.m_word_list[i].m_definitions_type[place], type);
				strcpy(global_dict.m_word_list[i].m_definition[place], definition);
				strcat(global_dict.m_word_list[i].m_definition[place], p_end);
				flag_search = 1;
			}

			if (i == global_dict.m_number_of_words)  // To create a brand new word and its definition
			{
				i++;
				global_dict.m_number_of_words++;
				global_dict.m_word_list[i].m_number_of_definitions = 1;
				strcpy(global_dict.m_word_list[i].m_word,word);
				strcpy(global_dict.m_word_list[i].m_definitions_type[1], type);
				strcpy(global_dict.m_word_list[i].m_definition[1], definition);
				strcat(global_dict.m_word_list[i].m_definition[1], p_end);
				flag_search = 1;
			}
			i++;
		}
	}


}