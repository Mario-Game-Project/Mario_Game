#include <SFML/Graphics.hpp>
#pragma once
class Pipe
{
	std::vector<sf::Sprite > tiles;
public:
	Pipe(sf::Texture& texture, int pipeHeight, float posTileX, float posTileY);
	void draw(sf::RenderWindow* window);

	int checkRightCollision(sf::Sprite* sprite);

	int checkLeftCollision(sf::Sprite* sprite);

	sf::Vector2f getStartPos();
	sf::Vector2f getEndPos();
	int checkDownCollision(sf::Sprite* sprite);
};
