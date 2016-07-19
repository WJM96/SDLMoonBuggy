#include "audio.hpp"

void Audio::init(){
	
	if(SDL_InitSubSystem(SDL_INIT_AUDIO) != 0){
		Log::warn("Couldn't init SDL's audio subsystem!");
		Log::warn(SDL_GetError());
	}
	
	if((Mix_Init(FLAGS) & FLAGS) != FLAGS){
		Log::warn("Couldn't init SDL_Mixer!");
		Log::warn(Mix_GetError());
	}
	
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, SAMPLESIZE) <= 0){
		Log::warn("Couldn't Open Audio!");
		Log::warn(Mix_GetError());
	}
}
void Audio::playSound(Mix_Chunk* sound){
	if( Mix_PlayChannel(-1, sound, 0) != 0){
		Log::warn("Problem playing sound!");
		Log::warn(Mix_GetError());
	}
}
void Audio::playMusic(Mix_Music* sound){
	if( Mix_PlayMusic(sound, 0) != 0){
		Log::warn("Problem playing Music!");
		Log::warn(Mix_GetError());
	}
}
void Audio::quit(){
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	Mix_Quit();
}
