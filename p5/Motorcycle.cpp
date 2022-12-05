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
#include "Motorcycle.h"
#include "Utils.h"

namespace sdds {
    Motorcycle::Motorcycle() : Vehicle() {
        m_hasSideCar = false;
    }

    Motorcycle::Motorcycle(const char* license, const char* makeModel) : Vehicle(license, makeModel) {
        m_hasSideCar = false;
    }

    Motorcycle::Motorcycle(const Motorcycle& motorRight) {
        m_hasSideCar = false;
        *this = motorRight;
    }

    Motorcycle& Motorcycle::operator=(const Motorcycle& motorRight) {
        m_hasSideCar = motorRight.m_hasSideCar;
        Vehicle::operator=(motorRight);
        return *this;
    }

    std::ostream& Motorcycle::writeType(std::ostream& ostr) const {
        if (ReadWritable::isCsv()) {
            ostr << "M,";
        }
        else {
            ostr << "Vehicle type: Motorcycle";
            ostr << std::endl;
        }
        return ostr;
    }

    std::istream& Motorcycle::read(std::istream& istr) {
        if (ReadWritable::isCsv()) {
            Vehicle::read(istr);
            istr >> m_hasSideCar;
            istr.ignore(1000, '\n');
        }
        else {
            std::cout << std::endl << "Motorcycle information entry" << std::endl;
            Vehicle::read();
            std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            char userAnswear[100];
            bool loopFlag = true;
            while (loopFlag) {
                istr >> userAnswear; 
                int length = ut.strlen(userAnswear);
                char upperAnswear = ut.toupper(userAnswear[0]);
                if (length != 1) {
                    std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                } else if (upperAnswear == 'N') {
                    loopFlag = false;
                    m_hasSideCar = false;
                }
                else if (upperAnswear == 'Y') {
                    loopFlag = false;
                    m_hasSideCar = true;
                }
                else std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
        return istr;
    }

    std::ostream& Motorcycle::write(std::ostream& ostr) const {
        if (Vehicle::isEmpty()) ostr << "Invalid Motorcycle Object" << std::endl;
        else {
            if (Vehicle::isCsv()) {
                Vehicle::write(ostr);
                ostr << m_hasSideCar << std::endl;
            }
            else {
                Vehicle::write(ostr);
                if (m_hasSideCar) ostr << "With Sidecar" << std::endl;
            }
        }
        return ostr;
    }

}