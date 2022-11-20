#pragma once
#include "object.hpp"

class Inventory
{
public:
    Inventory();
    Inventory(std::vector<Item> items_);
    ~Inventory() = default;

    Item get_item(unsigned int& i);
    void replace_item(unsigned int& i, Item item_);
    void trash(unsigned int& i);

private:
    std::vector<Item> items;
};
