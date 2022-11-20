#include "texture_pack.hpp"

TexturePack main_texture_pack;

void init_texture_pack(TexturePack& x, SDL_Renderer* r, std::vector<TTF_Font*>& f)
{
    unsigned int fs = 1;
    
    x.sprites.insert({0, render_text("O", f[0], colors::white, fs, r)});
    x.sprites.insert({1, render_text("o", f[2], colors::green1, fs, r)});
    x.sprites.insert({2, render_text(".", f[2], colors::gray2, fs, r)});
    x.sprites.insert({3, render_text("-", f[2], colors::green2, fs, r)});
    x.sprites.insert({4, render_text("e", f[1], colors::brown1, fs, r)});
    x.sprites.insert({5, render_text("f", f[1], colors::yellow1, fs, r)});
    x.sprites.insert({6, render_text("g", f[1], colors::gray2, fs, r)});
    x.sprites.insert({7, render_text("h", f[1], colors::green2, fs, r)});
    x.sprites.insert({8, render_text("i", f[1], colors::yellow2, fs, r)});
    x.sprites.insert({9, render_text("l", f[1], colors::violet3, fs, r)});
    x.sprites.insert({10, render_text("m", f[1], colors::violet2, fs, r)});
    x.sprites.insert({1000, render_text("k", f[0], colors::violet2, fs, r)});
    
    for(unsigned int i (0); i < main_id_pack.id_pack.size(); ++i)
    {
        x.names.insert({i, render_text(main_id_pack.id_pack[i], f[2], colors::white, fs, r)});
    }
}
