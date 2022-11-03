#ifndef _SDDS_BASKET_H_
#define _SDDS_BASKET_H_

namespace sdds {

    struct Fruit {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
        Fruit* m_fruits; // dynamically stores an array of fruit class
        int m_totalFruits;  // total number of fruits
        double m_totalPrice;  // total price of the basket
        public: 
            // DIY members
            Basket();
            ~Basket();
            Basket(Fruit rightFruits[], int size, double totalPrice);
            Basket(Basket& rightBasket);
            operator bool()const;
            Basket& operator=(const Basket& rightBasket);
            void setPrice(double price);
            Basket& operator+=(const Fruit& newFruit);

            // Custom members
            void setBasket(int size = 0, double totalPrice = 0);
            bool isBasketEmpty()const;
            void printBasket(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Basket& rightBasket);

    
}

#endif // _SDDS_BASKET_H_   