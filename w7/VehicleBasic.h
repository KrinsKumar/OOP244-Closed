/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{

    class VehicalBasic {
        char m_licenseNumber[9];
        char m_address[64];
        int m_buildYear;

        public:
            VehicalBasic(const char licenseNumber[], const int buildYear);
            void NewAddress(const char* address);
            std::ostream& write(std::ostream& os) const;
            std::istream & read(std::istream & is);

    };

    std::ostream& operator<<(std::ostream& os, const VehicalBasic& printVehical);
    std::istream& operator>>(std::istream& is, VehicalBasic& readVehical);

}

#endif

