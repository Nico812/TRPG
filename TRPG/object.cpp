#include "object.hpp"

//object:

Object::Object(coord& pos, unsigned int& id_)
{
    id = id_;
    position = &pos;
}


void Object::set_position(coord& new_position)
{
    position = &new_position;
}

void Object::move_position(unsigned int dir)
{
    //1:down, 2:up, 3:right, 4:left, ...
    switch(dir){
        case 1:
        position = &positions[position->x][position->y + 1];
        break;
        case 2:
        position = &positions[position->x][position->y - 1];
        break;
        case 3:
        position = &positions[position->x + 1][position->y];
        break;
        case 4:
        position = &positions[position->x - 1][position->y];
        break;
        default:
        std::cout << "direction inesistent [move_position()]" << std::endl;
    };
}

coord Object::get_position()
{
    return *position;
}

unsigned int& Object::get_id()
{
    return id;
}

void Object::set_id(unsigned int& id_)
{
    id = id_;
}

//item:
Item::Item(coord& pos, unsigned int& id_):Object(pos,id_)
{

}
