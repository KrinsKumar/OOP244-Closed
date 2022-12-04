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
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {

   MenuItem::MenuItem() {
      m_valid = false;
      ut.strcpy(m_item, "");
   }

   MenuItem::MenuItem(const char item[]) {
      m_valid = false;
      ut.strcpy(m_item, "");
      if (item != NULL) {
          ut.strcpy(m_item, item);   // copies the arguement in the class
         m_valid = true;
      }
   }

   std::ostream& MenuItem::display(std::ostream& ost) const {
      if (m_valid) {
         ost << m_item << endl;
      }
      return ost;
   }
 
 //======================================================================================

   Menu::Menu() {
      m_indentation = 0;
      m_totalItems = 0;
      ut.strcpy(m_title, "");
      m_valid = false;
   }

   Menu::Menu(const char title[], int indentation) {
      m_indentation = indentation;
      m_totalItems = 0;
      ut.strcpy(m_title, "");
      m_valid = false;
      if (title != NULL) {
          ut.strcpy(m_title, title);
         m_valid = true;
      }
   }

   Menu::operator bool() const {
      return m_valid;
   }

   Menu::operator int() const {
      return run();
   }

   Menu& Menu::operator=(const char title[]) {
      if (title != NULL) {
          ut.strcpy(m_title, title);
         m_valid = true;
      }
      else {
          ut.strcpy(m_title, "");
         m_valid = true;
      }
      return *this;
   }

   Menu& Menu::operator<<(const char title[]) {
      add(title);
      return *this;
   }

   bool Menu::isEmpty() const{
      return !m_valid;
   }

   std::ostream& Menu::display(std::ostream& ost) const{
      if (m_valid) {
         if (m_indentation != 0) {
            for (int j = 0; j < m_indentation; j++) {
               ost << "    ";
            }
         }
         ost << m_title << endl;
         if (m_totalItems == 0) {
            ost << "No Items to display!" << endl;
         }
         else {
            for (int i = 0; i < m_totalItems; i++) {
               if (m_indentation != 0) {
                  for (int j = 0; j < m_indentation; j++) {
                     ost << "    ";
                  }
               }
               ost << (i+1) << "- ";
               m_menuItems[i].display();
            }
            for (int j = 0; j < m_indentation; j++) {
               ost << "    ";
            }
            ost << "> ";
         }
      }
      else {
         ost << "Invalid Menu!" << endl;
      }
      return ost;
   }

   void Menu::add(const char item[]) {
      if (m_valid) {
         if (item != NULL) {
            if (m_totalItems < MAX_NO_OF_ITEMS) {
               m_menuItems[m_totalItems] = item;
               m_totalItems++;
            }
         }
         else {
            m_valid = false;
         }
      }
   }

   int Menu::run() const {
      int userResponse;
      display();
      if (m_totalItems == 0 || !m_valid) {
         userResponse = 0;
      } else {
         do {
            cin >> userResponse;
            while (cin.fail()) {
               cout << "Invalid Integer, try again: ";
               cin.clear();
               cin.ignore(1000, '\n');
               cin >> userResponse;
            }
            if (userResponse > m_totalItems || userResponse < 1) {
               cout << "Invalid selection, try again: ";
            }
         } while (userResponse > m_totalItems || userResponse < 1);
         cin.clear();
         cin.ignore(1000, '\n');
      }
      return userResponse;
   }

   void Menu::clear() {
      for (int i = 0; i < m_totalItems; i++) {
         MenuItem temp;
         m_menuItems[i] = temp;
      }
      m_totalItems = 0;
   }


}