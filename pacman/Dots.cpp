#include "Dots.h"



Dots::Dots()
{
	//rect1.setSize(sf::Vector2f(30, 30));
	////rect1.setPosition(sf::Vector2f(336, 484));
	////sprite1.setPosition(sf::Vector2f(0, 0));
	isshowing = true;
	islargedot = false;
	countwalk = 0;
}


Dots::~Dots()
{
}

Dots::Dots(int x, int y )
{
	rect1.setSize(sf::Vector2f(16, 16));
	rect1.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 5));
	rect1.setFillColor(sf::Color::Green);
	sprite1.setPosition(sf::Vector2f(x, y));
	
}

void Dots::setposition(int x, int y)
{
	sprite1.setPosition(sf::Vector2f(x , y ));
	rect1.setPosition(sf::Vector2f(x, y));
}

void Dots::update()
{
	sprite1.setTextureRect(sf::IntRect(countwalk * 24, 0, 24, 24));
	countwalk++;
	if (countwalk == 4)
	{
		countwalk = 0;
	}
}


