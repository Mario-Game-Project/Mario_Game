
#include <SFML/Graphics.hpp>
#pragma once
class Brick
{
	sf::RectangleShape tile;
	sf::Sprite topLeft;
	sf::Sprite topRight;
	sf::Sprite bottomLeft;
	sf::Sprite bottomRight;

	sf::Clock clock;

	bool isBouncing;
	bool bounce;
	bool breakIt;

public:
	Brick(sf::Texture& texture, float x, float y);
	int checkRightCollision(sf::Sprite*);
	int checkLeftCollision(sf::Sprite*);
	int checkDownCollision(sf::Sprite*);
	int checkUpCollision(sf::Sprite*, bool);
	//void breakIt();	
	void draw(sf::RenderWindow* window);
};
