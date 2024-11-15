#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Enemies.h"
#include "Screens.h"


// For release version , we are using WinMain() instead of main() 
// This will make the console window disappear as we have made changes in Properties>Linker>System>SubSystem to "Windows" for release only 

int static WinMain()
//int main()
{
	/* ==================================== Creating Window ==================================== */

	int winHeight = 32 * 25;
	int winWidth = int(16.0 / 9.0 * winHeight);
	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Mario Game", sf::Style::Close);

	// Setting icon to window title-bar :
	sf::Image icon;
	if (icon.loadFromFile("./Assets/Icon/logo.png")) { 
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}

	// enabling vSync
	window.setVerticalSyncEnabled(true);

	// defining clock to measure delta time
	sf::Clock deltaClock;

	// Disabling mouse cursor :

	sf::Cursor cursor;
	//cursor.loadFromSystem(sf::Cursor::Hand);
	window.setMouseCursor(cursor);

	/* ----------------------------------------------------------------------------------------- */


	/* ====================================== Characters ======================================= */

	sf::Texture spriteSheet;
	spriteSheet.loadFromFile("./Assets/Characters/SpriteSheet-32x64.png");

	// Player :
	Player player(spriteSheet, 21 * 32);
	bool isSpacePressed = false;

	// Enemies :
	Enemies enemies(&spriteSheet);

	/* ----------------------------------------------------------------------------------------- */


	/* ========================================== Map ========================================== */

	Map map(winWidth, winHeight);

	// Screens ( Pause / Game Over / Level Completed ....) :
	Screens screens(winWidth, winHeight);
	bool tabPressed = false;
	sf::Vector2i lastPosition = window.getPosition();

	/* ----------------------------------------------------------------------------------------- */


	/* ======================================= Game Loop ======================================= */

	while (window.isOpen())
	{
		// delta time : 
		float delta = deltaClock.restart().asSeconds();

		/* ----------------------------------- Window Events ----------------------------------- */
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/* ----------------------------------- Screens Logic ---------------------------------- */

		// Pause and Resume on Tab press
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && event.type != sf::Event::LostFocus)
		{
			if(!tabPressed) screens.togglePause();
			tabPressed = true;
		}
		else tabPressed = false;
		

		// Pause when lost focus
		if(event.type == sf::Event::LostFocus && !screens.isPaused) screens.togglePause();

		// Pause when window is moved
		sf::Vector2i currentPosition = window.getPosition();

		if (currentPosition != lastPosition) {
			if (!screens.isPaused) screens.togglePause();

			lastPosition = currentPosition;
		}

		// Check for game over and level completed conditions :
		screens.checkConditions(&player, map.getViewCenter());

		/* ===================================== Game Logic ===================================== */

		if (!screens.isPaused) {

			/* -------------------------------- Player Movements ------------------------------- */
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

			/* ------------------------------- Player Collisions ------------------------------- */

			// Down collision :
			{
				int res = map.checkDownCollision(player.getSprite(), player.isBig);

				if (res > -1 && !player.isDead) {
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


			// End Level Player's Animations :
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

			if (map.checkCastleDoor(player.getSprite()) && !player.reachedCastle ) player.reachedCastle = true;


			// Update player position and sprite :
			player.update(delta, isMoving);

			// Update view :
			map.mapView(player.getSprite(), delta);

			/* ------------------------------ Enemies Movements : ------------------------------ */

			enemies.winLeftBorder = map.winLeftBorder;
			enemies.winRightBorder = map.winRightBorder;

			enemies.update(&map, delta);

			/* --------------------------- Enemy-Player Collisions : --------------------------- */
			for (Enemy* enemy : enemies.enemies)
				if (!enemy->enemyDied) player.checkEnemyCollision(enemy->getSprite());

			// Death / Downgrade :
			if (!player.isDead
				&& !player.isInvisible
				&& enemies.checkPlayerCollision(player.getSprite())
				) player.enemyKilled();
		}

		/* ------------------------------------------------------------------------------------- */


		/* --------------------------------------- Draw ---------------------------------------- */

		window.clear();

		map.draw(&window, delta);
		enemies.draw(&window);
		player.draw(&window);
		screens.draw(&window);   
		
		window.display();
	}

	/* ----------------------------------------------------------------------------------------- */

	return 0;
}

