#pragma once
#include"SFML/Graphics.hpp"
#define max_numberofitems 2
class Menu
{
public:
	Menu(float width,float height);
	~Menu();
	void draw(sf::RenderWindow &window);
	void moveup();
	void movedown();
	int getpresseditem()
	{
		return selecteditemindex;
	}
	private:
		int selecteditemindex;
		sf::Font font;
		sf::Text menu[max_numberofitems];

};

