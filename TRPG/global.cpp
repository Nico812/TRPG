#include "global.hpp"

int window_height;
int window_width;
int tile_width;
int tile_height;
int border_ovest;
int border_north;

int ask_window_mode()
{
    int window_mode;
    std::cout << "Please set the window mode," << std::endl <<
    "1: HD, 2: Resizable, 3: Fullscreen" << std::endl;
    std::cin>> window_mode;
    return window_mode;
}

void initialize_window_param(char p_)
{
    switch (p_)
    {
    case 'h':
        window_width = 2560/2;
        window_height = 1600/2;
        tile_width = 40;
        tile_height = tile_width;
        border_ovest = (window_width*2 - tiles*tile_width)/2;
        border_north = (window_height*2 - tiles*tile_height)/2;
        break;
    case 'r':
        window_width = 2560/2;
        window_height = 1600/2;
        tile_width = 40/2;
        tile_height = tile_width;
        border_ovest = (window_width - tiles*tile_width)/2;
        border_north = (window_height - tiles*tile_height)/2;
        break;
    case 'f':
        window_width = 2560;
        window_height = 1600;
        tile_width = 40;
        tile_height = tile_width;
        border_ovest = (window_width - tiles*tile_width)/2;
        border_north = (window_height - tiles*tile_height)/2;
        break;
    default:
        window_width = 2560/2;
        window_height = 1600/2;
        tile_width = 40/2;
        tile_height = tile_width;
        border_ovest = (window_width - tiles*tile_width)/2;
        border_north = (window_height - tiles*tile_height)/2;
        break;
    }
}

std::array<std::array<coord, tiles>, tiles> positions;

void initialize_positions()
{

    for(unsigned int i = 0; i < tiles; ++i)
    {
        for(unsigned int j = 0; j < tiles; ++j)
        {
            positions[i][j].x = i;
            positions[i][j].y = j;
        }
    }
}


IdPack main_id_pack;

void init_idpack(IdPack& main_id_pack_)
{
    main_id_pack_.tiles_bound[0] = 1;
    main_id_pack_.tiles_bound[1] = 3;
    main_id_pack_.creatures_bound[0] = 1000;
    main_id_pack_.creatures_bound[1] = 1000;
    //qui vanno i nomi degli oggetti:
    main_id_pack_.id_pack.insert({0, "PG"});
    main_id_pack_.id_pack.insert({1, "rock"});
    main_id_pack_.id_pack.insert({2, "grass"});
    main_id_pack_.id_pack.insert({3, "gro"});
    main_id_pack_.id_pack.insert({4, "4"});
    main_id_pack_.id_pack.insert({5, "5"});
    main_id_pack_.id_pack.insert({6, "6"});
    main_id_pack_.id_pack.insert({7, "7"});
    main_id_pack_.id_pack.insert({8, "8"});
    main_id_pack_.id_pack.insert({9, "9"});
    main_id_pack_.id_pack.insert({10, "10"});
    
    //creatures;
    main_id_pack_.id_pack.insert({1000, "[infernal] Gesus"});
}
