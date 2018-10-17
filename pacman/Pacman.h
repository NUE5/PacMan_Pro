#pragma once
#include "Animation.h"
class Pacman :
	public Animation
{
public:

	Pacman();
	~Pacman();
	//update pacman and it's icon while the key pressed
	void update();
	//update keyboard events
	void updatemovement();
	//display the dith icon if pacman hit a wall
	void pacmandead();
	int getdirection()const { return direction; }
	

private:
	int lives, countwalk, direction; float movespeed;
	bool isalive;
	bool upkeypressed;
	bool downkeypressed;
	bool leftkeypressed;
	bool rightkeypressed;
};

