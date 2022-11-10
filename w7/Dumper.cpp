/*
Name:
Email:
Student ID:
Data:
Section:
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
    Dumper::Dumper(const char* licenseNumber, int buildYear, float capacity, const char* address)
    :VehicleBasic(licenseNumber, buildYear) {
        NewAddress(address);
        m_currentLoad = 0;
        m_maxLoadWeight = capacity;
    }

    bool Dumper::loaddCargo(double cargo) {
        bool load = false;
        if (cargo + m_currentLoad < m_maxLoadWeight) {
            load = true;
            m_currentLoad = cargo + m_currentLoad;
        }
        return load;
    }

    bool Dumper::unloadCargo() {
        bool unload = false;
        if (m_currentLoad != 0) {
            unload = true;
            m_currentLoad = 0;
        }
        return unload;
    }

    std::ostream& Dumper::write(std::ostream& os) const {
        VehicleBasic::write(os);
        os << " | " << m_currentLoad << "/" << m_maxLoadWeight;
        return os;
    }

    std::istream& Dumper::read(std::istream& is) {
        cout << "Built year: ";
        cin << updateYear();
        cout << "License plate: ";
        is >> m_licenseNumber;
        cout << "Current location: ";
        is >> m_address;

        return is;
    }
	
    std::ostream& operator<<(std::ostream& os, const Dumper& printDumper) {
        return printDumper.write(os);
    }

    std::istream& operator>>(std::istream& is, Dumper& readDumper) {
        return readDumper.read(is);
    }

}

