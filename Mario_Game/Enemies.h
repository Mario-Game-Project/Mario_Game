#include <iostream>
#include<SFML/Graphics.hpp>
#include "Enemy.h"
#include "Map.h"
#pragma once
class Enemies
{
public:
	std::vector<Enemy*> enemies;
	Enemies(sf::Texture* texture);
	void update(Map* map , float delta);

	bool checkPlayerCollision(sf::Sprite* sprite);
	void draw(sf::RenderWindow* window);
};

