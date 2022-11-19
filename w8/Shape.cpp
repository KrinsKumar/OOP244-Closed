#include "Shape.h"

namespace sdds {
    Shape::~Shape() {}
    std::istream& operator>>(std::istream& is, Shape& baseShape) {
        //baseShape.getSpecs(is);
        return is;
    }

    std::ostream& operator<<(std::ostream& os, Shape& baseShape) {
        //baseShape.draw(os);
        return os;
    }

}