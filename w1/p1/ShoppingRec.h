#ifndef _SDDS_SHOPPINGREC_H_
#define _SDDS_SHOPPINGREC_H_

namespace sdds
{
    const int MAX_TITLE_LENGTH = 50;

    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif 