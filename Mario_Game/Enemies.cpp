#include "Enemies.h"

Enemies::Enemies(sf::Texture* texture)
{
	{
		Enemy* enemy = new Enemy(texture,17 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture,30 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture,32 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture,37 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture,47 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture,49 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
}

void Enemies::update(Map* map, float delta)
{
	for (Enemy* enemy : enemies) {
		{
			int res = map->checkDownCollision(enemy->getSprite());
			if (res > -1 && !enemy->enemyDied) {
				enemy->isGrounded = true;
				enemy->getSprite()->setPosition(enemy->getSprite()->getPosition().x, res - 64);
			}
			else {
				enemy->isGrounded = false;
			}
		}
		{
			int res = map->checkLeftCollision(enemy->getSprite(), false);
			if (res > -1) {
				enemy->enemyMovingRight = true;
			}
		}
		{
			int res = map->checkRightCollision(enemy->getSprite());
			if (res > -1) {
				enemy->enemyMovingRight = false;
			}
		}
		enemy->update(delta);
	}
}

void Enemies::checkDeath(sf::Sprite* sprite)
{
	for (Enemy* enemy : enemies) {
		enemy->checkCollisionWithPlayer(*sprite);
	}
}

void Enemies::draw(sf::RenderWindow* window)
{
	for (Enemy* enemy : enemies) {
		enemy->draw(window);
	}
}
