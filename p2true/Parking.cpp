#include "Parking.h"
#include "Utils.h"
using namespace std;

namespace sdds {

    void Parking::returnVehical() {
        cout << "---------------------------------" << endl;
        cout << "Returning Vehicle" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }

    void Parking::listParkedVehicals() {
        cout << "---------------------------------" << endl;
        cout << "Listing Parked Vehicles" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }

    void Parking::findVehical() {
        cout << "---------------------------------" << endl;
        cout << "Finding a Vehicle" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }

    bool Parking::closeParking() {
        char userSelection;
        bool flag1 = true;
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
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
                } else cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        } while (flag1);
        return userSelection;
    }

    bool Parking::exitParkingApp() {
        char userSelection;    // stores the user selection
        bool flag1 = true;    //  flag for the loop
        bool returnFlag;
        cout << "This will terminate the application and save the data!" << endl;
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
        bool flag1 = false;
        if (m_isClassValid) {
            flag1 = true;
            cout << "---------------------------------" << endl;
            cout << "loading data from " << m_fileName << endl;
            cout << "---------------------------------" << endl << endl;
        }
        return flag1;
    }

    void Parking::saveDataFile() {
        if (m_isClassValid) {
            cout << "---------------------------------" << endl;
            cout << "Saving data into " << m_fileName << endl;
            cout << "---------------------------------" << endl;
        }
    }

    Parking::Parking(const char* filePath) {
        m_isClassValid = false;
        // set the file path
        if (filePath != nullptr) {
            if (strcmp(filePath, "")) {
                m_isClassValid = true;
                m_fileName = new char[strlen(filePath) + 1];    // allocates the memory
                strcpy(m_fileName, filePath);    // assigns the allocated memory
                if (loadDataFile()) {
                // initialises the main parking menu
                m_parkingMenu = { "Parking Menu, select an action:", 0 };
                m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" <<
                    "Close Parking (End of day)" << "Exit Program";
                // initilises the menu for the first option 
                m_vehicalSelection = { "Select type of the vehicle:", 1 };
                m_vehicalSelection << "Car" << "Motorcycle" << "Cancel";
                }
                else {
                    cout << "Error in data file" << endl;
                    m_isClassValid = false;
                }
            } else cout << "Error in data file" << endl;
        } else cout << "Error in data file" << endl;
        
    }

    Parking::~Parking() {
        saveDataFile();
        delete[] m_fileName;
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
                            cout << "Ending application!" << endl;
                        }
                        break;
                    case 6:
                        if (exitParkingApp()) {
                            flag1 = false;
                            cout << "Exiting application!" << endl;
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
    }
   
    void Parking::parkVehical() {
        int selection = m_vehicalSelection.run();
        switch (selection) {
            case 1:
                cout << "---------------------------------" << endl;
                cout << "Parking Car" << endl;
                cout << "---------------------------------" << endl;
                break;
            case 2:
                cout << "---------------------------------" << endl;
                cout << "Parking Motorcycle" << endl;
                cout << "---------------------------------" << endl;
                break;
            case 3:
                cout << "---------------------------------" << endl;
                cout << "Cancelled parking" << endl;
                cout << "---------------------------------" << endl;
                break;
        }
        cout << endl;
    }
}