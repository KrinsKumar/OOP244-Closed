/*
Name: Krinskumar Bhaveshkumar Vaghasia
Email: kvaghasia@myseneca.ca
Student ID: 169722212
Data: 11th November 2022
Section: Lab - Workshop 7
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

