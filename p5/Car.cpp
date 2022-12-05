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
#include "Car.h"
#include "Utils.h"

namespace sdds {

    Car::Car() : Vehicle() {    // the no arguement constructor sets the base class to safe invalid state
        m_carWash = false;
    }

    Car::Car(const char* license, const char* makeModel): Vehicle(license, makeModel) {
        m_carWash = false;
    }

    Car::Car(const Car& carRight) {
        m_carWash = false;
        *this = carRight;
    }

    Car& Car::operator=(const Car& carRight) {
        m_carWash = carRight.m_carWash;
        Vehicle::operator=(carRight);
        return *this;
    }

    std::ostream& Car::writeType(std::ostream& ostr) const {
        if (ReadWritable::isCsv()) {
            ostr << "C,";
        }
        else {
            ostr << "Vehicle type: Car";
            ostr << std::endl;
        }
        return ostr;
    }

    std::istream& Car::read(std::istream& istr) {
        if (ReadWritable::isCsv()) {
            Vehicle::read(istr);
            istr >> m_carWash;
            istr.ignore(1000, '\n');
        }
        else {
            std::cout << std::endl << "Car information entry" << std::endl;
            Vehicle::read();
            std::cout << "Carwash while parked? (Y)es/(N)o: ";
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
                    m_carWash = false;
                } else if (upperAnswear == 'Y') {
                    loopFlag = false;
                    m_carWash = true;
                } else std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
        return istr;
    }

    std::ostream& Car::write(std::ostream& ostr) const {
        if (Vehicle::isEmpty()) ostr << "Invalid Car Object" << std::endl;
        else {
            if (Vehicle::isCsv()) {
                Vehicle::write(ostr);
                ostr << m_carWash << std::endl;
            }
            else {
                Vehicle::write(ostr);
                if (m_carWash) ostr << "With Carwash" << std::endl;
            }
        }
        return ostr;
    }
    


}