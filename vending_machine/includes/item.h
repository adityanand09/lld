#ifndef __ITEM_H__
#define __ITEM_H__

#include "item_type.h"

class Item {
    private:
        ItemType m_item_type;
        double m_price;
    public:
        Item(ItemType item_type, double price);
        double getPrice();
        ItemType getItemType();
};

#endif