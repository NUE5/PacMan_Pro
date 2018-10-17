#pragma once
#include<SFML\Graphics.hpp>
class Windo2
{
public:

	Windo2(float width, float height);
	void drawgameover(sf::RenderWindow &window);
	void iswin(sf::RenderWindow &window);
	
	~Windo2();
	int score = 0;
private:
	
	sf::Font font1;
	sf::Text gameover;
	sf::Text win ;
	sf::Font font2;
	
};

