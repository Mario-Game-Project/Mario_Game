
#include <SFML/Graphics.hpp>
#pragma once
class Brick
{
	sf::Sprite tile;
public:
	Brick(sf::Texture& texture, float x, float y);
	int checkRightCollision(sf::Sprite*);
	int checkLeftCollision(sf::Sprite*);
	int checkDownCollision(sf::Sprite*);
	int checkUpCollision(sf::Sprite*);
	//void breakIt();	
	void draw(sf::RenderWindow* window);
};