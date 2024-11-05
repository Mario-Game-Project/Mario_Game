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
	
	sf::Vector2f getStartPos();
	sf::Vector2f getEndPos();
	void draw(sf::RenderWindow* window);
};