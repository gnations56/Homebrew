#include "sdllib.h"
#include "jsonlib.h"
#include "soundlib.h"
int main(int argc, char *argv[]) {

	SDL_Window *window;
	SDL_Renderer *renderer;
	bool done = false;
	bool update = true;

//	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) < 0) {
//		SDL_Log("SDL_Init: %s\n", SDL_GetError());
//		return -1;
//	}
SDL_Init(SDL_INIT_AUDIO);
consoleInit(NULL);
//	window = SDL_CreateWindow("sdl2_gles2", 0, 0, 1920, 1080, 0);
//	if (!window) {
//		SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
//		SDL_Quit();
//		return -1;
//	}
//
//	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//	if (!renderer) {
//		SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
//		SDL_Quit();
//		return -1;
//	}
//	set_sdl_renderer(renderer);

	int w = 1920;
	int h = 1080;

//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//	SDL_RenderClear(renderer);
//	SDL_SetRenderDrawColor(renderer, 111, 111, 111, 255);
//	SDL_GetWindowSize(window, &w, &h);
//	SDL_Rect f = {0, 0, 1920, 1080};
//	SDL_RenderFillRect(renderer, &f);
	Mix_Chunk *sfx;
	Mix_Music *bgm;

//	printf("romfs init status: %d", rc);
	if (initializeMixer(44100,2,2048) == true) {
		 bgm = loadMusicFile("/sounds/Insert.wav");
//		printf("Mix Error: %s",Mix_GetError());
		playMusic(bgm, -1);
		printf("Mix Error: %s",Mix_GetError());
		 sfx = loadSFXFile("/sounds/Shutdown.wav");
		printf("Mix Error: %s",Mix_GetError());
	}
//	printf("Mix Error: %s",Mix_GetError());



//	processRenderQueue();
	while (!done) {
		hidScanInput();
		if (isButtonPressed(CONTROLLER_P1_AUTO,KEY_A)) {
			const char* render_obj = createRenderObject("filled_circle",0,0,15,0,0,Color{255,0,0,255});
			playSFX(sfx,-1,1);
			pushToRenderList(render_obj);
//			update = true;
		}
		else if (isButtonPressed(CONTROLLER_P1_AUTO,buttonNameToNumber("+"))) {

			done = 1;
		}

			if (update == true) {
				processRenderQueue();
				SDL_RenderPresent(renderer);
				update = false;
			}
			consoleUpdate(NULL);
		}

//SDL_DestroyRenderer(renderer);
//SDL_DestroyWindow(window);
SDL_Quit();
return 0;
}