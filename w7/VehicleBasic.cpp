/*
Name: Krinskumar Bhaveshkumar Vaghasia
Email: kvaghasia@myseneca.ca
Student ID: 169722212
Data: 11th November 2022
Section: Lab - Workshop 7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{

    VehicleBasic::VehicleBasic(const char* licenseNumber, const int buildYear) {
        strcpy(m_licenseNumber, licenseNumber);
        m_buildYear = buildYear;
        strcpy(m_address, "Factory");
    }

    void VehicleBasic::NewAddress(const char* address)  {
        cout << "|";
        cout.fill(' ');
        cout.width(8);
        cout.setf(ios::right);
        cout << m_licenseNumber << "| |";
        cout.width(20);
        cout << m_address <<" ---> ";
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout.width(20);
        cout << address << "|" << endl;
        cout.unsetf(ios::left);


        strcpy(m_address, address);
    }

    std::ostream& VehicleBasic::write(std::ostream& os) const {
       os << "| " << m_buildYear << " | " << m_licenseNumber << " | " << m_address;
       return os;
    }

    std::istream& VehicleBasic::read(std::istream& is) {
        cout << "Built year: ";
        is >> m_buildYear;
        cout << "License plate: ";
        is >> m_licenseNumber;
        cout << "Current location: ";
        is >> m_address;
        return is;
    }

    void VehicleBasic::updateNumber(char* number) {
        strcpy(m_licenseNumber, number);
    }

    void VehicleBasic::updateAddress(char* address) {
        strcpy(m_address, address);
    }

    void VehicleBasic::updateYear(int year) {
        m_buildYear = year;
    }

    std::ostream& operator<<(std::ostream& os, const VehicleBasic& printVehicle){
        return printVehicle.write(os);
    }

    std::istream& operator>>(std::istream& is, VehicleBasic& readVehicle) {
        return readVehicle.read(is);
    }

}
