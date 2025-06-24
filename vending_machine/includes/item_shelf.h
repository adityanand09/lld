#ifndef __ITEM_SHELF_H__
#define __ITEM_SHELF_H__

#include <unordered_map>
#include <vector>
#include "item.h"

class ItemShelf {
    private:
        Item* m_item;
        int m_count;
        int m_shelf_code;
    public:
        ItemShelf(int shelf_code);
        void addItem(Item* item);
        void dispenseItem(int shelf_code);
        int getShelfCode();
        double getItemPrice();

};

#endif