#ifndef _SDDS_SHOPPINGLIST_H_
#define _SDDS_SHOPPINGLIST_H_

namespace sdds
{

    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
}

#endif 