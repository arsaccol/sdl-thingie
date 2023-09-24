#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "IApplication.h"
#include "Graphics.h"
#include "HandleInput.h"
#include "World.h"


class App : public IApplication {
    public:
        App() {
            inputHandler = std::make_unique<InputHandler>(window, *this);
        }

        bool init() {
            if(SDL_Init(SDL_INIT_VIDEO) < 0) {
                printf("%s\n", SDL_GetError());
                return false;
            }
            window = SDL_CreateWindow(windowTitle.c_str(), 
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                    SCREEN_WIDTH, SCREEN_HEIGHT, 
                    SDL_WINDOW_SHOWN
            );

            if(window == nullptr) {
                printf("%s\n", SDL_GetError());
                return false;
            }

            graphics = std::make_unique<Graphics>(window, *this);

            return true;
        }

        void loop() {
            while(!IApplication::shouldQuit()) {
                startTime = SDL_GetTicks();


                inputHandler->handleInput();

                graphics->render();

                endTime = SDL_GetTicks();
                frameTime = endTime - startTime;

                if(frameTime < targetFrameTime) {
                    SDL_Delay(targetFrameTime - frameTime);
                }





                
                Uint32 elapsedTime = SDL_GetTicks() - startTime;
                std::string newTitle = windowTitle + " " + std::to_string(elapsedTime) + " ms";
                SDL_SetWindowTitle(window, newTitle.c_str());


            }
        }

        void close() {

            SDL_DestroyWindow(window);
            window = nullptr;

            SDL_Quit();
        }



    private: 
        SDL_Window* window{nullptr};
        
        std::unique_ptr<InputHandler> inputHandler;
        std::unique_ptr<World> world;
        std::unique_ptr<Graphics> graphics;


        int SCREEN_WIDTH{640};
        int SCREEN_HEIGHT{480};

        Uint32 startTime{0};
        Uint32 endTime{0};

        Uint32 frameTime{0};
        Uint32 targetFrameTime{16};
        std::string windowTitle{"すごい楽しいゲーム"};

};
