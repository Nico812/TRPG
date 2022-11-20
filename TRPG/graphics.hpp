#pragma once
#include "global.hpp"

class Rect_Grid
{
public:
    Rect_Grid();
    ~Rect_Grid();
    SDL_Rect& get_rect(unsigned int x, unsigned int y){return *rects[x][y];}
private:
    std::array<std::array<SDL_Rect*, tiles>, tiles> rects;
};

namespace colors
{
    const SDL_Color black = {0, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color gray1 = {32, 32, 32, SDL_ALPHA_OPAQUE};
    const SDL_Color gray2 = {64, 64, 64, SDL_ALPHA_OPAQUE};
    const SDL_Color white = {255, 255, 255, SDL_ALPHA_OPAQUE};
    const SDL_Color red = {255, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color red1 = {102, 0, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color green = {0, 255, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color blue = {0, 0, 255, SDL_ALPHA_OPAQUE};
    const SDL_Color green1 = {120, 102, 51, SDL_ALPHA_OPAQUE};
    const SDL_Color green2 = {51, 102, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color brown1 = {102, 51, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color yellow1 = {102, 102, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color yellow2 = {204, 204, 0, SDL_ALPHA_OPAQUE};
    const SDL_Color violet2 = {76, 0, 153, SDL_ALPHA_OPAQUE};
    const SDL_Color violet3 = {127, 0, 255, SDL_ALPHA_OPAQUE};
}


bool init(SDL_Window*& main_window, SDL_Renderer*& main_renderer);
void clear_screen(SDL_Renderer* renderer);
void shutdown(SDL_Window* main_window, SDL_Renderer* main_renderer);

std::vector<std::string> load_fonts_files();
std::vector<TTF_Font*> loadfonts(int ptsize);
SDL_Texture* render_text(const std::string& text, TTF_Font* font, SDL_Color color, int fontsize, SDL_Renderer* renderer);

//main example: 
//int main(){
//     SDL_Rect message_rect;
//     message_rect.x = 0;
//     message_rect.y = 0;
//     message_rect.w = 100;
//     message_rect.h = 100;


    

//     if(init() == false){shutdown();};
//     TTF_Font* schwabacher = loadfont("/Users/nico/Desktop/TRPG/fonts/shwabacher.ttf", 11);

//     //draw loop
//     SDL_Event event;
//     bool running = true;

//     while(running){
//         clear_screen(main_renderer);
//         SDL_Texture* ciao = render_text("ciao", schwabacher, colors::white, 2000, main_renderer);
//         SDL_RenderCopy(main_renderer, ciao, NULL, &message_rect);

//         //check and processes I/O events
//         if(SDL_PollEvent(&event)){
//             switch(event.type){

//                 case SDL_KEYDOWN: {

//                     running = (event.key.keysym.scancode != SDL_SCANCODE_ESCAPE);

//                     if(event.key.keysym.scancode == SDL_SCANCODE_1){
//                         SDL_SetRenderDrawColor(main_renderer, colors::red.r, colors::red.g, colors::red.b, colors::red.a);
//                         SDL_RenderDrawLine(main_renderer, 0, 0, 300, 240);
//                         SDL_RenderDrawLine(main_renderer, 0, 0, 340, 240);
//                         SDL_RenderDrawLine(main_renderer, 340, 240, 320, 200);
//                     };

//                     break;
//                 }
//                 case SDL_QUIT:{
//                     running = false;
//                     break;
//                 }
//                 default:
//                 break;
//             }
//         }

//         SDL_RenderPresent(main_renderer);
//     }
//     TTF_Quit();
//     shutdown();
//     SDL_Quit();
//     return EXIT_SUCCESS;
// }
