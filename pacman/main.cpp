#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include<vector>
//classes.............
#include"Pacman.h"
#include"Tile.h"
#include"Ghosts.h"
#include"Dots.h"
#include"Projectile.h"
#include"Windo2.h"
//....................
using namespace sf;
using namespace std;
int main()
{
	//constants..........................
	int scale = 3 , dotscounter=259;
	int counter1 = 0, counter2 = 0, outofbox = 0, currentdir = 0, score = 0, posghost = 280,dotindex=0,dotsnumber=245,lives=3;
	sf::Clock boxclock, afraidclock , pclock , spacec , dclock , closeclock;
	bool isoutofbox = false, hitwall = false;
	//...................................
	RenderWindow window(VideoMode(224 * scale, 288 * scale), "Pac_Man");
	window.setFramerateLimit(30);
	Windo2 gameOver(window.getSize().x, window.getSize().y);
	Windo2 won(window.getSize().x, window.getSize().y);
	//loading pacman sprite...............
	sf::IntRect pacSprite(0, 0, 24, 24);
	Pacman player;
	sf::Texture pacman;
	if (!pacman.loadFromFile("images/pacmanDirections.png"))
	{
		std::cout << "Error\n";
	}
	player.sprite1.setTexture(pacman);
	player.sprite1.setTextureRect(pacSprite);

	//.....................................
	// loading ghosts 
	sf::Texture afraidghost;
	sf::IntRect afraidrect(0, 0, 32, 35);
	if (!afraidghost.loadFromFile("images/scared.png"))
	{
		cout << "Error\n";
	}
	std::vector<Ghosts>::iterator ghostsiter;
	std::vector<Ghosts> ghostsarray;

	//pinky

	Ghosts pinky;
	sf::IntRect pinkysprite(0, 0, 40, 240);
	sf::Texture pinkytex;
	if (!pinkytex.loadFromFile("images/pink.png"))
	{
		cout << "Error\n";
	}
	pinky.sprite1.setTexture(pinkytex);
	pinky.sprite2.setTexture(afraidghost);
	pinky.sprite1.setTextureRect(pinkysprite);
	pinky.sprite2.setTextureRect(afraidrect);
	pinky.setposition(25,96);
	ghostsarray.push_back(pinky);

	//inky

	Ghosts inky;
	sf::IntRect inkysprite(0, 0, 40, 240);
	sf::Texture inkytex;
	if (!inkytex.loadFromFile("images/blue.png"))
	{
		cout << "Error\n";
	}
	inky.sprite1.setTexture(inkytex);
	inky.sprite2.setTexture(afraidghost);
	inky.sprite1.setTextureRect(inkysprite);
	inky.sprite2.setTextureRect(afraidrect);
	inky.setposition(620, 96);
	ghostsarray.push_back(inky);

	//blinky

	Ghosts blinky;
	sf::IntRect blinkysprite(0, 0, 40, 240);
	sf::Texture blinkytex;
	if (!blinkytex.loadFromFile("images/red.png"))
	{
		cout << "Error\n";
	}
	blinky.sprite1.setTexture(blinkytex);
	blinky.sprite2.setTexture(afraidghost);
	blinky.sprite1.setTextureRect(blinkysprite);
	blinky.sprite2.setTextureRect(afraidrect);
	blinky.setposition(25, 768);
	ghostsarray.push_back(blinky);

	//clyde

	Ghosts clyde;
	sf::IntRect clydesprite(0, 0, 40, 240);
	sf::Texture clydetex;
	if (!clydetex.loadFromFile("images/yellow.png"))
	{
		cout << "Error\n";
	}
	clyde.sprite1.setTexture(clydetex);
	clyde.sprite2.setTexture(afraidghost);
	clyde.sprite1.setTextureRect(clydesprite);
	clyde.sprite2.setTextureRect(afraidrect);
	clyde.setposition(620, 768);
	ghostsarray.push_back(clyde);


	//......................................
	//loading the map ......................
	sf::Texture map;

	if (!map.loadFromFile("images/pacmanMap2.png"))
	{
		std::cout << "Error\n";
	}
	sf::Sprite mapsprite;
	mapsprite.setTexture(map);
	mapsprite.setScale(3, 3);
	//loading the walls
	std::ifstream fin;
	fin.open("level.txt");
	int val;
	if (fin.fail())
	{
		cout << "Errormap/n";
	}
	sf::Font font;
	
	//...................................
	
	Dots dots;
	std::vector<Dots>::const_iterator dotsiter;
	std::vector<Dots> dotsarray;
	sf::IntRect dotsrec(0,0, 24, 24);
	sf::Texture dotstex;
	sf::Texture largedottex;
	sf::Texture fruittex;
	if (!dotstex.loadFromFile("images/pellets.png"))
	{
		cout << "Error\n";
	}
	if (!largedottex.loadFromFile("images/largedot.png"))
	{
		cout << "Error\n";
	}
	if (!fruittex.loadFromFile("images/f.png"))
	{
		cout << "Error\n";
	}
	//projectile
	Projectile projectile1;
	sf::Texture fireball;
	if (!fireball.loadFromFile("images/ball.png"))
	{
		cout << "Error\n";
	}
	projectile1.sprite1.setTexture(fireball);
	std::vector<Projectile>::const_iterator proiter;
	std::vector<Projectile> proarray;
	//...................................
	

	//loading music file.................
	sf::Music intro;
	intro.openFromFile("pacman_beginning.wav");
	intro.setVolume(60);
	intro.play();

	sf::Music eatdot;
	eatdot.openFromFile("pacman_chomp.wav");
	eatdot.setVolume(60);

	sf::Music prointersect;
	prointersect.openFromFile("pacman_eatfruit.wav");
	prointersect.setVolume(90);

	sf::Music gameovr;
	gameovr.openFromFile("pacman_death.wav");
	gameovr.setVolume(240);
	 
	sf::Music wn;
	wn.openFromFile("pacman_intermission.wav");
	wn.setVolume(240);

	//...................................
	//setting up the tiles...............
	std::vector<Tile>::const_iterator tileiter;
	std::vector<Tile> tilearray;
	Tile tile;
	sf::Vector2i grid(28 * scale, 36 * scale);

	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			fin >> val;
			cout << val;
			if (val == 1)
			{
				tile.update(j, i);
				tilearray.push_back(tile);
			}
			// loading the balls as 0 rebresent it
			if (((i >= 4 && i < 12) || (i >= 5 && i < 33 && (j == 6 || j == 21)) || (i >= 20 && i < 34))
				&& (val == 0) && (dotindex <dotsnumber))
			{
				dots.setposition(j * 24 , i * 24 );
				dots.sprite1.setTexture(dotstex);
				dots.sprite1.setTextureRect(dotsrec);
				dots.setlargedot(false);
				dotsarray.push_back(dots);
				dotsnumber++;
			}
			if (val == 3)
			{
				dots.setposition(j * 24 , i * 24 );
				dots.sprite1.setTexture(largedottex);
				dots.sprite1.setTextureRect(dotsrec);
				dots.setlargedot(true);
				dotsarray.push_back(dots);
				dotsnumber++;
			}
			if (val == 4)
			{
				dots.setposition(j * 24, i * 24);
				dots.sprite1.setTexture(fruittex);
				dots.sprite1.setTextureRect(dotsrec);
				dots.setlargedot(false);
				dotsarray.push_back(dots);
				dotsnumber++;
			}

		}
	}
	
	
	//...................................


	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}
		if (lives <= 0)
		{
			sf::RenderWindow window2(sf::VideoMode(224 * scale, 288 * scale), "GAME_OVER");
			while (window2.isOpen())
			{
				window.close();

				while (window2.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window2.close();
					gameOver.drawgameover(window2);
					window2.display();
					gameovr.play();


				}
			}
		}
		if (dotscounter <= 0)
		{
			sf::RenderWindow window3(sf::VideoMode(224 * scale, 288 * scale), "YOU_WIN");
			while (window3.isOpen())
			{
				window.close();

				while (window3.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window3.close();
					won.iswin (window3);
					window3.display();
					wn.play();


				}
			}
		}
		window.clear();
		window.draw(mapsprite);

		
		
		
		counter1 = 0; counter2 = 0;
		if (spacec.getElapsedTime().asSeconds() >0.2) {
			spacec.restart();
			if (pclock.getElapsedTime().asSeconds() > 4)
			{
				for (ghostsiter = ghostsarray.begin(); ghostsiter != ghostsarray.end(); ghostsiter++) {
					projectile1.rect1.setPosition(ghostsarray[counter1].rect1.getPosition());
					if (projectile1.direction = ghostsarray[counter1].getghostdirec());
					proarray.push_back(projectile1);
					counter1++;
				}
				if (pclock.getElapsedTime().asSeconds() > 20)
				{
					pclock.restart();
					
				}
			}
		}
		counter1 = 0;
		for (proiter = proarray.begin(); proiter != proarray.end(); proiter++)
		{
			proarray[counter1].update();
			window.draw(proarray[counter1].rect1);
			window.draw(proarray[counter1].sprite1);
			counter1++;
		}
		//enemy projectile collides with player
		counter1 = 0;
		for (proiter = proarray.begin(); proiter != proarray.end(); proiter++)
		{
			if (proarray[counter1].rect1.getGlobalBounds().intersects(player.rect1.getGlobalBounds()))
			{
				score-=1;
				prointersect.play();
				proarray[counter1].destroy = true;
			}
			counter1++;
		}
		//delete projectile;
		counter1 = 0;
		for (proiter = proarray.begin(); proiter != proarray.end(); proiter++)
		{
			if (proarray[counter1].destroy == true)
			{
				proarray.erase(proiter);
				break;
			}
			counter1++;
		}
		
		//sf::Font font;
		std::ostringstream ssScore;
		ssScore << "score : " << score;
		font.loadFromFile("SNAP____.ttf");
		sf::Text labelscore;
		labelscore.setCharacterSize(40);
		labelscore.setPosition(30, 10);
		labelscore.setFont(font);
		labelscore.setString(ssScore.str());
		window.draw(labelscore);
		counter1 = 0;

		sf::Font live;
		std::ostringstream sslives;
		sslives << "Lives : " << lives;
		font.loadFromFile("SNAP____.ttf");
		sf::Text labellives;
		labellives.setCharacterSize(40);
		labellives.setPosition(420, 10);
		labellives.setFont(font);
		labellives.setString(sslives.str());
		window.draw(labellives);
		counter1 = 0;

		//.....................................
		
		player.update();
		player.updatemovement();
		// ghost functions
		for (ghostsiter = ghostsarray.begin(); ghostsiter < ghostsarray.end(); ghostsiter++)
		{
			if (outofbox < 4)
			{
				switch (outofbox)
				{
				case (0): if (boxclock.getElapsedTime().asSeconds() > 4 &&
					boxclock.getElapsedTime().asSeconds() < 4.6 &&
					!ghostsarray[outofbox].getoutofbox())
				{
					ghostsarray[outofbox].setghostdirec(2);
				}

						  else if (boxclock.getElapsedTime().asSeconds() > 4.6
							  && boxclock.getElapsedTime().asSeconds() < 4.7
							  && !isoutofbox)
						  {
							  ghostsarray[outofbox].setghostdirec(4);
							  boxclock.restart();
							  outofbox++;
						  }
						  break;
				case(1): if (boxclock.getElapsedTime().asSeconds() > 4 &&
					boxclock.getElapsedTime().asSeconds() < 4.2 &&
					!ghostsarray[outofbox].getoutofbox())
				{
					ghostsarray[outofbox].setghostdirec(2);
				}

						 else if (boxclock.getElapsedTime().asSeconds() > 4.2
							 && boxclock.getElapsedTime().asSeconds() < 4.4
							 && !isoutofbox)
						 {
							 ghostsarray[outofbox].setghostdirec(4);
							 boxclock.restart();
							 outofbox++;
						 }
						 break;

				case(2): if (boxclock.getElapsedTime().asSeconds() > 4 &&
					boxclock.getElapsedTime().asSeconds() < 4.2 &&
					!ghostsarray[outofbox].getoutofbox())
				{
					ghostsarray[outofbox].setghostdirec(3);
				}

						 else if (boxclock.getElapsedTime().asSeconds() > 4.2
							 && boxclock.getElapsedTime().asSeconds() < 4.4
							 && !isoutofbox)
						 {
							 ghostsarray[outofbox].setghostdirec(4);
							 boxclock.restart();
							 outofbox++;
						 }
						 break;
				case(3): if (boxclock.getElapsedTime().asSeconds() > 4 &&
					boxclock.getElapsedTime().asSeconds() < 4.5 &&
					!ghostsarray[outofbox].getoutofbox())
				{
					ghostsarray[outofbox].setghostdirec(3);
				}

						 else if (boxclock.getElapsedTime().asSeconds() > 4.5
							 && boxclock.getElapsedTime().asSeconds() < 4.7
							 && !isoutofbox)
						 {
							 ghostsarray[outofbox].setghostdirec(4);
							 boxclock.restart();
							 outofbox++;
						 }
						 break;
				}
			}
				
			
		}
		// detect if if pac hit a wall
		counter1 = 0;
		for (tileiter = tilearray.begin(); tileiter < tilearray.end(); tileiter++)
		{
			if (player.sprite1.getPosition().x >= 300 && player.sprite1.getPosition().x <= 360 &&
			player.sprite1.getPosition().y >= 370 && player.sprite1.getPosition().y <= 390)
			{
			if (player.getdirection() == 2)
			{
			player.rect1.move(0, -20);
			break;
			}
			}

			if (player.rect1.getGlobalBounds().intersects(tilearray[counter1].rect1.getGlobalBounds()))
			{
				
				//cout << std::endl << "Wall HIT AT: " << tilearray[counter1].rect1.getPosition().x << "," << tilearray[counter1].rect1.getPosition().y << endl;
				int currentdirection = player.getdirection();
				switch (currentdirection)
				{
				case 1: player.rect1.move(0, 10);
					break;
				case 2: player.rect1.move(0, -10);
					break;
				case 3: player.rect1.move(10, 0);
					break;
				case 4:	player.rect1.move(-10, 0);
					break;
				default:
					break;
				}
			}

			counter1++;

		}
		
		// ghange the direction of the ghost when hits a wall
		
		counter1 = 0; counter2 = 0;
		for (ghostsiter = ghostsarray.begin(); ghostsiter < ghostsarray.end(); ghostsiter++)
		{
			ghostsarray[counter1].sethitwall(false);
			ghostsarray[counter1].blockdown = false;
			ghostsarray[counter1].blockup = false;
			ghostsarray[counter1].blockleft = false;
			ghostsarray[counter1].blockright = false;

			for (tileiter = tilearray.begin(); tileiter < tilearray.end(); tileiter++)
			{
				if (ghostsarray[counter1].direct.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds()))
				{
					
					ghostsarray[counter1].sethitwall(true);

					if (ghostsarray[counter1].rect1.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds())&& ghostsarray[counter1].getoutofbox())
					{
						
						
						switch (ghostsarray[counter1].getghostsecdirec())
						{
						case 1:
							ghostsarray[counter1].rect1.move(0, -5);
							break;
						case 2:
							ghostsarray[counter1].rect1.move(-5, 0);
							break;
						case 3:
							ghostsarray[counter1].rect1.move(5, 0);
							break;
						case 4:
							ghostsarray[counter1].rect1.move(0, 5);
							break;
						default :
							break;
						}
					}
				}
				if (ghostsarray[counter1].uprect.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds()) 
					&&
					(ghostsarray[counter1].direct.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds())))
				{
					ghostsarray[counter1].blockup = true;
					ghostsarray[counter1].setoutofbox(true);
					hitwall = true;
				
				}
				if (ghostsarray[counter1].downrect.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds()) 
					&&ghostsarray[counter1].getoutofbox())
				{
					ghostsarray[counter1].blockdown = true;
					
				}
				if (ghostsarray[counter1].rightrect.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds()) 
					&& ghostsarray[counter1].getoutofbox())
				{
					ghostsarray[counter1].blockright = true;
					
				}
				if (ghostsarray[counter1].leftrect.getGlobalBounds().intersects(tilearray[counter2].rect1.getGlobalBounds()) 
					&& ghostsarray[counter1].getoutofbox())
				{
					ghostsarray[counter1].blockleft = true;
					
				} 
				ghostsarray[counter1].update();
				if (ghostsarray[counter1].getoutofbox() && ghostsarray[counter1].gethitwall())
				{
					ghostsarray[counter1].randommovement();
				}
				counter2++;
			}
			counter2 = 0;
			counter1++;
		}
		
		
		counter1 = 0;
		for (dotsiter = dotsarray.begin(); dotsiter < dotsarray.end(); dotsiter++)
		{
			if (dotsarray[counter1].getisshowing() == true)
			{
				window.draw(dotsarray[counter1].sprite1);
				dotsarray[counter1].update();
			}
			counter1++;
		}
       
		counter1 = 0;
		for (ghostsiter = ghostsarray.begin(); ghostsiter < ghostsarray.end(); ghostsiter++)
		{  
			
			ghostsarray[counter1].update();
			ghostsarray[counter1].moving();
			if (!ghostsarray[counter1].getisafraid())
			{
				window.draw(ghostsarray[counter1].sprite1);
			}
			else
			{
				window.draw(ghostsarray[counter1].sprite2);
			}
			counter1++;
		}
		

		
		 counter1 = 0;
		for (ghostsiter = ghostsarray.begin(); ghostsiter != ghostsarray.end(); ghostsiter++)
		{
			if (player.rect1.getGlobalBounds().intersects(ghostsarray[counter1].rect1.getGlobalBounds())
				)
			{
				 player.rect1.setPosition(sf::Vector2f(334, 640));
				 player.sprite1.setPosition(sf::Vector2f(334, 640));
				 lives--;
			}
			counter1++;
		}
		counter1 = 0; counter2 = 0;
		for (dotsiter = dotsarray.begin(); dotsiter < dotsarray.end(); dotsiter++)
		{
			
			if (player.rect1.getGlobalBounds().intersects(dotsarray[counter1].rect1.getGlobalBounds()))
			{
				dotsarray[counter1].setisshownig(false);
				dotsarray[counter1].rect1.setSize(sf::Vector2f(0, 0));
				eatdot.play();
				if (dotsarray[counter1].getlargedot())
				{
					for (ghostsiter = ghostsarray.begin(); ghostsiter < ghostsarray.end(); ghostsiter++)
					{
						score += 25;
						
						break;
						counter2++;
					}
					
					counter2 = 0;
				}
				
				score++;
				dotscounter--;
			}

			counter1++;
		}
		counter1 = 0;
		for (dotsiter = dotsarray.begin(); ghostsiter < ghostsarray.end(); ghostsiter++)
		{
			if (!dotsarray[counter1].getisshowing())
			{
				
				dotsarray.erase(dotsiter);
				
				
				break;
			}
			counter1++;
		}
		counter1 = 0;
		if (afraidclock.getElapsedTime().asSeconds() > 8.0)
		{
			for (ghostsiter = ghostsarray.begin(); ghostsiter != ghostsarray.end(); ghostsiter++)
			{
				ghostsarray[counter1].setisafraid(false);
				counter1++;
			}
		}
		
		window.draw(player.sprite1);
		
		window.display();
		
	}
	return 0;
}