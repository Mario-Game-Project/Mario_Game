#include "Screens.h"

void Screens::levelCompletedScreen()
{
	sf::Text text;

	text.setFont(font);
	text.setString("Level Completed!");
	text.setCharacterSize(100);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);

	// Shadow
	text.setPosition(winCenterX + 6, winCenterY + 8);
	text.setFillColor(sf::Color::Black);
	texts.push_back(text);

	// Text
	text.setPosition(winCenterX, winCenterY);
	text.setFillColor(sf::Color(50, 222, 132));
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
	texts.push_back(text);

	screen.setFillColor(sf::Color(0, 0, 0, 170));
	screen.setOrigin(screen.getLocalBounds().width / 2, screen.getLocalBounds().height / 2);
	screen.setPosition(winCenterX, winCenterY);
}

void Screens::gameOverScreen()
{
	sf::Text text;

	text.setFont(font);
	text.setString("Game Over!");
	text.setCharacterSize(100);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);

	// Shadow
	text.setPosition(winCenterX + 6, winCenterY + 8);
	text.setFillColor(sf::Color::Black);
	texts.push_back(text);

	// Text
	text.setPosition(winCenterX, winCenterY);
	text.setFillColor(sf::Color(196, 30, 58));
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
	texts.push_back(text);

	screen.setFillColor(sf::Color(0, 0, 0, 170));
	screen.setOrigin(screen.getLocalBounds().width / 2, screen.getLocalBounds().height / 2);
	screen.setPosition(winCenterX, winCenterY);
}

Screens::Screens(float windowWidth, float windowHeight) :
	conditionsSatisfied(false),
	isPaused(false),
	winCenterX(windowWidth / 2),
	winCenterY(windowHeight / 2)
{
	font.loadFromFile("./Assets/Fonts/SuperMario256.ttf");
	screen = sf::RectangleShape(sf::Vector2f(windowWidth, windowHeight));
	screen.setFillColor(sf::Color(0, 0, 0, 0));
}

void Screens::checkConditions(Player* player, sf::Vector2f centerPos)
{
	winCenterX = centerPos.x;
	winCenterY = centerPos.y;

	if (!conditionsSatisfied && !isPaused) // only render a screen once , bcause if already rendered , then it will keep adding text to vector and render multiple layers
	{
		if (player->reachedCastle)
		{
			if (clock.getElapsedTime().asMilliseconds() >= 500)
			{
				conditionsSatisfied = true;
				levelCompletedScreen();
			}
		}
		else clock.restart();

		if (player->getSprite()->getPosition().y > winCenterY * 4)
		{
			conditionsSatisfied = true;
			gameOverScreen();
		}
	}
	isPaused = isPaused || conditionsSatisfied;
}

void Screens::togglePause()
{
	if (conditionsSatisfied)  return;

	isPaused = !isPaused;

	if (isPaused) {
		sf::Text text;

		text.setFont(font);
		text.setString("Press Tab to Resume");
		text.setCharacterSize(81);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);

		// Shadow
		text.setPosition(winCenterX + 6, winCenterY + 8);
		text.setFillColor(sf::Color::Black);
		texts.push_back(text);

		// Text
		text.setPosition(winCenterX, winCenterY);
		text.setFillColor(sf::Color(111, 0, 255));
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(3);
		texts.push_back(text);

		screen.setFillColor(sf::Color(0, 0, 0, 170));
		screen.setOrigin(screen.getLocalBounds().width / 2, screen.getLocalBounds().height / 2);
		screen.setPosition(winCenterX, winCenterY);
	}
	else {
		screen.setFillColor(sf::Color(0, 0, 0, 0));
		texts.clear();
	}
}

void Screens::draw(sf::RenderWindow* window)
{
	window->draw(screen);
	for (sf::Text text : texts)	window->draw(text);
}
