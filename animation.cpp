#include "animation.hpp"

Animation::Animation(){
	clip = {0, 0 ,0, 0};
	cFrame = 0; numFrames = 1;
	msDelay = 1;
	tick = 0;
}

Animation::Animation(SDL_Rect sclip, int frames, int delay){
	set(sclip, frames, delay);
}
void Animation::set(SDL_Rect sclip, int frames, int delay){
	clip = sclip;
	cFrame = 0; numFrames = frames;
	msDelay = delay;
	tick = 0;
}
void Animation::update(int dt){
	tick += dt;
	if(tick > msDelay){
		cFrame++;
		cFrame = cFrame % numFrames;
		tick = 0;
	}
}
void Animation::draw(int x, int y, SDL_Texture* texture){
	clip.x = cFrame * clip.w;
	SDL_Rect dest = clip;
	dest.x = x;
	dest.y =y;
	SDL_RenderCopy(Context::ren, texture, &clip, &dest);
}
Animation::~Animation(){
	
}
