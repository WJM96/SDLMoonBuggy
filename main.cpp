#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "log.hpp"
#include "audio.hpp"
#include "context.hpp"
#include "animation.hpp"

const std::string VERSION = "v0.0.1";
const std::string TITLE = "Moon Buggy";
const std::string AUTHOR = "Wesley McClintock";

int main(int argc, char* argv[]){
	Audio::init();
	Context::init(TITLE + " " + VERSION + "--" + AUTHOR, 640, 480);
	
	Animation testAnim;
	testAnim.set({0, 0, 36, 20}, 4, 100);
	SDL_Texture* texture = Context::loadTexture("./res/sprites.png");
	
	SDL_Event event;
	bool playing = true;
	
	int now = SDL_GetTicks();
	int last = 0;
	int dt = 1;
	while(playing){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				playing = false;
			}
		}
		
		//update and draw
		testAnim.update(dt);
		testAnim.draw(30, 30, texture);
		
		//show 
		SDL_RenderPresent(Context::ren);
		SDL_RenderClear(Context::ren);
		
		now = SDL_GetTicks();
		dt = now - last;
		last = now;
		//std::cout << dt << std::endl;
	}
	
	
	
	SDL_DestroyTexture(texture);
	Audio::quit();
	Context::quit();
	SDL_Quit();
	return 0;
}

