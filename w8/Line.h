//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_LINE_H_
#define _SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {

    class Line: public LblShape {
        private:
            int m_length;
        public:
         Line();
         void draw(std::ostream& os) const;
         void getSpecs(std::istream& is);
         Line(const char* Cstring,const int length);

    };

}

#endif // !_SDDS_LINE_H_
