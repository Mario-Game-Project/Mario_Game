#include <SFML/Graphics.hpp>
#include "Floor.h"
#include "Pipe.h"
#include "Brick.h"

#pragma once
class Map
{
	sf::Texture texture;
	sf::Texture textureBg;
	sf::Sprite background;

	std::vector<Floor*> floors;
	std::vector<Pipe*> pipes;
	std::vector<Brick*> bricks;

	void renderFloor();
	void renderPipes();
	void renderBricks();

public:
	Map(float winWidth, float winHeight);
	int checkDownCollision(sf::Sprite* sprite);
	int checkLeftCollision(sf::Sprite* sprite);
	int checkRightCollision(sf::Sprite* sprite);

	int checkUpCollision(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

