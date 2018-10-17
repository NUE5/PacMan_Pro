#include "Pacman.h"



Pacman::Pacman()
{
	countwalk = 1;
	lives = 3;
	movespeed = 7;
	// set the size of the character
	rect1.setSize(sf::Vector2f(7, 7));
	rect1.setPosition(sf::Vector2f(334, 640));
	rect1.setFillColor(sf::Color::Red);
	sprite1.setPosition(sf::Vector2f(0, 0));


	rect2.setSize(sf::Vector2f(22, 20));
	rect2.setPosition(sf::Vector2f(334,640 ));
	


	//initialize keyboard events
	upkeypressed = false;
	downkeypressed = false;
	leftkeypressed = false;
	rightkeypressed = false;
}


Pacman::~Pacman()
{
}

void Pacman::update()
{

	sprite1.setPosition(rect1.getPosition().x - 11, rect1.getPosition().y - 11);
	rect2.setPosition(sprite1.getPosition().x + 1, sprite1.getPosition().y + 2);
}

void Pacman::updatemovement()
{
	upkeypressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	downkeypressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	leftkeypressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	rightkeypressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	
	if (upkeypressed)
	{
		rect1.move(0, -movespeed);
		sprite1.setTextureRect(sf::IntRect(countwalk*24, 48, 24, 24));
		direction = 1;
	}
	else if (downkeypressed)
	{
		rect1.move(0, movespeed);
		sprite1.setTextureRect(sf::IntRect(countwalk*24, 24*3, 24, 24));
		direction = 2;
	}
	else if (leftkeypressed)
	{
		rect1.move(-movespeed, 0);
		sprite1.setTextureRect(sf::IntRect(countwalk*24, 24, 24, 24));
		direction = 3;
	}
	else if (rightkeypressed)
	{
		rect1.move(movespeed, 0);
		sprite1.setTextureRect(sf::IntRect(countwalk*24, 0, 24, 24));
		direction = 4;
	}
	countwalk++; // to change between open and close mouse 
	if (countwalk == 3)
	{
		countwalk = 0;
	}
}

void Pacman::pacmandead()
{
	sprite1.setTextureRect(sf::IntRect(countwalk * 24, 96, 24, 24));
	countwalk++;
	if (countwalk == 6) countwalk = 0; //pacman vanish
}

