#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 26-Sept=2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
namespace sdds {

	struct Population {
		char* m_code;
		int* m_value;
	};

	// Reads the whole csv file and saves it into the dynamically allocated memory.
	bool load(const char fileName[]);
	bool read(char code[], FILE* fptr);  // Helper function that reads the postal code 
	bool read(int& value, FILE* fptr);  // Helper function that reads the population of the postal code 
	FILE*& getFilePointer(void);    // Gets the file pointer from file module to Population module

	void display(void);
	void sortData(void);


	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_