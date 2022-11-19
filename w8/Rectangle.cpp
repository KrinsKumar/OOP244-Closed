//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Rectangle.h"
#include <cstring>

namespace sdds {

    sdds::Rectangle::Rectangle(): LblShape() {
        m_height = 0;
        m_width = 0;
    }

    sdds::Rectangle::Rectangle(const char* Cstring, const int width, const int height): LblShape(Cstring) {
        if (height < 3 || int(strlen(Cstring) + 2) > width) {
            m_height = 0;
            m_width = 0;
        } else {
            m_height = height;
            m_width = width;
            m_empty = false;
        }
    }

    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
        m_empty = false;
    }

    void Rectangle::draw(std::ostream& os) const {
        if (!m_empty) {
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os.setf(std::ios::left);
            os << '-';
            os.unsetf(std::ios::left);
            os << '+' << std::endl;

            for (int i = 0; i < m_height - 2; i++) {
                os << '|';
                if (i == 0) {
                    os.width(m_width - 2);
                    os.fill(' ');
                    os.setf(std::ios::left);
                    os << LblShape::lable();
                    os.unsetf(std::ios::left);
                } else {
                    os.width(m_width - 2);
                    os.fill(' ');
                    os.setf(std::ios::left);
                    os << ' ';
                    os.unsetf(std::ios::left);
                }
                os << '|';
                os << std::endl;
            }

            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os.setf(std::ios::left);
            os << '-';
            os.unsetf(std::ios::left);
            os << '+';
        }
    }
}
