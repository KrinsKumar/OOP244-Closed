/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File  File.cpp
// Version 1.0
// Date  2022/09/17
// Author   Fardad Soleimanloo
// Description
// This file is incomplete and to be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 26-Sept=2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

namespace sdds {
   FILE* fptr;
   // Opens a file and keeps the file pointer in the File.cpp (file scope)
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   // Finds and returns the number of records kept in the file 
   // to be used for the dynamic memory allocation of the records in the program
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   // Closes the open file
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   FILE*& getFilePointer(void) {
	   return fptr;
   }

}