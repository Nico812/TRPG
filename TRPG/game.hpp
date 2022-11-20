#pragma once
#include "texture_pack.hpp"
#include "map.hpp"
#include "pg.hpp"
#include "ui.hpp"

class Game
{
public:
    Game();
    ~Game();

    std::string ask_name();
    void update();
    void handle_events();
    
    //creatures:
    void trasl_creatures(unsigned int dir);
    Creature spawn_creature(coord& pos_);
    void movement_spawn_creature(unsigned int dir);//spawn at sides.
    bool search_creature(coord& pos_);//true if theres a creature.
    Creature& get_creature(coord& pos_);
    void hit_dir(Creature& c, unsigned int dir, unsigned int range);
    void erase_deads();
    
    //render (PG name rendered in Game()):
    void render();
    void render_map();
    void render_pg();
    void render_creatures();
    void render_creatures_info();
    void render_PG_info();
    
    
    //movement:
    void pg_move(unsigned int dir);

//others:
    void load_texture_pack();

//get methods:
    const bool& get_running(){return this->running;}
//key binding.
    void manage_key_press();
//debug:
    void position_debug();

private:
    bool running;

    Map* map;
    PG* pg;
    std::vector<Creature*> creatures;
    
    SDL_Window* main_window;
    SDL_Renderer* main_renderer;
    SDL_Event* events;
//packs:
    TexturePack* texture_pack;
//
    std::vector<TTF_Font*> main_fonts;
};
