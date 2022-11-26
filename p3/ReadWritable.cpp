/* Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: menu.cpp
Version 1.1
Author	Krinskumar Bhaveshkumar Vaghasia
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/24  Preliminary release
2022/11/24  Added Citation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include "ReadWritable.h"

namespace sdds {

    sdds::ReadWritable::ReadWritable() {
        m_isComma = false;
    }

    sdds::ReadWritable::~ReadWritable() {

    }

    bool ReadWritable::isCsv() const {
        return m_isComma;
    }

    void ReadWritable::setCsv(bool value) {
        m_isComma = value;
    }

    std::istream& operator>>(std::istream& istr, ReadWritable& readWrite) {
        return readWrite.read(istr);
    }

    std::ostream& operator<<(std::ostream& ostr, const ReadWritable& readWrite)  {
        return readWrite.write(ostr);
    }
}
