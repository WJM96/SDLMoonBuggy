#include "player.hpp"

Player::Player(){
	anim.set({0, 0, 36, 20}, 4, 100);
	tick = 0;
	jumping = false;
	xoffset = 0;
	
	powerSound = Mix_LoadWAV("./res/power-up.wav");
	damageSound = Mix_LoadWAV("./res/damage.wav");
	jumpSound = Mix_LoadWAV("./res/jump.wav");
	engineSound = Mix_LoadWAV("./res/engine.wav");
}
void Player::update(int dt){
	anim.update(dt);
	if(jumping){
		tick += dt;
		if(tick > JUMPTIME){
			tick = 0;
			jumping = false;
		}
	}
	else{
		tick = 0;
	}
}
void Player::moveLeft(int dt){
	xoffset -= ACCELSPEED * (float(dt)/1000);
	if(xoffset < XMIN){
		xoffset = XMIN;
	}
	if(lastDir != 1){
		Audio::playSound(engineSound);
		lastDir = 1;
	}
}
void Player::moveRight(int dt){
	xoffset += ACCELSPEED * (float(dt)/1000);
	if(xoffset > XMAX){
		xoffset = XMAX;
	}
	if(lastDir != 2){
		Audio::playSound(engineSound);
		lastDir = 2;
	}
}
void Player::draw(SDL_Texture* sprites){
	int x = XLOCATION + xoffset;
	float jumpProgress = float(tick)/JUMPTIME * M_PI;
	int y = YLOCATION -(sinf(jumpProgress) * JUMPHEIGHT);
	anim.draw(x, y, sprites);
}
void Player::jump(){
	if(!jumping){
		jumping = true;
		Audio::playSound(jumpSound);
	}
}
bool Player::isJumping(){}
Player::~Player(){
	Mix_FreeChunk(powerSound);
	Mix_FreeChunk(damageSound);
	Mix_FreeChunk(jumpSound);
	Mix_FreeChunk(engineSound);
}
