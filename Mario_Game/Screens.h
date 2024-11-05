#include <SFML/Graphics.hpp>
#include "Player.h"
#pragma once

class Screens
{
	std::vector<sf::Text> texts;

	sf::Font font;
	sf::RectangleShape screen;
	sf::Clock clock;

	int winCenterX;
	int winCenterY;
	bool conditionsSatisfied;

	void levelCompletedScreen();
	void gameOverScreen();

public : 
	bool isPaused;
	Screens(float windowWidth, float windowHeight);
	void checkConditions(Player* player , sf::Vector2f centerPos);

	void togglePause();
	void draw(sf::RenderWindow* window );
};

