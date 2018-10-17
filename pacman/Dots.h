#pragma once
#include "Animation.h"
class Dots :
	public Animation
{
public:
	Dots();
	~Dots();
	Dots(int x, int y);
	void setisshownig(bool isshowing)
	{
		this->isshowing = isshowing;
	}
	bool getisshowing() const
	{
		return isshowing;
	}
	void setposition(int x, int y); // set the position of the dots
	void setlargedot(bool largedot) //create large dots
	{
		this->islargedot = largedot;
	}
	bool getlargedot() const
	{
		return this->islargedot;
	}
	void update();
	
private:
	bool isshowing, islargedot; int  countwalk ,value;
};

