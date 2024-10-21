#include "Enemy.h"
#include <iostream>

Enemy::Enemy(sf::Texture& texture ,float floor):
    isMovingLeft(true),
	speedX(100.0f),
	leftLimit(400.0f),
	rightLimit(800.0f),
	col(0),
    row(4)
{
    sprite.setTexture(texture);
    sprite.setPosition(rightLimit, floor);
    sprite.setTextureRect(sf::IntRect(col * 32, row * 64, 32, 64));
}

void Enemy::update(float delta)
{
    sf::Vector2f enemyPosition = sprite.getPosition();

    if (isMovingLeft) {
        enemyPosition.x -= speedX * delta;

        if (clock.getElapsedTime().asMilliseconds() > 100) {
            col = ++col % 5;
            row = 4;
            sprite.setTextureRect(sf::IntRect(col * 32, row * 64, 32, 64));
            clock.restart();
        }
        if (enemyPosition.x < leftLimit) {
            isMovingLeft = false;
            //std::cout << "Left limit reached" << std::endl;
        }
    }
    else {
        enemyPosition.x += speedX * delta;

        if (clock.getElapsedTime().asMilliseconds() > 100) {
            col = ++col % 5;
            row = 5;
            sprite.setTextureRect(sf::IntRect(col * 32, row * 64, 32, 64));
            clock.restart();
        }

        if (enemyPosition.x > rightLimit) {
            isMovingLeft = true;
			//std::cout << "Right limit reached" << std::endl;
        }
    }
    sprite.setPosition(enemyPosition);
}

void Enemy::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
