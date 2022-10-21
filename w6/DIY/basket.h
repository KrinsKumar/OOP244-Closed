#ifndef _SDDS_BASKET_H_
#define _SDDS_BASKET_H_

namespace sdds {

    struct Fruit {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
        Fruit* m_fruits; // dynamically stores an array of fruit class
        int m_totalFruits  // total number of fruits
        int m_totalPrice  // total price of the basket
        public: 
            Basket();
            ~Basket();
            operator bool(const Basket$ paraBasket);
            Basket(Fruit rightFruits[], int totalPrice);
            Basket(Basket& rightBasket);
            Basket& operator=(const Basket& rightBasket);
            void setPrice(double price);
            Basket& operator+=(const Fruit& newFruit);
    }

    
}

#endif // _SDDS_BASKET_H_   