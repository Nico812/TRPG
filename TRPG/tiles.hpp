#pragma once
#include "object.hpp"

class Tile : public Object
{
public:
    Tile(coord& pos, unsigned int id_);
    virtual ~Tile() = default;
    unsigned int& get_spread(){return spread;}
    bool get_obst(){return obst;}
private:
    unsigned int spread;
    bool obst;
};
