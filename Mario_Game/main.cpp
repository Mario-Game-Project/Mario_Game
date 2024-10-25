#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

int main()
{
	/* ======================= Creating Window ====================== */
	int winHeight = 32 * 25;
	int winWidth = int(16.0 / 9.0 * winHeight);
	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Mario Game", sf::Style::Close);

	// Setting icon to window title-bar :
	sf::Image icon;
	if (icon.loadFromFile("./Assets/Icon/logo-0.png")) {  // Replace "icon.png" with the path to your icon file
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}

	// enabling vSync
	window.setVerticalSyncEnabled(true);
	/*------------------------------------------------------------------*/

	/*========================== Characters ==========================*/
	sf::Texture spriteSheet;
	spriteSheet.loadFromFile("./Assets/Characters/SpriteSheet-32x64.png");

	Player player(spriteSheet, 21 * 32);
	Enemy enemy(spriteSheet, 21 * 32);

	sf::Clock clock;
	/*-----------------------------------------------------------------*/

	//========================== Map ==============================

	Map map(winWidth, winHeight);
	/*-----------------------------------------------------------------*/

	/*========================== Game Loop =================================*/
	while (window.isOpen())
	{
		float delta = clock.restart().asSeconds();

		/*----------------------- Events loop ----------------------------------*/
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*========================== Player Movements ==============================*/
		bool isMoving = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.moveRight(delta); // Right
			isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.moveLeft(delta); // Left

			isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			player.jump();

			isMoving = true;
		}

		player.applyGravity(delta);
		/*--------------------------------------------------------------------------*/

		/*========================== Player Collisions ==============================*/
		// Down collision
		{
			int res = map.checkDownCollision(player.getSprite());

			if (res > -1) {
				player.getSprite()->setPosition(player.getSprite()->getPosition().x, res - 64);
				player.isJumping = false;
			}
		}
		
		// Right collision
		{
			int res = map.checkRightCollision(player.getSprite());
			if (res > -1) {
				player.getSprite()->setPosition(res - 32, player.getSprite()->getPosition().y);
			}
		}

		// Left collision
		{
			int res = map.checkLeftCollision(player.getSprite());
			if (res > -1) {
				player.getSprite()->setPosition(res, player.getSprite()->getPosition().y);
			}
		}

		player.update(delta , isMoving);
		/*--------------------------------------------------------------------------*/

		/*========================== Enemy Movements ==============================*/
		enemy.update(delta);
		/*--------------------------------------------------------------------------*/

		/*========================== Drawing ==============================*/
		window.clear();

		map.draw(&window);
		player.draw(&window);
		enemy.draw(&window);

		window.display();
	}

	return 0;
}
