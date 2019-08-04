//
// Created by gnations on 8/2/2019.
//

#include "sdllib.h"
#include "jsonlib.h"
std::vector<const char*> render_queue (50);
SDL_Renderer *renderer;

void set_sdl_renderer(SDL_Renderer *render) {
	renderer = render;
}
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

void pushToRenderList(const char* torender) {
	render_queue.push_back(torender);
}

void processRenderQueue() {
	for (std::vector<const char*>::iterator it = render_queue.begin(); it != render_queue.end(); it++) {
	renderSDLObject(*it);
	}
}

void renderSDLObject(const char* render_object ) {
	json_object *obj_to_render = json_tokener_parse(render_object);
	const char* call = getCall(obj_to_render);
	int xpos = getXOffset(obj_to_render);
	int ypos = getYOffset(obj_to_render);
	int radius = getRadius(obj_to_render);
	int width = getWidth(obj_to_render);
	int height = getHeight(obj_to_render);
	Color c = getColor(obj_to_render);
	if (strcmp("filled_circle",call) == 0) {
		draw_filled_circle(renderer,xpos,ypos,radius,c);
	}
}

int buttonNameToNumber(std::string name) {
	int buttonnumber = -1;

		if(strcmp(name.c_str(),"A") == 0) {
			buttonnumber = KEY_A;
		}

		else if(strcmp(name.c_str(),"B") == 0) {
			buttonnumber = KEY_B;
		}
			
		else if(strcmp(name.c_str(),"X") == 0) {
			buttonnumber = KEY_X;
		}
		else if(strcmp(name.c_str(),"Y") == 0) {
			buttonnumber = KEY_Y;
		}
			
		else if(strcmp(name.c_str(),"Left Stick") == 0) {
			buttonnumber = KEY_LSTICK;
		}
			
		else if(strcmp(name.c_str(),"Right Stick") == 0) {
			buttonnumber = KEY_RSTICK;
		}
			
		else if(strcmp(name.c_str(),"L") == 0) {
			buttonnumber = KEY_L;
		}
			
		else if(strcmp(name.c_str(),"R") == 0) {
			buttonnumber = KEY_R;
		}
			
		else if(strcmp(name.c_str(),"ZL") == 0) {
			buttonnumber = KEY_ZL;
		}
			
		else if(strcmp(name.c_str(),"ZR") == 0) {
			buttonnumber = KEY_ZR;
		}
			
		else if(strcmp(name.c_str(),"+") == 0) {
			buttonnumber = KEY_PLUS;
		}
			
		else if (strcmp(name.c_str(),"-") == 0) {
			buttonnumber = KEY_MINUS;
		}
			
		else if(strcmp(name.c_str(),"Left") == 0) {
			buttonnumber = KEY_DLEFT;
		}
			
		else if(strcmp(name.c_str(),"Up") == 0) {
			buttonnumber = KEY_DUP;
		}
		
		else if(strcmp(name.c_str(),"Right") == 0) {
			buttonnumber = KEY_DRIGHT;
		}
		
		else if(strcmp(name.c_str(),"Down") == 0) {
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
