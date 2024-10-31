#include <SFML/Graphics.hpp>
#pragma once
class Castle
{
	sf::Sprite castle;

public:
	Castle(sf::Texture&, float x, float y);
	sf::Sprite* getSprite();
	bool castleDoor(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

