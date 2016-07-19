#ifndef ANIMATION
#define ANIMATION

#include "context.hpp"

class Animation{
public:
	Animation();
	Animation(SDL_Rect clip, int frames, int delay);
	void set(SDL_Rect clip, int frames, int delay);
	void update(int dt);
	void draw(int x, int y, SDL_Texture* texture);
	~Animation();
private:
	SDL_Rect clip;
	int cFrame, numFrames;
	int msDelay;
	int tick;
};

#endif
