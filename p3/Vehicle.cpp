/* Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: menu.cpp
Version 1.1
Author	Krinskumar Bhaveshkumar Vaghasia
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/24  Preliminary release
2022/11/24  Added Citation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include "Vehicle.h"
#include "Utils.h"

namespace sdds {

    sdds::Vehicle::Vehicle() {
        setEmpty();
    }

    sdds::Vehicle::Vehicle(const char* license, const char* makeModel) {
        if (license != NULL && makeModel != NULL && ut.strlen(license) <= 8 && ut.strlen(license) > 0 && 
            ut.strlen(makeModel) > 2) {
            m_parkingSpot = 0;
            ut.strcpy(m_license, license);
            m_makeModel = ut.alcpy(makeModel);
            m_isEmpty = false;
        } else setEmpty();
    }

    sdds::Vehicle::Vehicle(const Vehicle& leftVehicle) {
        *this = leftVehicle;
    }

    sdds::Vehicle::~Vehicle() {
        delete[] m_makeModel;
    }

    void Vehicle::setEmpty() {
        m_parkingSpot = 0;
        ut.strcpy(m_license, "");
        delete[] m_makeModel;
        m_makeModel = NULL;
        m_isEmpty = true;
    }

    bool Vehicle::isEmpty() const {
        return m_isEmpty;
    }

    const char* Vehicle::getLicensePlate() const {
        return m_license;
    }

    const char* Vehicle::getMakeModel() const {
        return m_makeModel;
    }

    void Vehicle::setMakeModel(const char* newMakeModel) {
        if (newMakeModel != NULL) {
            delete[] m_makeModel;
            m_makeModel = ut.alcpy(newMakeModel);
        } else setEmpty();
    }

    int Vehicle::getParkingSpot() const{
        return m_parkingSpot;
    }

    void Vehicle::setParkingSpot(int newSpot) {
        if (newSpot > 0) {
            m_parkingSpot = newSpot;
        } else setEmpty();
    }

    bool Vehicle::operator==(const char* licensePlate) const {
        bool returnFlag = true;
        for (int i = 0; i < ut.strlen(m_license) && returnFlag; i++) {
            if (ut.tolower(m_license[i]) != ut.tolower(licensePlate[i])) {
                returnFlag = false;
            }
        }
        return returnFlag;
    }

    bool Vehicle::operator==(const Vehicle& leftVehicle) const  {
        return *this == leftVehicle.m_license;
    }

    Vehicle& sdds::Vehicle::operator=(const Vehicle& leftVehicle) {
        m_isEmpty = false;
        ut.strcpy(m_license, leftVehicle.m_license);
        m_parkingSpot = leftVehicle.m_parkingSpot;
        m_makeModel = ut.alcpy(leftVehicle.m_makeModel);
        return *this;
    }

    std::istream& Vehicle::read(std::istream& istr) {
        if (isCsv()) {
            char temp[61];
            istr >> m_parkingSpot;
            istr.ignore();
            istr.getline(m_license, 8, ',');
            for (int i = 0; i < ut.strlen(m_license); i++) {    // saves the value in uppercase
                m_license[i] = ut.toupper(m_license[i]);
            }
            istr.getline(temp, 8, ',');
            setMakeModel(temp);    // allocates memory for the makemodel member of the class
            if (istr.fail()) {
                setEmpty();
                istr.clear();
                istr.ignore(1000, '\n');
            } else m_isEmpty = false;
        }
        else {
            bool loopFlag = true;
            std::cout << "Enter License Plate Number: ";
            do {    // gets license plate number
                char temp[100];
                istr >> temp;
                if (ut.strlen(temp) <= 8) {
                    loopFlag = false;
                    ut.strcpy(m_license, temp);
                }
                else {std::cout << "Invalid License Plate, try again: ";}
            } while (loopFlag); 

            for (int i = 0; i < ut.strlen(m_license); i++) {    // saves the value in uppercase
                m_license[i] = ut.toupper(m_license[i]);
            }

            loopFlag = true;
            std::cout << "Enter Make and Model: ";
            do {    // gets make and model
                char temp[100];
                istr >> temp;
                if (ut.strlen(temp) <= 60 && ut.strlen(temp) >= 2) { 
                    loopFlag = false;
                    setMakeModel(temp);
                }
                else { std::cout << "Invalid Make and model, try again: "; }
            } while (loopFlag);

            if (istr.fail()) {
                setEmpty();
                istr.clear();
                istr.ignore(1000, '\n');
            } else m_isEmpty = false;
            m_parkingSpot = 0;

        }
        return istr;
    }

    std::ostream& Vehicle::write(std::ostream& ostr) const {
        if (m_isEmpty) {
            ostr << "Invalid Vehicle Object" << std::endl;
        } else {
            writeType();
            if (isCsv()) {
                ostr << m_parkingSpot << ',' << m_license << ',' << m_makeModel << ',';
            }
            else {
                ostr << "Parking Spot Number: ";
                if (m_parkingSpot == 0) { ostr << "N/A";}
                else {ostr << m_parkingSpot;}

                ostr << std::endl << "License Plate: "<< m_license << std::endl;
                ostr << "Make and Model: " << m_makeModel << std::endl;
            }
        }
        return ostr;
    }
}

















