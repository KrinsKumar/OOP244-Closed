#include "Line.h"

namespace sdds {

    Line::Line() {
        m_length = 0;
    }

    Line::Line(const char* Cstring, const int length): LblShape(Cstring) {
        m_length = length;
    }

    void Line::draw(std::ostream& os) const {

    }

    void Line::getSpecs(std::istream& is) {
         LblShape::getSpecs(is);
         is >> m_length;
         is.ignore(1000, '\n');
    }


}