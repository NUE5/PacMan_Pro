#pragma once
#include "Animation.h"
class Ghosts :
	public Animation
{
public:
	Ghosts();
	~Ghosts();

	void update(); //update ghost's position;
	void setposition(int x, int y);
	
	void setghostdirec(int m)
	{
		
		direction = m;
	}
	int getghostsecdirec() const 
	{ 
		return direction;
	}
	bool getisafraid() const
	{
		return this->afraid;
	}
	void setisafraid(bool isafraid)
	{
		this->afraid = isafraid;
	}
	bool getoutofbox()const
	{ 
		return outofbox; 
	}
	void setoutofbox(bool isoutofbox)
	{
		this->outofbox = isoutofbox;
	}
	bool gethitwall()const
	{
		return hitwall;
	}
	void sethitwall(bool ishitwall) 
	{
		hitwall =ishitwall; 
	}
	void randommovement();
	void moving(); //move the ghost depending on a certain variable
	
	int getghostdirec() const
	{
		return direction;
	}
public:

	sf::RectangleShape direct;
	sf::RectangleShape uprect;
	sf::RectangleShape downrect;
	sf::RectangleShape leftrect;
	sf::RectangleShape rightrect;

	bool outofbox;
	bool blockup = false;
	bool blockdown = false;
	bool blockright = false;
	bool blockleft = false;
	
	int counter = 0 , direction , movespeed=0;
	

private:
	bool afraid;
	bool alive;
	bool hitwall;
	bool visited;
	int  x_axis, y_axis, countwalk;
};

