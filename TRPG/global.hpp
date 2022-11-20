#pragma once
#include<SDL2/SDL.h>
#include"SDL_ttf.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <array>
#include <map>
#include <vector>
#include <cmath>


//window mode:
int ask_window_mode();

//window parameters:
void initialize_window_param(char p_);
const int tiles = 31;
extern int window_height;
extern int window_width;
extern int tile_width;
extern int tile_height;

extern int border_ovest;
extern int border_north;

//coordinates and positions:
struct coord{
    unsigned int x;
    unsigned int y;
};

extern std::array<std::array<coord, tiles>, tiles> positions;
void initialize_positions();

struct IdPack
{
    std::map<unsigned int, std::string> id_pack;
    std::array<unsigned int, 2> tiles_bound;
    std::array<unsigned int, 2> creatures_bound;
};

void init_idpack(IdPack& id_pack_);

extern IdPack main_id_pack;

