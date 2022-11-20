#include "game.hpp"



int main(){

    Game* TRPG = new Game;

    while(TRPG->get_running()){

        TRPG->update();
        TRPG->handle_events();
        TRPG->render();
        
    }

    TRPG->~Game();

    return 0;
}

// int main(){


//     std::array<std::array<SDL_Rect, tiles>, tiles> rect_grid(rect_grid_init());

//     //draw loop
//     SDL_Event event;
//     bool running = true;

//     while(running){
//         clear_screen(main_renderer);

//         for (int i = 0; i < tiles; ++i){
//             for(int j = 0; j < tiles; ++j){
//                 SDL_RenderCopy(main_renderer, ciao, NULL, &rect_grid[i][j]);
//             }
//         }

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
//                         SDL_RenderDrawLine(main_renderer, 500, 400, 300, 240);
//                         SDL_RenderDrawLine(main_renderer, 500, 0, 340, 240);
//                         SDL_RenderDrawLine(main_renderer, 340, 0, 320, 200);
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
//     shutdown(main_window, main_renderer);
//     SDL_Quit();
//     return EXIT_SUCCESS;
// }
