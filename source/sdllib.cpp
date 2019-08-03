//
// Created by gnations on 8/2/2019.
//

#include "sdllib.h"


void draw_filled_rectangle(SDL_Renderer *renderer, int xpos, int ypos,int width, int height, Color color) {
	SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
	SDL_Rect r = {xpos,ypos,width,height};
	SDL_RenderFillRect(renderer,&r);
}

void draw_filled_circle(SDL_Renderer *renderer, int xpos, int ypos, int radius,Color c) {
	filledCircleRGBA(renderer,xpos,ypos,radius,c.r,c.g,c.b,c.a);
}

void draw_filled_rounded_rectangle(SDL_Renderer *renderer,int xpos,int ypos, int width, int height, int filletrad,Color c) {
	roundedBoxRGBA(renderer,xpos,ypos,width,height,filletrad,c.r,c.g,c.b,c.a);
}

void draw_outline_rectangle(SDL_Renderer *renderer, int xpos, int ypos,int width, int height, Color color) {
	SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
	SDL_Rect r = {xpos,ypos,width,height};
	SDL_RenderFillRect(renderer,&r);
}

void draw_outline_circle(SDL_Renderer *renderer, int xpos, int ypos, int radius,Color c) {
	filledCircleRGBA(renderer,xpos,ypos,radius,c.r,c.g,c.b,c.a);
}

void draw_outline_rounded_rectangle(SDL_Renderer *renderer,int xpos,int ypos, int width, int height, int filletrad,Color c) {
	roundedRectangleRGBA(renderer,xpos,ypos,width,height,filletrad,c.r,c.g,c.b,c.a);
}

int buttonNameToNumber(char* name) {
	int buttonnumber = NULL;

		if(strcmp(name,"A") == 0) {
			buttonnumber = KEY_A;
		}

		else if(strcmp(name,"B") == 0) {
			buttonnumber = KEY_B;
		}
			
		else if(strcmp(name,"X") == 0) {
			buttonnumber = KEY_X;
		}
		else if(strcmp(name,"Y") == 0) {
			buttonnumber = KEY_Y;
		}
			
		else if(strcmp(name,"Left Stick") == 0) {
			buttonnumber = KEY_LSTICK;
		}
			
		else if(strcmp(name,"Right Stick") == 0) {
			buttonnumber = KEY_RSTICK;
		}
			
		else if(strcmp(name,"L") == 0) {
			buttonnumber = KEY_L;
		}
			
		else if(strcmp(name,"R") == 0) {
			buttonnumber = KEY_R;
		}
			
		else if(strcmp(name,"ZL") == 0) {
			buttonnumber = KEY_ZL;
		}
			
		else if(strcmp(name,"ZR") == 0) {
			buttonnumber = KEY_ZR;
		}
			
		else if(strcmp(name,"+") == 0) {
			buttonnumber = KEY_PLUS;
		}
			
		else if (strcmp(name,"-") == 0) {
			buttonnumber = KEY_MINUS;
		}
			
		else if(strcmp(name,"Left") == 0) {
			buttonnumber = KEY_DLEFT;
		}
			
		else if(strcmp(name,"Up") == 0) {
			buttonnumber = KEY_DUP;
		}
		
		else if(strcmp(name,"Right") == 0) {
			buttonnumber = KEY_DRIGHT;
		}
		
		else if(strcmp(name,"Down") == 0) {
			buttonnumber = KEY_DDOWN;
		}
			
	
	return buttonnumber;
}

//note if in handheld both map to #0
bool isButtonPressed(HidControllerID joyconnum, int button) {
	{
		u64 kDown = hidKeysDown(joyconnum);
		if (kDown & button) {
			return true;
		}
		return false;
	}

}
//void draw_filled_circle
