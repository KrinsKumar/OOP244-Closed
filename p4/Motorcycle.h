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