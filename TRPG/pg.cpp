#include "pg.hpp"

PG::PG(std::string name_):MovInvCreature(positions[tiles/2][tiles/2], 0)
{
    name = name_;
    
    set_id(0);
    set_lv(1);
    set_hp(1);
    set_exp_max(10);
    set_exp(0);
    //set_drops()?

    //inventory?
}
