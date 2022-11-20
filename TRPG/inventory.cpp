#include "inventory.hpp"

//costructors:
Inventory::Inventory(){}

Inventory::Inventory(std::vector<Item> items_)
{
    items = items_;
}

//methods:

Item Inventory::get_item(unsigned int& i)
{
    return items[i];
}

void Inventory::replace_item(unsigned int& i, Item item_)
{
    items[i] = item_;
}

void Inventory::trash(unsigned int& i)
{
    for(unsigned int j = i; j < items.size()-1; ++j)
    {
        items[i] = items[j + 1];
    }
    items.pop_back();
}