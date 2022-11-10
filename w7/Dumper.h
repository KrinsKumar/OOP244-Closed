/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{

    class Dumper :public VehicleBasic {
        float m_maxLoadWeight;
        float m_currentLoad;

        public: 
            Dumper(const char *licenseNumber, int buildYear, float capacity, const char* address);
            bool loaddCargo(double cargo);
            bool unloadCargo();
            std::ostream& write(std::ostream& os) const;
            std::istream& read(std::istream& is);
    };

    std::ostream& operator<<(std::ostream& os, const Dumper& printDumper);
    std::istream& operator>>(std::istream& is, Dumper& readDumper);

}
#endif

