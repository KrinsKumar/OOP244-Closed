#include <iostream>
#include "basket.h"


using namespace std;

namespace sdds {

   Basket::Basket() {
      setBasket();
   }

   Basket::~Basket() {
      delete []m_fruits;
   }

   Basket::Basket(Fruit rightFruits[], int size, double totalPrice)  {
      if (rightFruits != nullptr && size != 0 && totalPrice != 0) {
         setBasket(size, totalPrice);   // checks the parameter
         m_fruits = new Fruit[size];    // allocates the memory
         for (int i = 0; i < size; i++) {
            m_fruits[i] = rightFruits[i];
         }
      } else setBasket();
   }

   Basket::Basket(Basket& rightBasket) {
      setBasket(rightBasket.m_totalFruits, rightBasket.m_totalPrice);
      *this = rightBasket;
   }

   Basket::operator bool()const {
      return m_totalFruits > 0;
   }

   Basket& Basket::operator=(const Basket& rightBasket) {
      if (m_fruits != nullptr) 
         delete []m_fruits;
      setBasket(rightBasket.m_totalFruits, rightBasket.m_totalPrice);
      m_fruits = new Fruit[m_totalFruits];    // memeory allocation
      for (int i = 0; i < m_totalFruits; i++) {
         m_fruits[i] = rightBasket.m_fruits[i];    // copying the fruites from the passed class
      }
      
      return *this;
   }

   void Basket::setPrice(double price) {
      m_totalPrice = price;
   }

   Basket& Basket::operator+=(const Fruit& newFruit) {
      Fruit* temp = new Fruit[m_totalFruits + 1];    // new temp memory with +1 storage
      for (int i = 0; i < m_totalFruits; i++) {    // filling up the temp memory
         temp[i] = m_fruits[i];
      }
      temp[m_totalFruits] = newFruit;
      delete[] m_fruits;    // deleting old memory 

      m_totalFruits++;    
      m_fruits = new Fruit[m_totalFruits];    // allocating new memory 
      for (int i = 0; i < m_totalFruits; i++) {
         m_fruits[i] = temp[i];
      }
      delete[] temp;    // deleting the temp memory
      return *this;
   }

   std::ostream& operator<<(std::ostream& ostr, const Basket& rightBasket) {
      if (rightBasket.isBasketEmpty()) {
         ostr << "The basket is empty!" << endl;
      }
      else rightBasket.printBasket(ostr);
      return ostr;
   }


   //-----------------------------------------------------------------------


   void Basket::setBasket(int size, double totalPrice) {
      m_fruits = nullptr;
      m_totalFruits = size;
      m_totalPrice = totalPrice;
   }

   bool Basket::isBasketEmpty()const {
      return m_totalFruits == 0;
   }

   void Basket::printBasket(std::ostream& ostr) const {
      ostr << "Basket Content:" << endl;
      for (int i = 0; i < m_totalFruits; i++) {
         ostr.fill(' ');
         ostr.width(10);
         ostr.setf(ios::right);
         ostr << m_fruits[i].m_name;
         ostr.unsetf(ios::right);
         ostr.setf(ios::fixed);
         ostr.precision(2);
         ostr << ": " << m_fruits[i].m_qty << "kg" << endl;
         ostr.unsetf(ios::fixed);
      }
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << "Price: " << m_totalPrice << endl;
      ostr.unsetf(ios::fixed);
   }

}
