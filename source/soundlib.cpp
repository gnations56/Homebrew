//
// Created by gnations on 8/4/2019.
//

#include "soundlib.h"

bool initializeMixer(int frequency, int channels, int chunksize){
	if( Mix_OpenAudio( frequency, MIX_DEFAULT_FORMAT, channels, chunksize ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
	}
	return true;
}

Mix_Music * loadMusicFile(std::string filepath){
	Mix_Music *mus;
	mus = Mix_LoadMUS(filepath.c_str());
	return mus;
}

Mix_Chunk * loadSFXFile(std::string filepath){
	Mix_Chunk *sfx;
	sfx = Mix_LoadWAV(filepath.c_str());
	return sfx;
}

void playMusic(Mix_Music *music, int loops) {
	//set loops to -1 to repeat until halted
	Mix_PlayMusic(music,loops);
}

int playSFX(Mix_Chunk *sfx, int channel, int times_to_repeat){
	Mix_PlayChannel(channel,sfx,times_to_repeat);
}

void pauseMusic() {
	if (Mix_PlayingMusic() == 0) {
		Mix_ResumeMusic();
	}
	else {
		Mix_PauseMusic();
	};
}

void stopMusic(){
	Mix_HaltMusic();
}

void stopSFX(int channel){
	//if -1 is passed will halt ALL channels
	Mix_HaltChannel(channel);
}

void cleanUpMusic(Mix_Music *music){
	Mix_FreeMusic(music);
}

void cleanUpSFX(Mix_Chunk *sfx){

}