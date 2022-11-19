//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_SHAPE_H_
#define _SDDS_SHAPE_H_
#include <iostream>

namespace sdds {

    class Shape {
        public:virtual ~Shape();
            virtual void draw(std::ostream& os) const = 0;
            virtual void getSpecs(std::istream& is) = 0;
    };
    std::istream& operator>>(std::istream& istr, Shape& baseShape);
    std::ostream& operator<<(std::ostream& ostr, const Shape& baseShape);
}

#endif // !_SDDS_SHAPE_H_
