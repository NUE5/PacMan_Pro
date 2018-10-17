#include "Menu.h".
#include<iostream>


Menu::Menu(float width,float height)
{
	if (!font.loadFromFile(""))
	{
		std::cout << "error\n";
	}
	//******************************************************
	//first item
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("START");
	menu[0].setPosition(sf::Vector2f(width / 2, (height / max_numberofitems + 1) * 1));
	//*******************************************************
	//second item
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].setString("EXIT");
	menu[1].setPosition(sf::Vector2f(width / 2, (height / max_numberofitems + 1) * 2));

	selecteditemindex = 0;

}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; max_numberofitems; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::movedown()
{
	if (selecteditemindex + 1 < max_numberofitems)
	{
		menu[selecteditemindex].setFillColor(sf::Color::White);
		selecteditemindex++;
		menu[selecteditemindex].setFillColor(sf::Color::Red);
	}
}





