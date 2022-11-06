#ifndef _SDDS_MENU_H_
#define _SDDS_MENU_H_

namespace sdds {

   const int MAX_NO_OF_ITEMS = 10;

   class MenuItem {
      char m_item[50];
      bool m_valid;    // class is invalid if this is false
      friend class Menu;

      MenuItem();
      MenuItem(const char item[]);
      MenuItem(const MenuItem& Item) = delete;

      std::ostream& display(std::ostream& ost = std::cout)const; 
   };
   // helper function for 
   //std::ostream& operator<<(std::ostream& ost, const MenuItem leftItem);


   class Menu {
      char m_title[50];
      int m_totalItems;
      int m_indentation;
      bool m_valid;
      MenuItem m_menuItems[MAX_NO_OF_ITEMS];

      public:
         Menu();
         Menu(const char title[], int indentation = 0);
         Menu(const Menu& menu) = delete;
         operator bool() const;
         operator int() const;

         Menu& operator=(const char title[]);    // updates the title of the class
         Menu& operator<<(const char title[]);
         
         bool isEmpty() const;
         std::ostream& display(std::ostream& ost = std::cout)const;
         void add(const char item[]);
         int run() const;
         void clear();
   };
}

#endif // !_SDDS_MENU_H_   