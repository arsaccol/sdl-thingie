#pragma once

#include <SDL2/SDL.h>
#include <cmath>

#include "IApplication.h"



class Graphics {
public: 

    Graphics(SDL_Window* window, IApplication& app)
        : window{window}
        , app{app}
    {

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer == nullptr) {
            SDL_Log("Couldn't start renderer");

            app.doQuit();
        }



        renderSurface = SDL_CreateRGBSurface(0, renderWidth, renderHeight, 32, 0, 0, 0, 0);
    }
    ~Graphics() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(renderTexture);
        SDL_FreeSurface(renderSurface);
        renderSurface = nullptr;
    }

    void render() {
        SDL_LockSurface(renderSurface);

        Uint32* pixels = static_cast<Uint32*>(renderSurface->pixels);
        Uint32 redColor = SDL_MapRGB(renderSurface->format, 255, 0, 0);

        int pixelCount = renderWidth * renderHeight;

        for(int i = 0; i < pixelCount; ++i) {
            pixels[i] = redColor;
        }

        SDL_UnlockSurface(renderSurface);

        renderTexture = SDL_CreateTextureFromSurface(renderer, renderSurface);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, renderTexture, nullptr, nullptr);
        SDL_RenderPresent(renderer);


    }

    SDL_Surface* getSurface() {
        return renderSurface;
    }


    void clear() {
    }

private:
    IApplication& app;
    SDL_Surface* renderSurface{nullptr};
    SDL_Renderer* renderer{nullptr};
    SDL_Window* window{nullptr};
    SDL_Texture* renderTexture{nullptr};
    int renderWidth{640};
    int renderHeight{480};
};
