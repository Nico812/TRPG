#pragma once
#include "creature.hpp"

//to do: destructor

class PG : public MovInvCreature
{
public:
    PG(std::string name_);
    ~PG() = default;
    std::string get_name()const{return name;}
private:
    std::string name;
};
