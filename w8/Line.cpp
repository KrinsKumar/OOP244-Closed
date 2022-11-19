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
        if (m_length > 0 && LblShape::lable() == NULL) {
            os << LblShape::lable();
            os.width(m_length);
            os.fill('=');
            os.setf(std::ios::left);
            os << '=';
            os.unsetf(std::ios::left);
        }
    }


}