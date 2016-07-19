#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "log.hpp"
#include "player.hpp"
#include "score.hpp"

const std::string VERSION = "v0.0.1";
const std::string TITLE = "Moon Buggy";
const std::string AUTHOR = "Wesley McClintock";

int main(int argc, char* argv[]){
	Audio::init();
	Context::init(TITLE + " " + VERSION + "--" + AUTHOR, 640, 480);
	Scoreboard::init();
	
	
	SDL_Texture* sprites = Context::loadTexture("./res/sprites.png");
	
	Player player;
	
	SDL_Event event;
	const unsigned char* keys = SDL_GetKeyboardState(NULL);
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
		//check input
		if(keys[SDL_SCANCODE_SPACE]){
			player.jump();
		}
		if(keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]){
			player.moveLeft(dt);
		}
		if(keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]){
			player.moveRight(dt);
		}
		
		
		//update and draw
		player.update(dt);
		player.draw(sprites);
		Scoreboard::drawScore();
		
		//show 
		SDL_RenderPresent(Context::ren);
		SDL_RenderClear(Context::ren);
		
		//wait
		SDL_Delay(32);
		
		now = SDL_GetTicks();
		dt = now - last;
		last = now;
		//std::cout << dt << std::endl;
	}
	
	
	
	SDL_DestroyTexture(sprites);
	Audio::quit();
	Context::quit();
	Scoreboard::quit();
	SDL_Quit();
	return 0;
}

