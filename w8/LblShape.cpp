//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"

namespace sdds {

    LblShape::LblShape() {
        
    }

    const char* LblShape::lable() const {
        return m_label;
    }

    LblShape::LblShape(const char* Cstring) {
        m_label = new char[strlen(Cstring) + 1];
        strcpy(m_label, Cstring); 
    }

    LblShape::~LblShape() {
        delete [] m_label;
    }

    void LblShape::getSpecs(std::istream& is) {
        char tempString[100];
        delete[] m_label;
        is.getline(tempString, 50,  ',');
        m_label = new char[strlen(tempString) + 1];
        strcpy(m_label, tempString);
    }

}