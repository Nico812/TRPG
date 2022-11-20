#pragma once
#include"graphics.hpp"

struct TexturePack
{
    std::map<unsigned int, SDL_Texture*> sprites;
    std::map<unsigned int, SDL_Texture*> names;
};

void init_texture_pack(TexturePack& x, SDL_Renderer* r, std::vector<TTF_Font*>& f);

extern TexturePack main_texture_pack;

void destroy_texture_pack(); // implementa
