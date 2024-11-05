#include <SFML/Graphics.hpp>
#pragma once
class Floor
{
	std::vector<sf::Sprite> tiles;

public:
	Floor(sf::Texture& texture, int posTilesX, int posTilesY, int tilesN);
	int checkDownCollision(sf::Sprite* sprite);
	int checkRightCollision(sf::Sprite* sprite);
	int checkLeftCollision(sf::Sprite* sprite);
	sf::Vector2f getStartPos();
	sf::Vector2f getEndPos();
	void draw(sf::RenderWindow* window);
};

