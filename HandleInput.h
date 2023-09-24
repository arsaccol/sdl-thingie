#pragma once

#include <SDL2/SDL.h>
#include "IApplication.h"


class InputHandler {
public:
    InputHandler(SDL_Window* window, IApplication& app) 
        : window{window}
        , app{app}
        
    {
    }

    void handleInput() {
        SDL_Event e;


        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                app.doQuit();

            }
        }
    }




private:
    double mouse_x;
    double mouse_y;
    SDL_Window* window;
    IApplication& app;

};
