#ifndef PLAYER
#define PLAYER

#include "audio.hpp"
#include "context.hpp"
#include "animation.hpp"

class Player{
public:	
	static const int SPEED = 100, //pps (pixels per second)
				JUMPTIME = 700, //ms
				JUMPHEIGHT = 25, //pixels
				ACCELSPEED = 50, //pps
				YLOCATION = 120, //pixels
				XLOCATION = 64,  //pixels
				XMAX = 64 + XLOCATION,
				XMIN = 0 - XLOCATION;
	Player();
	void update(int dt);
	void moveLeft(int dt);
	void moveRight(int dt);
	void draw(SDL_Texture* sprites);
	void jump();
	bool isJumping();
	~Player();
private:
	Animation anim;
	float xoffset;
	bool jumping;
	int lastDir; //just for our engine noise
	int tick;
	Mix_Chunk* powerSound;
	Mix_Chunk* damageSound;
	Mix_Chunk* jumpSound;
	Mix_Chunk* engineSound;
};

#endif
