#include "inventory.h"

Inventory::Inventory(int shelf_count) : m_item_shelves(shelf_count) {
    int start_code = 101;
    for (int i=0; i<shelf_count; i++) {
        m_item_shelves[i] = new ItemShelf(start_code);
        start_code++;
    }
}

void Inventory::addItem(Item* item, int shelf_code) {
    for (ItemShelf* item_shelf : m_item_shelves) {
        if (item_shelf->getShelfCode() == shelf_code) {
            item_shelf->addItem(item);
        }
    }
}

void Inventory::dispenseItem(int shelf_code) {
    for (ItemShelf* item_shelf : m_item_shelves) {
        if (item_shelf->getShelfCode() == shelf_code) {
            item_shelf->dispenseItem(shelf_code);
        }
    }
}

double Inventory::getItemPrice(int shelf_code) {
    for (ItemShelf* item_shelf : m_item_shelves) {
        if (item_shelf->getShelfCode() == shelf_code) {
            return item_shelf->getItemPrice();
        }
    }
    return 0;
}