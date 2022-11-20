#pragma once
#include "tiles.hpp"

class Map
{
    public:
    Map();
    ~Map() = default;
    
    bool pg_check_obst(unsigned int dir);
    bool check_obst(coord& coord_);
    //non funziona:
    //void clear_tile(unsigned int x, unsigned int y, SDL_Renderer* renderer);
    void tiles_move(const int& direction);
    //spawn:
    Tile spawn_tile_side(coord& coord_, char side);
    Tile spawn_tile_spread_side(coord& coord_, char side_);
    Tile spawn_tile_new(coord& coord_);

    void tiles_move_down();
    void tiles_move_up();
    void tiles_move_right();
    void tiles_move_left();

    Rect_Grid rect_grid;
    std::array<std::array<Tile*, tiles>, tiles> tile_grid;

    private:
};
