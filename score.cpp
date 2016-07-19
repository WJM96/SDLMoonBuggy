#include "score.hpp"

namespace Scoreboard{
	int score = 0;
	int hiScore = 0;
	SDL_Texture* text = NULL;
	TTF_Font* font = NULL;
};

void Scoreboard::init(){
	if( TTF_Init() == -1){
		Log::err("Couldn't load ttf!");
		Log::err(TTF_GetError());
	}
	
	font = TTF_OpenFont("./res/PressStart2P.ttf", 8);
	if(font == NULL){
		Log::err("Couldn't load font!");
		Log::err(TTF_GetError());
	}
	
	addScore(0);
}
void Scoreboard::drawScore(){
	int w, h;
	SDL_QueryTexture(text, NULL, NULL, &w, &h);
	SDL_Rect dest = {3, 3, w, h};
	SDL_RenderCopy(Context::ren, text, NULL, &dest);
}
void Scoreboard::addScore(int points){
	score += points;
	if(score > hiScore){
		hiScore = score;
	}
	
	std::string scorestr = "score: [" + std::to_string(score) + "] hi: [" + std::to_string(hiScore) + "]";
	
	SDL_Surface* msg = TTF_RenderText_Solid( font, scorestr.c_str(), {255, 255, 255, 255} );
	if(msg == NULL){
		Log::err("Couldn't render the text!");
		Log::err(TTF_GetError());
	}
	SDL_DestroyTexture(text);
	text = SDL_CreateTextureFromSurface(Context::ren, msg);
	SDL_FreeSurface(msg);
}
void Scoreboard::quit(){
	SDL_DestroyTexture(text);
	TTF_CloseFont(font);
	TTF_Quit();
}
