//Full Name : Krinskumar Bhaveshkumar Vaghasia
//Student ID# : 169722212
//Email : kvaghasia@myseneca.ca
//Date : 18-NOV-2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef _SDDS_LBLSHAPE_H_
#define _SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds {

    class LblShape: public Shape {
        private:
            char* m_label{};
        protected:
            const char* lable() const;
        public:
            LblShape();
            LblShape(const char* Cstring);
            ~LblShape();

            virtual void getSpecs(std::istream& is);

            // deleted members
            LblShape(const LblShape& tempShape) = delete;
            void operator=(const LblShape& tempShape) = delete;
    };

}

#endif // !_SDDS_LBLSHAPE_H_