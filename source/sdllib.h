//
// Created by gnations on 8/2/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <switch.h>
#include <string>
#include "LTImer.h"
#ifndef HOMEBREW_SDLLIB_H
#define HOMEBREW_SDLLIB_H

struct Color{
	int r;
	int g;
	int b;
	int a;
};
//graphics routines
void draw_filled_rectangle(SDL_Renderer *renderer, int xpos, int ypos,int width, int height,Color color);
void draw_filled_circle(SDL_Renderer *renderer, int xpos, int ypos, int radius,Color c);
void draw_filled_rounded_rectangle(SDL_Renderer *renderer,int xpos,int ypos, int width, int height, int filletrad,Color c);
void draw_outline_rectangle(SDL_Renderer *renderer, int xpos, int ypos,int width, int height, Color color);
void draw_outline_circle(SDL_Renderer *renderer, int xpos, int ypos, int radius,Color c);
void draw_outline_rounded_rectangle(SDL_Renderer *renderer,int xpos,int ypos, int width, int height, int filletrad,Color c);

//joycon routines
int buttonNameToNumber(char* name);
bool isButtonPressed(HidControllerID joyconnum, int button);
#endif //HOMEBREW_SDLLIB_H
