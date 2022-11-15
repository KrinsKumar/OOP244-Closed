#define _CRT_SECURE_NO_WARNINGS
#include <string>
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
        is.getline(tempString, 50);
        m_label = new char[strlen(tempString) + 1];
        strcpy(m_label, tempString);
    }

}