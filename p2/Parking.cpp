#include "Parking.h"
#include "Menu.h"
#include "Utils.h"

using namespace sdds;

namespace sdds {
   Parking::Parking(const char* filePath) {
      m_isClassValid = false;
      
      // initialises the main parking menu
      m_parkingMenu = { "Parking Menu, select an action:", 0 };
      m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" <<
                       "Close Parking (End of day)" << "Exit Program";

      // initilises the menu for the first option 
      m_vehicalSelection = { "Select type of the vehicle:", 1 };
      m_vehicalSelection << "Car" << "Motorcycle" << "Cancel";

      // set the file path
      if (filePath != nullptr) {
         m_isClassValid = true;
         m_fileName = new char[strlen(filePath)];
      }
   }

   Parking::~Parking() {
      delete[] m_fileName;
   }

}