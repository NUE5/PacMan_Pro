#pragma once
#include "Animation.h"
class Projectile :
	public Animation
{
public:
	Projectile();
	~Projectile();
	int movespeed = 10;
	int attackdamage = 5;
	int counterwalking = 0;
	int direction = 0;
	bool enemyprojectile = false;
	bool destroy = false;
	int counterlifetime = 0;
	void update();
	//void updatemovement();
};

