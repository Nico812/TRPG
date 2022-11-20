#include "game.hpp"

Game::Game()
{
    running = true;
    pg = new PG(ask_name());
    
    if(init(main_window, main_renderer) == false){shutdown(main_window, main_renderer); running = false;};

    main_fonts = loadfonts(100);
    initialize_positions();

    init_idpack(main_id_pack);
    init_texture_pack(main_texture_pack, main_renderer, main_fonts);
    init_UiRects(main_ui_rects);
    events = new SDL_Event;

    map = new Map;
}

Game::~Game()
{
    map->~Map();
    map = nullptr;

    TTF_Quit();
    shutdown(main_window, main_renderer);
    SDL_Quit();
}

Creature Game::spawn_creature(coord& pos_)
{
    return Creature(pos_, rand()%(main_id_pack.creatures_bound[1] - main_id_pack.creatures_bound[0] + 1) + main_id_pack.creatures_bound[0]);
}

void Game::update()
{
    clear_screen(main_renderer);
}

void Game::handle_events()
{
    if(SDL_PollEvent(events)){
        switch(events->type){

            case SDL_KEYDOWN:
            {
                manage_key_press();
                break;
            }
            case SDL_QUIT:
            {
                running = false;
                break;
            }
            default: break;
        }
    }
}

void Game::manage_key_press()
{
    switch(events->key.keysym.scancode)
    {
        case SDL_SCANCODE_ESCAPE:{running = false;}
        break;
        case SDL_SCANCODE_UP:{pg_move(1);}
        break;
        case SDL_SCANCODE_DOWN:{pg_move(2);}
        break;
        case SDL_SCANCODE_LEFT:{pg_move(3);}
        break;
        case SDL_SCANCODE_RIGHT:{pg_move(4);}
        break;
        case SDL_SCANCODE_W:
        {
            hit_dir(*pg, 1, pg->get_range());
            erase_deads();
        }
        break;
        case SDL_SCANCODE_S:{hit_dir(*pg, 2, pg->get_range());}
        break;
        case SDL_SCANCODE_A:{hit_dir(*pg, 3, pg->get_range());}
        break;
        case SDL_SCANCODE_D:{hit_dir(*pg, 4, pg->get_range());}
        break;
        default: break;
    }
}

void Game::render()
{
    render_map();
    render_pg();
    render_creatures();
    render_creatures_info();
    render_PG_info();
    
    SDL_RenderPresent(main_renderer);
}

void Game::render_map()
{
    for (int i = 0; i < tiles; ++i)
    {
        for(int j = 0; j < tiles; ++j)
        {
            SDL_RenderCopy(main_renderer, main_texture_pack.sprites[map->tile_grid[i][j]->get_id()], NULL, &map->rect_grid.get_rect(i,j));
        }
    }
}

void Game::render_pg()
{
    SDL_RenderCopy(main_renderer, main_texture_pack.sprites[pg->get_id()], NULL, &map->rect_grid.get_rect(tiles/2, tiles/2));
}

void Game::render_creatures()
{
    for(unsigned i(0); i < creatures.size(); ++i)
    {
        SDL_RenderCopy(main_renderer, main_texture_pack.sprites[creatures[i]->get_id()], NULL, &map->rect_grid.get_rect(creatures[i]->get_pos().x, creatures[i]->get_pos().y));
    }
}

void Game::render_creatures_info()
{
    for(unsigned i(0); i < creatures.size(); ++i)
    {
        
        SDL_RenderCopy(main_renderer, main_texture_pack.names[creatures[i]->get_id()], NULL, main_ui_rects.c_name_rects[i]);
        
        SDL_RenderCopy(main_renderer, render_text(std::to_string(creatures[i]->get_hp()), main_fonts[2], colors::white, 1, main_renderer), NULL, main_ui_rects.c_health_rects[i]);
    }
}

void Game::render_PG_info()
{
    SDL_RenderCopy(main_renderer, render_text(std::to_string(pg->get_hp()), main_fonts[2], colors::white, 1, main_renderer), NULL, main_ui_rects.PG_health_rect);
    
    SDL_RenderCopy(main_renderer, render_text(pg->get_name(), main_fonts[2], colors::white, 1, main_renderer), NULL, main_ui_rects.PG_name_rect);
}

//altro:

std::string Game::ask_name()
{
    std::string n;
    std::cout << "Hello stupid traveler... what is your stupid name?" << std::endl;
    std::cin >> n;
    return n;
}

