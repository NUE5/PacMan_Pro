#pragma once
#include "Animation.h"
class Tile :
	public Animation
{
public:
	Tile();
	~Tile();
	
	void update(int x, int y);
private:
	int positionx , positiony;

};

