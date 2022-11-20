#include "creature.hpp"

//to do: destructors

//creature:

Creature::Creature(coord& position_, unsigned int id_):id(id_)
{
    this->position = &position_;
    this->hp = 10;
    this->lv = 1;
    this->exp_max = 10;
    this->exp = 0;
}

//inventory creature:

InvCreature::InvCreature(coord& position_, unsigned int id_):Creature(position_, id_) {}

//moving inventory creature:

MovInvCreature::MovInvCreature(coord& position_, unsigned int id_):InvCreature(position_, id_)
{
    switch(id_)
    {
        case 1000:
            set_hp(10);
            set_lv(1);
            set_exp_max(10);
            set_exp(0);
    }
}

unsigned int Creature::damage()
{
    return 1;
}

void Creature::hit(Creature& c)
{
    c.set_hp(c.get_hp() - this->damage());
}

