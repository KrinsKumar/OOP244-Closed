/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: menu.cpp
Version 1.1
Author	Krinskumar Bhaveshkumar Vaghasia
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/17  Preliminary release
2022/12/01  Added Citation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef _SDDS_PARKING_H_
#define _SDDS_PARKING_H_
#include "Menu.h"
namespace sdds {

   class Parking {
      char* m_fileName{};
      Menu m_parkingMenu;
      Menu m_vehicalSelection;
      bool m_isClassValid;    // true if the class is valid

      bool isEmpty() const;
      void parkingStatus();    // not yet implimented
      void parkVehical();    // handles the first option of the main menu
      void returnVehical();    // handles the second option
      void listParkedVehicals();
      void findVehical();
      bool closeParking();    // handles the fifth option
      bool exitParkingApp();
      bool loadDataFile();
      void saveDataFile();

      public:
         Parking(const char* filePath);
         ~Parking();
         Parking(const Parking& anotherParkingMenu) = delete;
         int run();
   };

}

#endif // !_SDDS_PARKING_H_   