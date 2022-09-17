#ifndef SDDS_WORDS_H 
#define SDDS_WORDS_H 
//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-Sept=2022
namespace sdds 
{

	/// <summary>
	/// Search in the dictionary for the word and display all the definitions found.
	/// 
	/// Print "NOT FOUND: word [X] is not in the dictionary." if
	///   the word doesn't exist in dictionary.
	/// </summary>
	/// <param name="word">The word to search and display.</param>
	void DisplayWord(const char* word);

	/// <summary>
	/// Adds a word to the dictionary.
	/// 
	/// If the dictionary already contains the word, add a new definition for it.
	/// </summary>
	/// <param name="word">The word to add to the dictionary.</param>
	/// <param name="type">The type of the word (noun, verb, adjective, etc.)</param>
	/// <param name="definition">The definition for the word.</param>
	void AddWord(const char* word, const char* type, const char* definition);

}

#endif
