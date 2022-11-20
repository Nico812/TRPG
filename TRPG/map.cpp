#include "map.hpp"

Map::Map()
{
    //rect_grid initialization:
    //tile_grid initialization:
    for(unsigned int j = 0; j < tile_grid[0].size(); ++j)
    {
        for(unsigned int i = 0; i < tile_grid.size(); ++i)
        {
            tile_grid[i][j] = new Tile(positions[i][j], rand()%10 +1);
        }
    }
}

bool Map::pg_check_obst(unsigned int dir)
{
    //1: up, 2:down, 3:left, 4:right.
    switch(dir)
    {
        case 1:
            return tile_grid[tiles/2][tiles/2 - 1]->get_obst();
        case 2:
            return tile_grid[tiles/2][tiles/2 + 1]->get_obst();
        case 3:
            return tile_grid[tiles/2 - 1][tiles/2]->get_obst();
        case 4:
            return tile_grid[tiles/2 + 1][tiles/2]->get_obst();
        default:
            return true;
    }
}

//non funziona:
//void Map::clear_tile(unsigned int x, unsigned int y, SDL_Renderer* renderer)
//{
//    SDL_Surface* surf = SDL_CreateRGBSurface(0, tile_width, tile_height, 1, 0, 0, 0, 255);
//    SDL_FillRect(surf, &rect_grid.get_rect(x, y), SDL_MapRGB(surf->format, 255, 0, 0));
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
//    SDL_RenderCopy(renderer, texture, &rect_grid.get_rect(x, y), NULL);
//
//    SDL_DestroyTexture(texture);
//    SDL_FreeSurface(surf);
//}

void Map::tiles_move(const int& direction)
{
    //moves all the tiles in one direction
    //1:down, 2:up, 3:right, 4:left, ...
    switch(direction){
        case 1:
        tiles_move_down();
        break;
        case 2:
        tiles_move_up();
        break;
        case 3:
        tiles_move_right();
        break;
        case 4:
        tiles_move_left();
        break;

        default:
        std::cout << "direction inesistent [tiles_move()]" << std::endl;
    };
}

Tile Map::spawn_tile_side(coord& coord_, char side)
{
    if(rand() % 10 > 0)
    {
        return spawn_tile_spread_side(coord_, side);
    }
    else
    {
        return spawn_tile_new(coord_);
    }
}


