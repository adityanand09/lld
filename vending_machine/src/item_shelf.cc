#include "item_shelf.h"
#include <iostream>

ItemShelf::ItemShelf(int shelf_code) : m_shelf_code(shelf_code), m_item(nullptr) {}

void ItemShelf::addItem(Item* item) {
    if (m_item == nullptr || m_count == 0) {
        m_item = item;
        m_count = 1;
    } else if (m_item->getItemType() == item->getItemType()) {
        m_count += 1;
    }
}

void ItemShelf::dispenseItem(int shelf_code) {
    if (m_count == 0) return;
    std::cout << "Item " << shelf_code << " dispensed" << std::endl;
    m_count -= 1;
}

int ItemShelf::getShelfCode() {
    return m_shelf_code;
}

double ItemShelf::getItemPrice() {
    return m_item->getPrice();
}