#include <SFML/Graphics.hpp>
#include "Floor.h"
#include "Pipe.h"

#pragma once
class Map
{
	sf::Texture texture;
	sf::Texture textureBg;
	sf::Sprite background;

	std::vector<Floor*> floors;
	std::vector<Pipe*> pipes;

	void renderFloor();
	void renderPipes();

public:
	Map(float winWidth, float winHeight);
	int checkDownCollision(sf::Sprite* sprite);
	int checkLeftCollision(sf::Sprite* sprite);
	int checkRightCollision(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

