/* Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: menu.cpp
Version 1.1
Author	Krinskumar Bhaveshkumar Vaghasia
Revision History
-----------------------------------------------------------
Date      Reason
2022/12/01  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef _SDDS_MOTORCYCLE_H_
#define _SDDS_MOTORCYCLE_H_

#include "Vehicle.h"

namespace sdds {

    class Motorcycle : public Vehicle {
        private:
            bool m_hasSideCar;
        public:
            Motorcycle();
            Motorcycle(const char* license, const char* makeModel);
            Motorcycle(const Motorcycle& motorRight);

            Motorcycle& operator=(const Motorcycle& motorRight);
            virtual std::ostream& writeType(std::ostream& ostr = std::cout) const;

            virtual std::istream& read(std::istream& istr = std::cin);
            virtual std::ostream& write(std::ostream& ostr = std::cout) const;
    };

}

#endif // _SDDS_MOTORCYCLE_H_