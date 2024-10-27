#include <SFML/Graphics.hpp>
#pragma once
class Stone
{
	std::vector < sf::Sprite > tiles;
public:
	Stone(sf::Texture& texture, float x, float y, float tilesN);
	int checkDownCollision(sf::Sprite*);
	int checkRightCollision(sf::Sprite*);
	int checkLeftCollision(sf::Sprite*);
	//void breakIt();	
	void draw(sf::RenderWindow* window);
};