#ifndef SCOREBOARD
#define SCOREBOARD

#include <string>
#include "context.hpp"
#include <SDL2/SDL_ttf.h>

namespace Scoreboard{
	extern int score;
	extern int hiScore;
	extern SDL_Texture* text;
	extern TTF_Font* font;

	void init();
	void drawScore();
	void addScore(int score);
	void quit();

};

#endif
