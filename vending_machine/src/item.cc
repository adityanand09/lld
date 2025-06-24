#include "item.h"

Item::Item(ItemType item_type, double price) : m_item_type(item_type), m_price(price) {}

double Item::getPrice() {
    return m_price;
}

ItemType Item::getItemType() {
    return m_item_type;
}