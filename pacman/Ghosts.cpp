#include "Ghosts.h"
#include<math.h>

Ghosts::Ghosts()
{
	movespeed = 7;
	rect1.setPosition(sf::Vector2f(280, 410));
	sprite1.setPosition(sf::Vector2f(280, 410));
	rect1.setFillColor(sf::Color::Red);
	rect1.setSize(sf::Vector2f(22, 22));
	rect2.setSize(sf::Vector2f(5, 5));
	
	 afraid = false;
	 outofbox = false;
	 blockup = false;
	 blockdown = false;
	 blockright = false;
	 blockleft = false;
	 hitwall = false;
	 visited = false;
	direct.setSize(sf::Vector2f(5, 5));
	uprect.setSize(sf::Vector2f(17, 17));
	downrect.setSize(sf::Vector2f(17, 17));
	leftrect.setSize(sf::Vector2f(17, 17));
	rightrect.setSize(sf::Vector2f(17, 17));
	
}


Ghosts::~Ghosts()
{
}

void Ghosts::update()
{
	
	sprite1.setPosition(rect1.getPosition().x - 4, rect1.getPosition().y - 4);
	sprite2.setPosition(rect1.getPosition().x - 4, rect1.getPosition().y - 4);
	uprect.setPosition(rect1.getPosition().x, rect1.getPosition().y - 7);
	downrect.setPosition(rect1.getPosition().x, rect1.getPosition().y + 17);
	leftrect.setPosition(rect1.getPosition().x - 7, rect1.getPosition().y);
	rightrect.setPosition(rect1.getPosition().x + 17, rect1.getPosition().y);

	switch (direction)
	{
	case 1:
		direct.setPosition(rect1.getPosition().x + 5, rect1.getPosition().y + 17);
		break;
	case 2:
		direct.setPosition(rect1.getPosition().x + 17, rect1.getPosition().y + 8);
		break;
	case 3:
		direct.setPosition(rect1.getPosition().x - 5, rect1.getPosition().y + 8);
		break;
	case 4:
		direct.setPosition(rect1.getPosition().x + 8, rect1.getPosition().y - 5);
		break;
	}
}

void Ghosts::setposition(int x, int y)
{
	sprite1.setPosition(sf::Vector2f(x, y));
	sprite2.setPosition(sf::Vector2f(x, y));
	rect1.setPosition(sf::Vector2f(x, y));
}
void Ghosts::moving()//random ghost behavior 
{
	switch (direction)
	{
	case 1:

		sprite1.move(0, movespeed);//moves down
		rect1.move(0, movespeed);
		sprite2.move(0, movespeed);
		break;

	case 2:

		sprite1.move(movespeed, 0);// moves to the Right
		rect1.move(movespeed, 0);
		sprite2.move(movespeed, 0);
		break;
	case 3:
	
		sprite1.move(-movespeed, 0); // moves to the Left
		rect1.move(-movespeed, 0);
		sprite2.move(-movespeed, 0);
		break;
	case 4:
	
		sprite1.move(0, -movespeed); // moves up
		rect1.move(0, -movespeed);
		sprite2.move(0, -movespeed);
		break;
	}
}



void Ghosts::randommovement()
{
	bool chase = true; int move = 0; 
	while (chase)
	{
		move = rand() % 4 + 1;
		switch (move)
		{
		case 1:
			if (!blockdown)
			{
				direction = 1;
				chase = false;
			}
			break;
		case 2:
			if (!blockright)
			{
				direction = 2;
				chase = false;
			}
			break;
		case 3:
			if (!blockleft)
			{
				direction = 3;
				chase = false;
			}
			break;
		case 4:
			if (!blockup)
			{
				direction = 4;
				chase = false;
			}
			break;


		}
		
	}
	
}



