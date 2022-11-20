#pragma once
#include "inventory.hpp"

class Creature
{
public:
    Creature(coord& position_, unsigned int id_);
    ~Creature() = default;
    
    unsigned int damage();
    void hit(Creature& c);
    void earn_exp(); // implementa
    void drop(); //implementa

    void set_id(unsigned int id_){id = id_;}
    void set_pos(coord& coord_){position = &coord_;}
    void set_lv(unsigned int lv_){lv = lv_;}
    void set_hp(unsigned int hp_){hp = hp_;}
    void set_exp_max(unsigned int exp_max_){exp_max = exp_max_;}
    void set_exp(unsigned int exp_){exp = exp_;}
    void set_drops(std::vector<Item> drops_){drops = drops_;}

    unsigned int& get_id(){return id;}
    coord& get_pos(){return *position;}
    unsigned int& get_lv(){return lv;}
    unsigned int& get_hp(){return hp;}
    unsigned int& get_exp_max(){return exp_max;}
    unsigned int& get_exp(){return exp;}
    std::vector<Item> get_drops(){return drops;}
    virtual unsigned short get_range(){return 1;}

private:
    unsigned int id;
    coord* position;
    unsigned int lv;
    unsigned int hp;
    unsigned int exp_max;
    unsigned int exp;

    std::vector<Item> drops;

    //type of status?
    //Status status;
};

class InvCreature : public Creature
{
public:
    InvCreature(coord& position_, unsigned int id_);
private:
    Inventory inv;
};

class MovInvCreature : public InvCreature
{
    //id: [1000; 2000[
public:
    MovInvCreature(coord& position_, unsigned int id_);
};
