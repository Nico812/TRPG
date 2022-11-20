#include "graphics.hpp"
#pragma once

class Object
{
public:
    Object(coord& pos, unsigned int& id_);
    ~Object() = default;

    void set_position(coord& new_position);
    void move_position(unsigned int dir);
    unsigned int& get_id();
    //set id serve veramente??
    void set_id(unsigned int& id_);
    coord get_position();    
private:
    coord* position;
    unsigned int id;
};

class Item : public Object
{
public:
    Item(coord& pos, unsigned int& id_);
    ~Item() = default;
};

