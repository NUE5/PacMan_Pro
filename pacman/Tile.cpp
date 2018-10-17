#include "Tile.h"



Tile::Tile()
{
	positionx = 0;
	positiony = 0;
	rect1.setSize(sf::Vector2f(20, 20));
	//rect1.setPosition(sf::Vector2f(positionx * 24, positiony * 24));
}


Tile::~Tile()
{
}

void Tile::update(int x, int y)
{

	rect1.setPosition(sf::Vector2f(x * 24, y * 24));
}
