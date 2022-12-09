/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: menu.cpp
Version 1.1
Author	Krinskumar Bhaveshkumar Vaghasia
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/17  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include <fstream>
#include "Parking.h"
#include "Utils.h"
#include "Motorcycle.h"
#include "Vehicle.h"
#include "Car.h"
using namespace std;

namespace sdds {

    void Parking::returnVehical() {
        bool loopFlag = true;
        cout << "Return Vehicle" << endl;
        cout << "Enter License Plate Number: ";
        char temp[100];
        do {    // gets Licence plate number
            cin >> temp;
            if (ut.strlen(temp) <= 8) {
                loopFlag = false;
            }
            else { std::cout << "Invalid Licence Plate, try again: "; }
        } while (loopFlag); 

        char tempCap[10];
        int i;
        for (i = 0; i < ut.strlen(temp); i++) {
            tempCap[i] = ut.toupper(temp[i]);
        }
        tempCap[i] = '\0';
        
        loopFlag = true;
        for (i = 0; i < maxSpots && loopFlag; i++) {    // seraches for the Licence plate
            if (m_vehicalArray[i] != nullptr) {
                if (*m_vehicalArray[i] == temp) {
                    loopFlag = false;
                    cout << endl << "Returning:" << endl;
                    m_vehicalArray[i]->setCsv(false);
                    m_vehicalArray[i]->write();
                    delete m_vehicalArray[i];
                    m_vehicalArray[i] = nullptr;
                    m_spotsTaken--;
                    m_SpotsAvailable++;
                }
            }   
        }

        if (i == maxSpots) {    // makes sure that the plate was found
            cout << endl << "License plate " << tempCap << " Not found" << endl;
        }

        cout << endl << "Press <ENTER> to continue...." << endl;
    }

    void Parking::listParkedVehicals() {
        cout << "*** List of parked vehicles ***";
        for (int i = 0; i < maxSpots; i++) {
            if (m_vehicalArray[i] != nullptr) {
                cout << endl;
                m_vehicalArray[i]->setCsv(false);
                m_vehicalArray[i]->write();
                cout << "-------------------------------";
            }
        }
        cout << endl << "Press <ENTER> to continue...." << endl;
    }

    void Parking::findVehical() {
        cout << "Vehicle Search" << endl;
        bool loopFlag = true;
        cout << "Enter Licence Plate Number: ";
        char temp[10];
        do {    // gets Licence plate number
            cin >> temp;
            if (ut.strlen(temp) <= 8) {
                loopFlag = false;
            }
            else { std::cout << "Invalid Licence Plate, try again: "; }
        } while (loopFlag);
            
        char tempCap[10];
        int i;
        for (i = 0; i < ut.strlen(temp); i++) {
            tempCap[i] = ut.toupper(temp[i]);
        }
        tempCap[i] = '\0';

        loopFlag = true;
        for (i = 0; i < maxSpots && loopFlag; i++) {    // seraches for the Licence plate
            if (m_vehicalArray[i] != nullptr) {
                if (*m_vehicalArray[i] == tempCap) {
                    loopFlag = false;
                    cout << endl << "Vehicle found:" << endl;
                    m_vehicalArray[i]->setCsv(false);
                    m_vehicalArray[i]->write();
                    cout << endl;
                }
            }
        }

        if (i == maxSpots) {    // makes sure that the plate was found
            cout << endl << "License plate " << tempCap << " Not found" << endl << endl;
        }

        cout << "Press <ENTER> to continue...." << endl;
    }

