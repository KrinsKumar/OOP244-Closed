//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Line.h"

namespace sdds {

    Line::Line(): LblShape() {
        m_length = 0;
    }

    Line::Line(const char* Cstring, const int length): LblShape(Cstring) {
        m_length = length;
    }

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && LblShape::lable() != NULL) {
            os.width(m_length);
            os.fill('=');
            os.setf(std::ios::left);
            os << LblShape::lable();
            os.unsetf(std::ios::left);
        }
    }


}