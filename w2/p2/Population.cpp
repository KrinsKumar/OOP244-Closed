#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include <cstring>
#include "File.h"
//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 26-Sept=2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

using namespace std;
namespace sdds {

	// Global variables
	int Records = 0; 
	Population* popData{};

	bool load(const char fileName[]) {	

		bool flag = true;
		
		if (openFile(fileName)) {

			int totalRecords = noOfRecords();    // To get the number of records in the file 
			
			FILE* fptr = getFilePointer();    // To get the pointer in the file* 
			popData = new Population[totalRecords];

			for (int i = 0; i < totalRecords; i++) { // Loop to scan all the records
				int value;
				char code[4];
				if (read(code, fptr) && read(value, fptr)) {   // To check successful read

					popData[i].m_code = new char[4];  // Allocates the memories 
					popData[i].m_value = new int;

					strcpy(popData[i].m_code, code);  // Saves the calues in the allocated memories
					*popData[i].m_value = value;
				}
				else {
					i = totalRecords;    // to break the loop
				}
			}
			Records = totalRecords;
		}
		else {
			cout << "Could not open data file : " << fileName << endl;
			flag = false;
		}

		closeFile();
		return flag;
	}

	bool read(char code[], FILE* fptr) {
		int flag = true;
		if (fscanf(fptr, "%[^,]", code) != 1) {
			flag = false;
		}
		return flag;
	}

	bool read(int& value, FILE* fptr) {
		int flag = true;
		if (fscanf(fptr, ",%d\n", &value) != 1) {
			flag = false;
		}
		return flag;
	}



	void display(void) {
		int totalPop = 0;
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sortData(); // The sorting function
		
		for (int i = 0; i < Records; i++) {
			cout << i + 1 << "- " << popData[i].m_code << ":  " << *popData[i].m_value << endl;
			totalPop += *popData[i].m_value;
		}

		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPop << endl;
	}
	

	 //The sorting function
	void sortData(void){

		int i; // For loop
		int j; // For inner loop
		int index;  // To keep track of the index with highest value in population
		Population* temp{};
		temp = new Population;  // To perform the sorting

		for (i = 0; i < Records; i++) {


			for (j = i, index = j; j < Records - 1 ; j++) {  // To find the biggest value from the array

				if (*popData[index].m_value > *popData[j + 1].m_value) {  // If some other smaller value is found 
					index = j + 1;
				}
				else if (*popData[index].m_value == *popData[j + 1].m_value) {    // If the values are same 
					int flag = 0;
					for (int k = 0; k < 3 && flag == 0; k++) {
						if (int(popData[index].m_code[k]) > int(popData[j + 1].m_code[k])) {  // Checking the letters
							index = j + 1;
							flag++;
						}
						else if (int(popData[index].m_code[k]) < int(popData[j + 1].m_code[k])) {
							flag++;
						}
					}
				}
			}

			if (index != i) {
				temp->m_code = popData[index].m_code;
				temp->m_value = popData[index].m_value;

				popData[index].m_code = popData[i].m_code;
				popData[index].m_value = popData[i].m_value;

				popData[i].m_code = temp->m_code;
				popData[i].m_value = temp->m_value;
			}

		}
		delete temp;

	}

	void deallocateMemory() {
		for (int i = 0; i < Records; i++) {
			delete popData[i].m_value;
			delete[] popData[i].m_code;
		}
		delete[] popData;
	}

}