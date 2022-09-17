#ifndef SDDS_DICTIONARY_H 
#define SDDS_DICTIONARY_H

namespace sdds 
{
	struct word
	{
		char m_word[64];
		int m_number_of_definitions;
		char m_definitions_type[8][20];
		char m_definition[8][1024];
	};

	struct dictionary
	{
		int m_number_of_words;
		word m_word_list[100];
	};

    /// <summary>
    /// Load from a file a set of words with their definition.  Any previous
    ///   existing dictionary is discarded, regardless of the result of the load.
    /// </summary>
    /// <param name="filename">The name of the file containing the dictionary.</param>
    /// <returns>0 if data has been loaded from the file, non-zero otherwise
    ///   (null parameter, empty parameter, missing file).</returns>
    int LoadDictionary(const char* filename);

    /// <summary>
    /// Save all the words existing in the dictionary into a file.  The functions
    ///   "LoadDictionary" should be able to load from this after the save finished.
    /// </summary>
    /// <param name="filename">The name of the file where to save.</param>
    void SaveDictionary(const char* filename);

    /// <summary>
    /// Searches in the dictionary for a word and update its definition and type.
    ///   If the word contains multiple definitions, print the message
    ///   "The word [X] has multiple definitions:" followed by a list of existing
    ///   definitions, and asks user which one to update.  This function assumes that
    ///   the user's input is correct and doesn't require validation.
    /// 
    /// If the word is not in the dictionary, this function does nothing.
    /// </summary>
    /// <param name="word">The word to update.</param>
    /// <param name="type">The new type of the definition.</param>
    /// <param name="definition">The new definition.</param>
    /// <returns></returns>
    int UpdateDefinition(const char* word, const char* type, const char* definition);
}

#endif