#ifndef _SDDS_PARKING_H_
#define _SDDS_PARKING_H_

namespace sdds {

   class Parking {
      char* m_fileName;
      Menu m_parkingMenu;
      Menu m_vehicalSelection;
      bool m_isClassValid;

      bool isEmpty() const;
      void parkingStatus();    // not yet implimented
      void parkVehical();    // handles the first option of the main menu
      void returnVehical();    // handles the second option
      void listParkedVehicals();
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