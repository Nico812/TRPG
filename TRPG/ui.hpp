#pragma once
#include "graphics.hpp"

struct UiRects
{
    SDL_Rect* PG_name_rect;
    SDL_Rect* PG_health_rect;
    std::array<SDL_Rect*, tiles*tiles> c_name_rects;
    std::array<SDL_Rect*, tiles*tiles> c_health_rects;
};

void init_UiRects(UiRects& in);

extern UiRects main_ui_rects;
