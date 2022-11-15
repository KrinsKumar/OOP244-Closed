#include <iostream>
#include "Menu.h"
#include "Parking.h"
#include "Utils.h"
using namespace std;

namespace sdds {

   void Parking::returnVehical() {
      cout << "---------------------------------" << endl;
      cout << "Returning Vehicle" << endl;
      cout << "---------------------------------" << endl;
   }

   void Parking::listParkedVehicals() {
      cout << "---------------------------------" << endl;
      cout << "Listing Parked Vehicles" << endl;
      cout << "---------------------------------" << endl;
   }

   bool Parking::closeParking() {
      char userSelection;
      bool flag1 = true;
      cout << "This will close the parking; All the vehicles will be removed!" << endl;
      cout << "Are you sure? (Y)es/(N)o:" << endl;
      do {
         cin >> userSelection;
         if (cin.fail()) {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry:";
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            if (userSelection == 'y' || userSelection == 'Y' || userSelection == 'n' || userSelection == 'N') {

            }
         }
      } while (flag1);
      return userSelection;
   }

   bool Parking::exitParkingApp() {
      return false;
   }

   bool Parking::loadDataFile() {
      return false;
   }

   void Parking::saveDataFile() {
   
   }

   Parking::Parking(const char* filePath) {

      m_isClassValid = false;
      m_fileName = nullptr;

      // set the file path
      if (filePath != nullptr) {
         m_isClassValid = true;
         m_fileName = new char[strlen(filePath)];    // allocates the memory
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
      }
   }

   Parking::~Parking() {
      saveDataFile();
      delete[] m_fileName;
   }

   int Parking::run() {
      return 0;
   }

   bool Parking::isEmpty() const {
      return m_isClassValid;
   }

   void Parking::parkingStatus() {
      cout << "****** Valet Parking ******" << endl;
   }

   void Parking::parkVehical() {
      int selection = m_vehicalSelection.run();
      if (selection == 1) {
         cout << "---------------------------------" << endl;
         cout << "Parking Car" << endl;
         cout << "---------------------------------" << endl;
      }
      if (selection == 1) {
         cout << "---------------------------------" << endl;
         cout << "Parking Motorcycle" << endl;
         cout << "---------------------------------" << endl;
      }
      if (selection == 1) {
         cout << "---------------------------------" << endl;
         cout << "Parking parking" << endl;
         cout << "---------------------------------" << endl;
      }
   }


}