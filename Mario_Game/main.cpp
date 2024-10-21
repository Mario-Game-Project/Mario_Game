#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

int main()
{
    /* ======================= Creating Window ====================== */
    int height = 32 * 25;
    int width = int(16.0 / 9.0 * height);

    sf::RenderWindow window(sf::VideoMode(width, height), "Mario Game", sf::Style::Close);

    // Setting icon to window title-bar :
    sf::Image icon;
    if (icon.loadFromFile("./Assets/Icon/logo-0.png")) {  // Replace "icon.png" with the path to your icon file
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }

    window.setVerticalSyncEnabled(true); // enabling vSync
    /*------------------------------------------------------------------*/

    /*========================== Loading Assets ==========================*/
    sf::Texture spriteSheet;
    spriteSheet.loadFromFile("./Assets/Characters/SpriteSheet-32x64.png");

    Player player(spriteSheet, 21 * 32);
    Enemy enemy(spriteSheet, 21 * 32);
    
    sf::Clock clock;
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.moveRight(delta); // Right
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.moveLeft(delta); // Left
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                player.jump();
        }

        player.applyGravity(delta);
        /*--------------------------------------------------------------------------*/

        /*========================== Enemy Movements ==============================*/
		enemy.update(delta);
		/*--------------------------------------------------------------------------*/

        /*========================== Drawing ==============================*/
        window.clear();

		player.draw(&window);
        enemy.draw(&window);

        window.display();
    }

    return 0;
}
