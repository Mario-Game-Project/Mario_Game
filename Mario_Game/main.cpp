#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Enemies.h"

int main()
{
	/* ==================================== Creating Window ==================================== */

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

	// defining clock to measure delta time
	sf::Clock deltaClock;

	/* ----------------------------------------------------------------------------------------- */


	/* ====================================== Characters ======================================= */

	sf::Texture spriteSheet;
	spriteSheet.loadFromFile("./Assets/Characters/SpriteSheet-32x64.png");

	// Player :
	Player player(spriteSheet, 21 * 32);

	// Enemies :
	Enemies enemies(&spriteSheet);

	bool isSpacePressed = false;

	/* ----------------------------------------------------------------------------------------- */


	/* ========================================== Map ========================================== */

	Map map(winWidth, winHeight);

	/* ----------------------------------------------------------------------------------------- */


	/* ======================================= Game Loop ======================================= */

	while (window.isOpen())
	{
		float delta = deltaClock.restart().asSeconds();

		/* ----------------------------------- Window Events ----------------------------------- */
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/* ---------------------------------- Player Movements --------------------------------- */
		bool isMoving = false;

		// Right Movement 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.moveRight(delta);
			isMoving = true;
		}

		// Left Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.moveLeft(delta);
			isMoving = true;
		}

		// Jump
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (!isSpacePressed) player.jump(); // only one jump per spacebar hold

			isMoving = true;
			isSpacePressed = true;
		}
		else isSpacePressed = false;

		/* --------------------------------- Player Collisions --------------------------------- */


		// Down collision :
		{
			int res = map.checkDownCollision(player.getSprite(), player.isBig);

			if (res > -1 && !player.isDied) {
				player.getSprite()->setPosition(player.getSprite()->getPosition().x, res - 64);
				player.canMoveDown = false;
			}
			else player.canMoveDown = true;

		}
		// Right collision :
		{
			int res = map.checkRightCollision(player.getSprite(), player.isBig);

			if (res > -1) {
				player.getSprite()->setPosition(res - 32, player.getSprite()->getPosition().y);
				player.canMoveRight = false;
			}
			else player.canMoveRight = true;
		}

		// Left collision :
		{
			int res = map.checkLeftCollision(player.getSprite(), player.isBig, true);

			if (res > -1) {
				player.getSprite()->setPosition(res, player.getSprite()->getPosition().y);
				player.canMoveLeft = false;
			}
			else player.canMoveLeft = true;
		}

		//Up Collision :
		{
			int res = map.checkUpCollision(player.getSprite(), player.isBig);

			if (res > -1) {
				res = player.isBig ? res - 8 : res - 24;
				player.getSprite()->setPosition(player.getSprite()->getPosition().x, res);
				player.canMoveUp = false;
			}
			else player.canMoveUp = true;
		}

		// Upgrade :
		if (map.checkPowerUp(player.getSprite())) player.Upgrade();

		// Death / Downgrade :
		if (!player.isDied && !player.isInvisible && enemies.checkPlayerCollision(player.getSprite())) player.enemyKilled();

		if (!player.touchedFlag)
		{
			int flag = map.checkEndFlag(player.getSprite());
			if (flag > -1)
			{
				player.getSprite()->setPosition(flag - 24, player.getSprite()->getPosition().y);
				player.touchedFlag = true;
			}
		}
		else isMoving = true;

		// Update player position and sprite :
		player.update(delta, isMoving);

		// Update view :
		map.mapView(player.getSprite(), delta);

		if (map.checkCastleDoor(player.getSprite())) player.reachedCastle = true;

		/* -------------------------------- Enemies Movements : -------------------------------- */
		enemies.update(&map, delta);

		for (Enemy* enemy : enemies.enemies)
			if (!enemy->enemyDied) player.checkEnemyCollision(enemy->getSprite());

		/* --------------------------------------- Draw ---------------------------------------- */
		window.clear();

		map.draw(&window, delta);
		player.draw(&window);
		enemies.draw(&window);
		window.display();
	}

	/* ----------------------------------------------------------------------------------------- */

	return 0;
}