//debug:

void Game::position_debug()
{
    for(unsigned int j=0; j < map->tile_grid.size(); ++j)
    {
        for(unsigned int i=0; i < map->tile_grid.size(); ++i)
        {
            std::cout << "(" << map->tile_grid[i][j]->get_position().x << ", " << map->tile_grid[i][j]->get_position().y << ")  ";
        }
        std::cout << std::endl;
    }
}

void Game::pg_move(unsigned int dir)
{
    if(map->pg_check_obst(dir)){return;};
    map->tiles_move(dir);
    trasl_creatures(dir);
    
    movement_spawn_creature(dir);
}

void Game::trasl_creatures(unsigned int dir)
{
    if(creatures.size() == 0){return;}
    switch (dir)
    {
        case 1:
            for(auto i = creatures.begin(); i != creatures.end(); ++i)
            {
                while((*i)->get_pos().y == tiles - 1)
                {
                    delete *i;
                    i = creatures.erase(i);
                    //not sure:
                    if((creatures.size() == 0)or(i == creatures.end())){return;}
                }
                (*i)->set_pos(positions[(*i)->get_pos().x][(*i)->get_pos().y + 1]);
            }
            break;
            
        case 2:
            for(auto i = creatures.begin(); i != creatures.end(); ++i)
            {
                while((*i)->get_pos().y == 0)
                {
                    delete *i;
                    i = creatures.erase(i);
                    if((creatures.size() == 0)or(i == creatures.end())){return;}
                }
                (*i)->set_pos(positions[(*i)->get_pos().x][(*i)->get_pos().y - 1]);
            }
            break;
            
        case 3:
            for(auto i = creatures.begin(); i != creatures.end(); ++i)
            {
                while((*i)->get_pos().x == tiles - 1)
                {
                    delete *i;
                    i = creatures.erase(i);
                    if((creatures.size() == 0)or(i == creatures.end())){return;}
                }
                (*i)->set_pos(positions[(*i)->get_pos().x + 1][(*i)->get_pos().y]);
            }
            break;
            
        case 4:
            for(auto i = creatures.begin(); i != creatures.end(); ++i)
            {
                while((*i)->get_pos().x == 0)
                {
                    delete *i;
                    i = creatures.erase(i);
                    if((creatures.size() == 0)or(i == creatures.end())){return;}
                }
                (*i)->set_pos(positions[(*i)->get_pos().x - 1][(*i)->get_pos().y]);
            }
            break;
            
        default:
            break;
    }
}

void Game::movement_spawn_creature(unsigned int dir)
{
    if(rand()%20 == 0)
    {
        switch (dir)
        {
            case 1:
            {
                unsigned int r = rand()%tiles;
                if(!(map->check_obst(positions[r][0])))
                {
                    creatures.push_back(new Creature(spawn_creature(positions[r][0])));
                }
                break;
            }
            case 2:
            {
                break;
            }
                
            default:
            {
                break;
            }
        }
    }
}

Creature& Game::get_creature(coord& pos_)
{
    for(unsigned short i(0); i < creatures.size(); ++i )
    {
        if((creatures[i]->get_pos().x == pos_.x)and(creatures[i]->get_pos().y == pos_.y))
        {
            return *creatures[i];
        }
    }
    std::cout << "strangely i`m trying to hit myself ... [am i on salvia?] [get_creature()]" << std::endl;
    return *pg;
}

bool Game::search_creature(coord& pos_)
{
    for(unsigned short i(0); i < creatures.size(); ++i )
    {
        if((creatures[i]->get_pos().x == pos_.x)and(creatures[i]->get_pos().y == pos_.y))
        {
            return true;
        }
    }
    return false;
}

void Game::hit_dir(Creature& c, unsigned int dir, unsigned int range)
{
    switch(dir)
    {
        case 1:
        {
            for(unsigned short i(1); i <= range; ++i)
            {
                if(search_creature(positions[c.get_pos().x][c.get_pos().y - i]))
                {
                    c.hit(get_creature(positions[c.get_pos().x][c.get_pos().y - i]));
                }
            }
            break;
        }
            
        default:
        {
            break;
        }
    }
}

void Game::erase_deads()
{
    for (auto i = creatures.begin(); i != creatures.end(); ++i)
    {
        while((*i)->get_hp() <= 0)
        {
            delete *i;
            i = creatures.erase(i);
            if((creatures.size() == 0)or(i == creatures.end())){return;}
        }
    }
}
