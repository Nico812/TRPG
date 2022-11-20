#include "graphics.hpp"

bool init(SDL_Window*& main_window, SDL_Renderer*& main_renderer)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    };

    if(TTF_Init() != 0)
    {
        std::cout << "TTF_Init failed with error: " << TTF_GetError() << std::endl;
        return EXIT_FAILURE;
    };

    switch(ask_window_mode())
    {
        case 1:
            initialize_window_param('h');
            main_window = SDL_CreateWindow("TRPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_ALLOW_HIGHDPI);
            break;
        case 2:
            initialize_window_param('r');
            main_window = SDL_CreateWindow("TRPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_RESIZABLE);
            break;
        case 3:
            initialize_window_param('f');
            main_window = SDL_CreateWindow("TRPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_FULLSCREEN);
            break;
        default:
            initialize_window_param('r');
            main_window = SDL_CreateWindow("TRPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_RESIZABLE);
            break;
    }

    if (main_window == nullptr){
        std::cout << "Unable to create the main window. Error: " << SDL_GetError() << std::endl;
        SDL_Quit(); //force shutdown
        return EXIT_FAILURE;
    }

    main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}

std::vector<std::string> load_fonts_files()
{
    std::vector<std::string> fonts_files;
    
    fonts_files.push_back("/Users/nico/Desktop/TRPG/fonts/invaders.from.space.ttf");
    fonts_files.push_back("/Users/nico/Desktop/TRPG/fonts/Mess-Light_web.ttf");
    fonts_files.push_back("/Users/nico/Desktop/TRPG/fonts/Libra-Normal.ttf");
    return fonts_files;
}

std::vector<TTF_Font*> loadfonts(int ptsize)
{
    std::vector<std::string> file_list;
    std::vector<TTF_Font*> font_list;
    
    file_list = load_fonts_files();
    
    for(unsigned int i = 0; i < file_list.size(); ++i)
    {
        font_list.push_back(TTF_OpenFont(file_list[i].c_str(), ptsize));
        if (font_list[i] == NULL)
        {
          std::cout <<"Unable to load font :" << TTF_GetError();
          // Handle the error here.
        }
    }
 return font_list;
}

void shutdown(SDL_Window* window, SDL_Renderer* renderer)
{
    if(window != nullptr){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    if(renderer != nullptr){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    SDL_Quit();
}

void clear_screen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, colors::black.r, colors::black.g, colors::black.b, colors::black.a);
    SDL_RenderClear(renderer);
}

SDL_Texture* render_text(const std::string& text, TTF_Font* font, SDL_Color color, int fontsize, SDL_Renderer* renderer)
{
	SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	//Clean up the surface and font
	SDL_FreeSurface(surf);
    surf = nullptr;
    //
	return texture;
}

Rect_Grid::Rect_Grid()
{
    for (int i = 0; i < tiles; ++i){
        for(int j = 0; j < tiles; ++j){
            rects[i][j] = new SDL_Rect;
            rects[i][j]->x = border_ovest + i*tile_width;
            rects[i][j]->y = border_north + j*tile_height;
            rects[i][j]->w = tile_width;
            rects[i][j]->h = tile_height;
        }
    }
}

Rect_Grid::~Rect_Grid()
{
     for (int i = 0; i < tiles; ++i){
        for(int j = 0; j < tiles; ++j){
            delete rects[i][j];
            rects[i][j] = nullptr;
        }
    }
}
