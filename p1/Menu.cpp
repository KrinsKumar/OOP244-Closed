#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {

   //MenuItem::MenuItem() {
   //   m_valid = false;
   //}

   MenuItem::MenuItem(const char item[]) {
      m_valid = true;
      if (item != nullptr) {
         strcpy(m_item, item);   // copies the arguement in the class
         m_valid = true;
      }
   }

   std::ostream& MenuItem::display(std::ostream& ost) const {
      if (m_valid) {
         ost << m_item << endl;
      }
      return ost;
   }

   MenuItem& MenuItem::operator=(const MenuItem& rightMenuItem) {
      MenuItem temp;
      return temp;   // returns a temp invalid instance of the class
   }


   //===========================================================================================

   std::ostream& operator<<(std::ostream, const MenuItem leftItem)
   {
      // // O: insert return statement here
   }

}
