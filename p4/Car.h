#ifndef _SDDS_CAR_H_
#define _SDDS_CAR_H_

#include "Vehicle.h"

namespace sdds {

    class Car : public Vehicle {
        private:
            bool m_carWash;
        public:
            Car();
            Car(const char* license, const char* makeModel);
            Car(const Car& carRight);

            Car& operator=(const Car& carRight);
            virtual std::ostream& writeType(std::ostream& ostr = std::cout) const;

            virtual std::istream& read(std::istream& istr = std::cin);
            virtual std::ostream& write(std::ostream& ostr = std::cout) const;
    };

}

#endif // _SDDS_CAR_H_
