//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Shape.h"

namespace sdds {
    Shape::~Shape() {}

    std::istream& operator>>(std::istream& istr, Shape& baseShape) {
        baseShape.getSpecs(istr);
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Shape& baseShape) {
        baseShape.draw(ostr);
        return ostr;
    }

}