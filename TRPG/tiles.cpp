#include "tiles.hpp"


Tile::Tile(coord& pos, unsigned int id_):Object(pos,id_)
{

    switch(id_)
    {
        //rock:
        case 1:
        spread = 2;
        obst = true;
        break;

        case 2:
        spread = 5;
        obst = false;
        break;

        case 3:
        spread = 5;
        obst = false;
        break;
        
        default:
        spread = 1;
        obst = false;
    }

}
