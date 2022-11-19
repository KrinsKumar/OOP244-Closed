//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_RECTANGLE_H_
#define _SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {

    class Rectangle : public LblShape {
        private:
            int m_width;
            int m_height;
            bool m_empty = true;    // true if the class is empty
        public:
            Rectangle();
            Rectangle(const char* Cstring, const int width, const int height);
            void getSpecs(std::istream& is);
            void draw(std::ostream& os) const;
    };

}

#endif // !_SDDS_LINE_H_