Tile Map::spawn_tile_spread_side(coord& coord_, char side_)
{
    
    if(side_ == 'u')
    {
        //standard:
        if((coord_.x != 0)and(coord_.x != tiles - 1))
        {
            unsigned int r1 = tile_grid[coord_.x - 1][1]->get_spread();
            unsigned int r2 = r1 + tile_grid[coord_.x][1]->get_spread();
            unsigned int r3 = r2 + tile_grid[coord_.x +     1][1]->get_spread();
            unsigned int r = rand() % r3;
            if(r < r1)
            {
                return Tile(coord_, tile_grid[coord_.x - 1][1]->get_id());
            }
            else
            {
                if((r1 <= r)and(r < r2))
                {
                    return Tile(coord_, tile_grid[coord_.x][1]->get_id());
                }
                else
                {
                    return Tile(coord_, tile_grid[coord_.x +    1][1]->get_id());
                }
            }
    
        }
    
            //angoli:
        if(coord_.x == 0)
        {
            if(rand() % (tile_grid[0][1]->get_spread() +    tile_grid[1][1]->get_spread()) >=    tile_grid[0][1]->get_spread())
            {
                return Tile(coord_, tile_grid[1][1]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[0][1]->get_id());
            }
        }
    
        if(coord_.x == tiles - 1)
        {
            if(rand() % (tile_grid[tiles - 1][1]->get_spread() +    tile_grid[tiles - 2][1]->get_spread() + 1) >    tile_grid[tiles - 1][1]->get_spread())
            {
                return Tile(coord_, tile_grid[tiles - 2][1]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[tiles - 1][1]->get_id());
            }
        }
    }
    
    if(side_ == 'd')
    {
        //standard:
        if((coord_.x != 0)and(coord_.x != tiles - 1))
        {
            unsigned int r1 = tile_grid[coord_.x - 1][tiles - 2]->get_spread();
            unsigned int r2 = r1 + tile_grid[coord_.x][tiles - 2]->get_spread();
            unsigned int r3 = r2 + tile_grid[coord_.x + 1][tiles - 2]->get_spread();
            unsigned int r = rand() % r3;
            if(r < r1)
            {
                return Tile(coord_, tile_grid[coord_.x - 1][tiles - 2]->get_id());
            }
            else
            {
                if((r1 <= r)and(r < r2))
                {
                    return Tile(coord_, tile_grid[coord_.x][tiles - 2]->get_id());
                }
                else
                {
                    return Tile(coord_, tile_grid[coord_.x + 1][tiles - 2]->get_id());
                }
            }
    
        }
        //angoli:
        if(coord_.x == 0)
        {
            if(rand() % (tile_grid[0][tiles - 2]->get_spread() + tile_grid[1][tiles - 2]->get_spread()) >=        tile_grid[0][tiles - 2]->get_spread())
            {
                return Tile(coord_, tile_grid[1][tiles - 2]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[0][tiles - 2]->get_id());
            }
        }
    
        if(coord_.x == tiles - 1)
        {
            if(rand() % (tile_grid[tiles - 1][tiles - 2]->get_spread() + tile_grid[tiles - 2][tiles - 2]->get_spread()) >= tile_grid[tiles - 1][tiles - 2]->get_spread())
            {
                return Tile(coord_, tile_grid[tiles - 2][tiles - 2]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[tiles - 1][tiles - 2]->get_id());
            }
        }
    }
    
    if(side_ == 'l')
    {
        //standard:
        if((coord_.y != 0)and(coord_.y != tiles - 1))
        {
            unsigned int r1 = tile_grid[1][coord_.y - 1]->get_spread();
            unsigned int r2 = r1 + tile_grid[1][coord_.y]->get_spread();
            unsigned int r3 = r2 + tile_grid[1][coord_.y + 1]->get_spread();
            unsigned int r = rand() % r3;
            if(r < r1)
            {
                return Tile(coord_, tile_grid[1][coord_.y - 1]->get_id());
            }
            else
            {
                if((r1 <= r)and(r < r2))
                {
                    return Tile(coord_, tile_grid[1][coord_.y]->get_id());
                }
                else
                {
                    return Tile(coord_, tile_grid[1][coord_.y + 1]->get_id());
                }
            }
    
        }
        //angoli:
        if(coord_.y == 0)
        {
            if(rand() % (tile_grid[1][0]->get_spread() + tile_grid[1][1]->get_spread()) >= tile_grid[1][0]->get_spread())
            {
                return Tile(coord_, tile_grid[1][1]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[1][0]->get_id());
            }
        }
    
        if(coord_.y == tiles - 1)
        {
            if(rand() % (tile_grid[1][tiles - 1]->get_spread() + tile_grid[1][tiles - 2]->get_spread()) >= tile_grid[1][tiles - 1]->get_spread())
            {
                return Tile(coord_, tile_grid[1][tiles - 2]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[1][tiles - 1]->get_id());
            }
        }
    }
    
    if(side_ == 'r')
    {
        //standard:
        if((coord_.y != 0)and(coord_.y != tiles - 1))
        {
            unsigned int r1 = tile_grid[tiles - 2][coord_.y - 1]->get_spread();
            unsigned int r2 = r1 + tile_grid[tiles - 2][coord_.y]->get_spread();
            unsigned int r3 = r2 + tile_grid[tiles - 2][coord_.y + 1]->get_spread();
            unsigned int r = rand() % r3;
            if(r < r1)
            {
                return Tile(coord_, tile_grid[tiles - 2][coord_.y - 1]->get_id());
            }
            else
            {
                if((r1 <= r)and(r < r2))
                {
                    return Tile(coord_, tile_grid[tiles - 2][coord_.y]->get_id());
                }
                else
                {
                    return Tile(coord_, tile_grid[tiles - 2][coord_.y + 1]->get_id());
                }
            }
    
        }
        //angoli:
        if(coord_.y == 0)
        {
            if(rand() % (tile_grid[tiles - 2][0]->get_spread() + tile_grid[tiles - 2][1]->get_spread()) >= tile_grid[tiles - 2][0]->get_spread())
            {
                return Tile(coord_, tile_grid[tiles - 2][1]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[tiles - 2][0]->get_id());
            }
        }
    
        if(coord_.y == tiles - 1)
        {
            if(rand() % (tile_grid[tiles - 2][tiles - 1]->get_spread() + tile_grid[tiles - 2][tiles - 2]->get_spread()) >= tile_grid[tiles - 2][tiles - 1]->get_spread())
            {
                return Tile(coord_, tile_grid[tiles - 2][tiles - 2]->get_id());
            }
            else
            {
                return Tile(coord_, tile_grid[tiles - 2][tiles - 1]->get_id());
            }
        }
    }
    

    std::cout << "error in Map::spawn_tile_spread_side" << std::endl;
    return Tile(coord_, 0);

}

