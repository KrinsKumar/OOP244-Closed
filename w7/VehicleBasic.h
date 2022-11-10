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
    class VehicleBasic {
        char m_licenseNumber[9];
        char m_address[64];
        int m_buildYear;

        public:
            VehicleBasic(const char* licenseNumber, const int buildYear);
            void NewAddress(const char* address);
            std::ostream& write(std::ostream& os) const;
            std::istream & read(std::istream & is);

            void updateNumber(char* number);
            void updateAddress(char* address);
            void updateYear(int year);

    };
    std::ostream& operator<<(std::ostream& os, const VehicleBasic& printVehicle);
    std::istream& operator>>(std::istream& is, VehicleBasic& readVehicle);

}

#endif

