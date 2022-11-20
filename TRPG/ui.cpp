#include "ui.hpp"

UiRects main_ui_rects;

void init_UiRects(UiRects& in)
{
    in.PG_name_rect = new SDL_Rect;
    in.PG_name_rect->x = tile_width;
    in.PG_name_rect->y = border_north;
    in.PG_name_rect->w = border_ovest - 2*tile_width;
    in.PG_name_rect->h = tile_height;

    in.PG_health_rect = new SDL_Rect;
    in.PG_health_rect->x = tile_width;
    in.PG_health_rect->y = border_north + 2*tile_height;
    //in.PG_health_rect->w = border_ovest - 2*tile_width;
    in.PG_health_rect->w = 2*tile_width;
    in.PG_health_rect->h = tile_height;
    
    for(unsigned int i(0); i < in.c_name_rects.size(); ++i)
    {
        in.c_name_rects[i] = new SDL_Rect;
        in.c_name_rects[i]->x = border_ovest + tiles*tile_width + tile_width;
        in.c_name_rects[i]->y = border_north + 4*i*tile_height;
        in.c_name_rects[i]->w = border_ovest - 2*tile_width;
        in.c_name_rects[i]->h = tile_height;
    }
    
    for(unsigned int i(0); i < in.c_health_rects.size(); ++i)
    {
        in.c_health_rects[i] = new SDL_Rect;
        in.c_health_rects[i]->x = border_ovest + tiles*tile_width + tile_width;
        in.c_health_rects[i]->y = border_north + 2*tile_height + 4*i*tile_height;
        //in.c_health_rects[i]->w = border_ovest - 2*tile_width;
        in.c_health_rects[i]->w = 2*tile_width;
        in.c_health_rects[i]->h = tile_height;
    }
}
