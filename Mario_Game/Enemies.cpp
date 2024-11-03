#include "Enemies.h"

void Enemies::checkEnemiesCollision()
{

	for (int i = 0; i < enemies.size(); i++) {
		for (int j = i+1; j < enemies.size(); j++) {
			enemies.at(i)->checkEnemiesCollision(enemies.at(j));
		}
	}
}
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
		Enemy* enemy = new Enemy(texture, 41 * 32, 21 * 32);
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
	{
		Enemy* enemy = new Enemy(texture, 80 * 32, 14 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 82 * 32, 14 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 94 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 98 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 108 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 110 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 135 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 139 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 143 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 147 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 180 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
}

void Enemies::update(Map* map, float delta)
{
	for (Enemy* enemy : enemies) {
		{
			int res = map->checkDownCollision(enemy->getSprite() , false);
			if (res > -1 && !enemy->enemyDied) {
				enemy->isGrounded = true;
				enemy->getSprite()->setPosition(enemy->getSprite()->getPosition().x, res - 64);
			}
			else {
				enemy->isGrounded = false;
			}
		}
		{
			int res = map->checkLeftCollision(enemy->getSprite(), false , false);
			if (res > -1) {
				enemy->enemyMovingRight = true;
			}
		}
		{
			int res = map->checkRightCollision(enemy->getSprite() , false);
			if (res > -1) {
				enemy->enemyMovingRight = false;
			}
		}
		enemy->update(delta);
	}
	checkEnemiesCollision();
}

bool Enemies::checkPlayerCollision(sf::Sprite* sprite)
{
	for (Enemy* enemy : enemies) {
		if(!enemy->enemyDied){
			enemy->checkCollisionWithPlayer(*sprite);
			if (enemy->enemyDied) return true;
		}
	}
	return false;
}

void Enemies::draw(sf::RenderWindow* window)
{
	for (Enemy* enemy : enemies) {
		enemy->draw(window);
	}
}
