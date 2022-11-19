#include "Rectangle.h"

namespace sdds {

    sdds::Rectangle::Rectangle(): LblShape() {
        m_height = 0;
        m_width = 0;
    }

    sdds::Rectangle::Rectangle(const char* Cstring, const int width, const int height): LblShape(Cstring) {
        if (height < 3 || strlen(Cstring) + 2 > width) {
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
    }

    void Rectangle::draw(std::ostream& os) const {
        if (!m_empty) {
            os << '+';
            os.width(m_height - 2);
            os.fill('-');
            os.setf(std::ios::left);
            os << '-';
            os.unsetf(std::ios::left);
            os << '+';

            for (int i = 0; i < m_height - 2; i++) {
                os << '|';
                if (i == 0) {
                    os.width(m_height - 2);
                    os.fill(' ');
                    os.setf(std::ios::left);
                    os << LblShape::lable();
                    os.unsetf(std::ios::left);
                } else {
                    os.width(m_height - 2);
                    os.fill(' ');
                    os.setf(std::ios::left);
                    os << ' ';
                    os.unsetf(std::ios::left);
                }
                os << '|';
            }

            os << '+';
            os.width(m_height - 2);
            os.fill('-');
            os.setf(std::ios::left);
            os << '-';
            os.unsetf(std::ios::left);
            os << '+';
        }
    }
}
