#include "Windo2.h"
#include<iostream>


Windo2::Windo2(float width, float height)
{
	if (!font1.loadFromFile("pacfont.ttf"))
	{
		std::cout << "Error\n";
	}
	gameover.setFont(font1);
	gameover.setFillColor(sf::Color::Yellow);
	gameover.setString("Game Over \n   123456789");
	gameover.setCharacterSize(60);
	gameover.setPosition(sf::Vector2f(120,420 ));
	if (!font2.loadFromFile("pacfont.ttf"))
	{
		std::cout << "Error\n";
	}
	win.setFont(font2);
	win.setFillColor(sf::Color::Yellow);
	win.setString("Congratulations \n      123456789 ");
	win.setCharacterSize(45);
	win.setPosition(sf::Vector2f(120, 420));
	
	
}

void Windo2::drawgameover(sf::RenderWindow & window)
{
	window.draw(gameover);
}

void Windo2::iswin(sf::RenderWindow & window)
{
	window.draw(win);
}


Windo2::~Windo2()
{
}
