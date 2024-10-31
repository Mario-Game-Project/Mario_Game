#include <SFML/Graphics.hpp>
#pragma once

class Flag
{
	std::vector<sf::Sprite> pole;
	sf::Sprite flag;
	bool poleCollided;

public:
	Flag(sf::Texture&, float tileX, float tileY , int height);
	int checkPoleCollision(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window , float delta);
};

