#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <vector>
#include "item.h"
#include "item_shelf.h"

class Inventory {
    private:
        std::vector<ItemShelf*> m_item_shelves;;
    public:
        Inventory(int shelf_count);
        void addItem(Item* item, int shelf_code);
        void dispenseItem(int shelf_code);
        double getItemPrice(int shelf_code);
};

#endif