Tile Map::spawn_tile_new(coord& coord_)
{
    return Tile(coord_, rand()%(main_id_pack.tiles_bound[1] - main_id_pack.tiles_bound[0] + 1) + main_id_pack.tiles_bound[0]);
}

void Map::tiles_move_down()
{

    //last row:
    for(unsigned int t = 0; t < tile_grid.size(); ++t){
        //destroy:
        tile_grid[t][tile_grid.size() - 1]-> ~Tile();
        //take:
        tile_grid[t][tile_grid.size() - 1] = tile_grid[t][tile_grid.size() - 2];
        //update position:
        tile_grid[t][tile_grid.size() - 1]-> move_position(1);
    }

    for(unsigned long j = tile_grid[0].size() - 2; j > 0; --j){
        for(unsigned int i = 0; i < tile_grid.size(); ++i){
            tile_grid[i][j] = tile_grid[i][j-1];
            tile_grid[i][j]-> move_position(1);
        }
    }
    
    //first row:
    for(unsigned int l = 0; l < tile_grid.size(); ++l)
    {
        tile_grid[l][0] = new Tile(spawn_tile_side(positions[l][0], 'u'));
    }
}

void Map::tiles_move_up()
{
    //first row:
    for(unsigned int t = 0; t < tile_grid.size(); ++t){
        //destroy:
        tile_grid[t][0]-> ~Tile();
        //take:
        tile_grid[t][0] = tile_grid[t][1];
        //update position:
        tile_grid[t][0]-> move_position(2);
    }

    for(unsigned int j = 1; j < tile_grid[0].size() - 1; ++j){
        for(unsigned int i = 0; i < tile_grid.size(); ++i){
            tile_grid[i][j] = tile_grid[i][j+1];
            tile_grid[i][j]-> move_position(2);
        }
    }

    //last row:
    for(unsigned int l = 0; l < tile_grid.size(); ++l)
    {
        tile_grid[l][tile_grid.size()-1] = new Tile(spawn_tile_side(positions[l][tiles - 1], 'd'));
    }
}

void Map::tiles_move_right()
{
    //last column:
    for(unsigned int t = 0; t < tile_grid[0].size(); ++t){
        //destroy:
        tile_grid[tile_grid[0].size() - 1][t]-> ~Tile();
        //take:
        tile_grid[tile_grid[0].size() - 1][t] = tile_grid[tile_grid.size() - 2][t];
        //update position:
        tile_grid[tile_grid[0].size() - 1][t]-> move_position(3);
    }

    //why xcode makes me put "unsigned long" instead of "unsigned int" here, but not up five lines from here?
    for(unsigned long i = tile_grid.size() - 2; i > 0; --i){
        for(unsigned int j = 0; j < tile_grid[0].size(); ++j){
            tile_grid[i][j] = tile_grid[i-1][j];
            tile_grid[i][j]-> move_position(3);
        }
    }

    //first column:
    for(unsigned int l = 0; l < tile_grid[0].size(); ++l)
    {
        tile_grid[0][l] = new Tile(spawn_tile_side(positions[0][l], 'l'));
    }
}

void Map::tiles_move_left()
{
    //first column:
    for(unsigned int t = 0; t < tile_grid[0].size(); ++t){
        //destroy:
        tile_grid[0][t]-> ~Tile();
        //take:
        tile_grid[0][t] = tile_grid[1][t];
        //update position:
        tile_grid[0][t]-> move_position(4);
    }

    for(unsigned int i = 1; i < tile_grid.size() - 1; ++i){
        for(unsigned int j = 0; j < tile_grid[0].size(); ++j){
            tile_grid[i][j] = tile_grid[i+1][j];
            tile_grid[i][j]-> move_position(4);
        }
    }

    //last column:
    for(unsigned int l = 0; l < tile_grid[0].size(); ++l)
    {
        tile_grid[tile_grid[0].size()-1][l] = new Tile(spawn_tile_side(positions[tiles - 1][l], 'r'));
    }
}

bool Map::check_obst(coord& coord_)
{
    return(tile_grid[coord_.x][coord_.y]->get_obst());
}
