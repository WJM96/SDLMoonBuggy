#include "context.hpp"

namespace Context{
	SDL_Window* win = NULL;
	SDL_Renderer* ren = NULL;
	
}

void Context::init(std::string title, int w, int h){
	//init the video subsystem
	if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0){
		Log::warn("Couldn't initialize video subsystem!");
		Log::warn(SDL_GetError());
	}
	
	//create the windowj
	win = SDL_CreateWindow(title.c_str(), 100, 100, w, h, SDL_WINDOW_SHOWN);
	if(win == NULL){
		Log::warn("Couldn't initialize Window!");
		Log::warn(SDL_GetError());
	}

	//and the renderer
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(ren == NULL){
		Log::warn("Couldn't initialize Renderer!");
		Log::warn(SDL_GetError());
	}
	
	
	//SDL_img
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
		Log::warn("Couldn't initialize SDL_IMG!");
		Log::warn(IMG_GetError());
	}
	
	SDL_RenderSetScale(ren, RENDER_SCALE, RENDER_SCALE);
	
}

SDL_Texture* Context::loadTexture(std::string file){
	SDL_Surface* img = IMG_Load(file.c_str());
	SDL_Texture* text = NULL;
	if(img == NULL){
		Log::err("Couldn't load image into surface");
		Log::err(IMG_GetError());
		return NULL;
	}
	else{
		text = SDL_CreateTextureFromSurface(ren, img);
		if(text == NULL){
			Log::err("Couldn't load surface into texture");
			Log::err(SDL_GetError());
			SDL_FreeSurface(img);
			return NULL;
		}
		else{
			SDL_FreeSurface(img);
			return text;
		}
	}
}

void Context::quit(){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	win = NULL;
	ren = NULL;
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	IMG_Quit();
}
