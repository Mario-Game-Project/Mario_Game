#include <SFML/Graphics.hpp>
#pragma once
class Castle
{
	sf::Sprite castle;

public:
	Castle(sf::Texture&, float x, float y);

	sf::Vector2f getPosition();
	bool castleDoor(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

