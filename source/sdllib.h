//
// Created by gnations on 8/2/2019.
//

#include "masterinc.h"
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include <vector>
#include <errno.h>
#ifndef HOMEBREW_SDLLIB_H
#define HOMEBREW_SDLLIB_H


//graphics routines
void set_sdl_renderer(SDL_Renderer *render);
void draw_filled_rectangle(SDL_Renderer *renderer, int xpos, int ypos,int width, int height,Color color);
void draw_filled_circle(SDL_Renderer *renderer, int xpos, int ypos, int radius,Color c);
void draw_filled_rounded_rectangle(SDL_Renderer *renderer,int xpos,int ypos, int width, int height, int filletrad,Color c);
void draw_outline_rectangle(SDL_Renderer *renderer, int xpos, int ypos,int width, int height, Color color);
void draw_outline_circle(SDL_Renderer *renderer, int xpos, int ypos, int radius,Color c);
void draw_outline_rounded_rectangle(SDL_Renderer *renderer,int xpos,int ypos, int width, int height, int filletrad,Color c);
void pushToRenderList(const char* torender);
void processRenderQueue();
void renderSDLObject(const char* render_object );
//joycon routines
int buttonNameToNumber(std::string name);
bool isButtonPressed(HidControllerID joyconnum, int button);
#endif //HOMEBREW_SDLLIB_H
