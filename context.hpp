#ifndef CONTEXT
#define CONTEXT

#include "log.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//graphics stuff
namespace Context{
	extern SDL_Window* win;
	extern SDL_Renderer* ren;
	const float RENDER_SCALE = 2;
	void init(std::string title, int w, int h);
	SDL_Texture* loadTexture(std::string file);
	void quit();
};

#endif
