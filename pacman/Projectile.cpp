#include "Projectile.h"



Projectile::Projectile()
{
	rect1.setSize(sf::Vector2f(30, 30));
	rect1.setPosition(sf::Vector2f(0 ,0));
	rect1.setFillColor(sf::Color::Transparent);
	sprite1.setTextureRect(sf::IntRect(32*2, 32*7, 32, 32));
}


Projectile::~Projectile()
{
}

void Projectile::update()
{
	if (direction == 1)
	{
		rect1.move(0, -movespeed);
	}
	if (direction == 2)
	{
		rect1.move(0, movespeed);
	}
	if (direction == 3)
	{
		rect1.move(-movespeed, 0);
	}
	if (direction == 4)
	{
		rect1.move(movespeed, 0);
	}
	counterlifetime++;
	if (counterlifetime > 30)
	{
		destroy = true;
	}
	sprite1.setPosition(rect1.getPosition());
}
