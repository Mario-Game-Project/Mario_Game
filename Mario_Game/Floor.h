#include <SFML/Graphics.hpp>
#pragma once
class Floor
{
	std::vector<sf::Sprite> tiles;

public:
	Floor(sf::Texture& texture, int posTilesX, int posTilesY, int tilesN);
	int checkDownCollision(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