    bool Parking::closeParking() {
        bool returnFlag = true;
        
        if (!m_isClassValid) {
            cout << "Closing Parking" << endl << endl;
        }
        else {
            char userSelection;
            bool flag1 = true;
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: "; 
            do {
                cin >> userSelection;
                if (cin.fail()) {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry:";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else {
                    if (userSelection == 'y' || userSelection == 'Y' || userSelection == 'n' || userSelection == 'N') {
                        flag1 = false;
                    }
                    else cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            } while (flag1);
            
            // userSelection is the response
            if (userSelection == 'n' || userSelection == 'N') {
                returnFlag = false;
            }
            else {
                cout << "Closing Parking" << endl;
                for (int i = 0; i < maxSpots; i++) { 
                    if (m_vehicalArray[i] != nullptr) {
                        cout << endl;
                        cout << "Towing request" << endl;
                        cout << "*********************" << endl;
                        m_vehicalArray[i]->setCsv(false);
                        m_vehicalArray[i]->write();
                        delete m_vehicalArray[i];
                        m_vehicalArray[i] = nullptr;
                    }
                }
                returnFlag = true;
            }
        }
        return returnFlag;
    }

    bool Parking::exitParkingApp() {
        char userSelection;    // stores the user selection
        bool flag1 = true;    //  flag for the loop
        bool returnFlag;
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        do {
            cin >> userSelection;
            if (cin.fail()) {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                if (userSelection == 'y' || userSelection == 'Y') {
                    flag1 = false;
                    returnFlag = true;
                } else if (userSelection == 'n' || userSelection == 'N') {
                    flag1 = false;
                    returnFlag = false;
                } else cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        } while (flag1);
        return returnFlag;
    }

    bool Parking::loadDataFile() {
        bool flag1 = true;
        if (m_isClassValid) {
            ifstream file (m_fileName, ifstream::in);

            if (file.is_open()) {
                bool flagLoop = true;
                do {
                    char vehicalType;
                    file >> vehicalType;
                    file.ignore();
                    if (vehicalType == 'M') {
                        Vehicle* tempVehicle = new Motorcycle;
                        tempVehicle->setCsv(true);
                        tempVehicle->read(file);
                        m_vehicalArray[tempVehicle->getParkingSpot() - 1] = tempVehicle;
                        m_spotsTaken++;
                        m_SpotsAvailable--;
                    }
                    else if (vehicalType == 'C') {
                        Vehicle* tempVehicle = new Car;
                        tempVehicle->setCsv(true);
                        tempVehicle->read(file);
                        m_vehicalArray[tempVehicle->getParkingSpot() - 1] = tempVehicle;
                        m_spotsTaken++;
                        m_SpotsAvailable--;
                    }
                    else {
                        flagLoop = false;
                    }
                    vehicalType = ' ';
                } while (flagLoop && m_spotsTaken < maxSpots);
            }
        }
        return flag1;
    }

    void Parking::saveDataFile() {
        if (m_isClassValid) {
            ofstream file(m_fileName);
            if (file.is_open()) {
                for (int i = 0; i < maxSpots; i++) {
                    if (m_vehicalArray[i] != nullptr) {
                        m_vehicalArray[i]->setCsv(true);
                        m_vehicalArray[i]->write(file);
                    }
                }
            }
        }
    }

    Parking::Parking(const char* filePath, int noOfSpots) {
        m_isClassValid = false;
        // set the file path
        if (!(noOfSpots < 10 || noOfSpots > maxSpots)) {
            m_SpotsAvailable = noOfSpots;
            if (filePath != nullptr) {
                for (int i = 0; i < maxSpots; i++) {
                    m_vehicalArray[i] = nullptr;
                }
                if (ut.strcmp(filePath, "")) {
                    m_isClassValid = true;
                    m_fileName = new char[ut.strlen(filePath) + 1];    // allocates the memory
                    ut.strcpy(m_fileName, filePath);    // assigns the allocated memory
                    if (loadDataFile()) {
                    // initialises the main parking menu
                    m_parkingMenu = { "Parking Menu, select an action:", 0 };
                    m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" <<
                        "Close Parking (End of day)" << "Exit Program";
                    // initilises the menu for the first option 
                    m_vehicalSelection = { "Select type of the vehicle:", 1 };
                    m_vehicalSelection << "Car" << "Motorcycle" << "Cancel";
                    } else {
                        cout << "Error in data file" << endl;
                        m_isClassValid = false;
                    } 
                } else cout << "Error in data file" << endl;
            } else cout << "Error in data file" << endl;
        }
    }

    Parking::~Parking() {
        saveDataFile();
        delete[] m_fileName;
        for (int i = 0; i < maxSpots; i++) {
            delete m_vehicalArray[i];
        }
    }

    int Parking::run() {
        int returnInt = 1;  // return this number
        if (m_isClassValid) {
            bool flag1 = true; // for the loop
            int selection; // to store users input
            returnInt--;
            do {
                parkingStatus();
                selection = m_parkingMenu.run();
                switch (selection) {
                    case 1:
                        parkVehical();
                        break;
                    case 2:
                        returnVehical();
                        break;
                    case 3:
                        listParkedVehicals();
                        break;
                    case 4:
                        findVehical();
                        break;
                    case 5:
                        if (closeParking()) {
                            flag1 = false;
                        }
                        break;
                    case 6:
                        if (exitParkingApp()) {
                            flag1 = false;
                            cout << "Exiting program!" << endl;
                        }
                        break;
                }
            } while (flag1);
        }
        return returnInt;
    }

    bool Parking::isEmpty() const {
        return m_isClassValid;
    }

    void Parking::parkingStatus() {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.width(4);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << m_SpotsAvailable;
        cout.unsetf(ios::left);
        cout << " *****";
        cout << endl;
    }
   
    void Parking::parkVehical() {
        bool readFlag = true;
        Vehicle* tempVehicle{};
        if (m_spotsTaken == maxSpots) {
            cout << "Parking is full";
        }
        else {
            int selection = m_vehicalSelection.run();
            switch (selection) {
            case 1:
                tempVehicle = new Car;
                break;
            case 2:
                tempVehicle = new Motorcycle;
                break;
            case 3:
                cout << "Parking Cancelled" << endl;
                readFlag = false;
                break;
            }

            if (readFlag) {    // if exit was not selected
                tempVehicle->setCsv(false);
                tempVehicle->read();

                bool loopFlag = true;  // finds a spot for the new vehical which is nullptr
                for (int i = 0; i < maxSpots && loopFlag; i++) {
                    if (m_vehicalArray[i] == nullptr) {
                        tempVehicle->setParkingSpot(i + 1);
                        m_vehicalArray[i] = tempVehicle;
                        loopFlag = false;
                    }
                }

                cout << endl << "Parking Ticket" << endl;
                tempVehicle->write();
                cout << endl << "Press <ENTER> to continue...." << endl;
            }
        }
    }
}