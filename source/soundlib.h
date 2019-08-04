//
// Created by gnations on 8/4/2019.
//
#include "masterinc.h"
#include <SDL_mixer.h>

bool initializeMixer(int frequency, int channels, int chunksize);
Mix_Music * loadMusicFile(std::string filepath);
Mix_Chunk * loadSFXFile(std::string filepath);
void playMusic(Mix_Music *music,int loops);
int playSFX(Mix_Chunk *sfx, int channel, int times_to_repeat);
void pauseMusic();
void stopMusic();
void stopSFX(Mix_Chunk *sfx);
void cleanUpMusic(Mix_Music *music);
void cleanUpSFX(Mix_Chunk *sfx);

#ifndef HOMEBREW_SOUNDLIB_H
#define HOMEBREW_SOUNDLIB_H

#endif //HOMEBREW_SOUNDLIB_H
