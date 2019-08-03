#include "sdllib.h"

#define SCREEN_FPS 30

int main(int argc, char *argv[]) {
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

	int frame = 0;
	SDL_Event event;
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool done = false;
	bool update = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
		SDL_Log("SDL_Init: %s\n", SDL_GetError());
		return -1;
	}

	window = SDL_CreateWindow("sdl2_gles2", 0, 0, 1920, 1080, 0);
	if (!window) {
		SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	int w = 1920;
	int h = 1080;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 111, 111, 111, 255);
	SDL_GetWindowSize(window, &w, &h);
	SDL_Rect f = {0, 0, 1920, 1080};
	SDL_RenderFillRect(renderer, &f);

	frame = 0;
	while (!done) {
		hidScanInput();
		if (isButtonPressed(CONTROLLER_P1_AUTO,KEY_A)) {
			draw_filled_circle(renderer,64,64,15,Color{255,0,0,255});
			update = true;
		}
		else if (isButtonPressed(CONTROLLER_P1_AUTO,buttonNameToNumber("+"))) {
			done = 1;
		}

			if (update == true) {

				SDL_RenderPresent(renderer);
				update = false;
			}
		}


SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;
}