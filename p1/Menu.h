// menu menuItem
// menu < memuItem
#ifndef _SDDS_MENU_H_
#define _SDDS_MENU_H_

namespace sdds {

   const int MAX_NO_OF_ITEMS = 10;

   class MenuItem {
      //char m_item[50];
     // bool m_valid;    // class is invalid if this is false
      //friend class Menu;

     // MenuItem();
      MenuItem(const char item[]);

      //MenuItem& operator=(const MenuItem& rightMenuItem);
     // std::ostream& display(std::ostream& ost = std::cout)const;   // displayes the values
   };

   // helper functions for MenuItem
  // std::ostream& operator<<(std::ostream& ost, const MenuItem leftItem);    // calls the display function


   /*class Menu {
      char m_title[50];
      int m_totalItems;
      int m_indentation;
      MenuItem m_menuItem[MAX_NO_OF_ITEMS];
   
      public:
         Menu(const char title[], int indentation = 1);
   }*/;
}

#endif // !_SDDS_MENU_H_