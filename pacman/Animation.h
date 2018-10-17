#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
class Animation
{
public:
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Text text;
	int x, y;
	Animation(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	Animation();
	~Animation();


};

