#ifndef _SDDS_PARKING_H_
#define _SDDS_PARKING_H_

namespace sdds {
   
   class Parking {
      char* m_fileName;
      Menu m_parkingMenu;
      Menu m_vehicalSelection;
      bool m_isClassValid;
      
      public:
         Parking(const char* filePath);
         ~Parking();
   };

}

#endif // !_SDDS_PARKING_H_   