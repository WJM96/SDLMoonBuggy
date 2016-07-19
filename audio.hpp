#ifndef AUDIO
#define AUDIO
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include "log.hpp"

//this is a namespace and not a class because we don't really need to store any data
namespace Audio{
	const int SAMPLESIZE = 2048;
	const int MONO = 1;
	const int STEREO = 2;
	const int FLAGS = MIX_INIT_OGG;
	
	void init();
	void playSound(Mix_Chunk* sound);
	void playMusic(Mix_Music* sound);
	void quit();
};
#endif
