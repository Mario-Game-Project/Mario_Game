#include <iostream>
#include<SFML/Graphics.hpp>
#include "Enemy.h"
#include "Map.h"
#pragma once
class Enemies
{
	std::vector<Enemy*> enemies;

public:
	Enemies(sf::Texture* texture);
	void update(Map* map , float delta);

	void checkDeath(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

