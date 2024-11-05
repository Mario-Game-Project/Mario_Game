#include "Enemies.h"

Enemies::Enemies(sf::Texture* texture)
{
	{
		Enemy* enemy = new Enemy(texture, 17 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 25 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 28 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 32 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 37 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 41 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 47 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 49 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 59 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 78 * 32, 13 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 80 * 32, 13 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 98 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 100 * 32, 21 * 32);
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
		Enemy* enemy = new Enemy(texture, 115 * 32, 21 * 32);
		enemies.push_back(enemy);
	}
	{
		Enemy* enemy = new Enemy(texture, 120 * 32, 21 * 32);
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
		Enemy* enemy = new Enemy(texture, 167 * 32, 10 * 32);
		enemies.push_back(enemy);
	}
}

void Enemies::update(Map* map, float delta)
{
	for (Enemy* enemy : enemies) {

		int enemyLeft = enemy->getStartPos().x;
		int enemyRight = enemy->getEndPos().x;

		if (enemyLeft < winRightBorder && enemyRight > winLeftBorder) {
			{
				int res = map->checkDownCollision(enemy->getSprite(), false);
				if (res > -1 && !enemy->enemyDied) {
					enemy->isGrounded = true;
					enemy->getSprite()->setPosition(enemy->getSprite()->getPosition().x, res - 64);
				}
				else {
					enemy->isGrounded = false;
				}
			}
			{
				int res = map->checkLeftCollision(enemy->getSprite(), false, false);
				if (res > -1 && !enemy->enemyDied) {
					enemy->enemyMovingRight = true;
				}
			}
			{
				int res = map->checkRightCollision(enemy->getSprite(), false);
				if (res > -1 && !enemy->enemyDied) {
					enemy->enemyMovingRight = false;
				}
			}
			enemy->update(delta);
		}
		else if (enemyLeft > winRightBorder) break;
	}

	for (int i = 0; i < enemies.size(); i++) {

		Enemy* enemy = enemies.at(i);

		int enemyLeft = enemy->getStartPos().x;
		int enemyRight = enemy->getEndPos().x;

		if (enemyLeft < winRightBorder && enemyRight > winLeftBorder && !enemy->enemyDied) {

			for (int j = i + 1; j < enemies.size(); j++) {
				Enemy* enemy2 = enemies.at(j);
				if(!enemy2->enemyDied) enemy->checkEnemiesCollision(enemy2);				
			}

		}
		else if (enemyLeft > winRightBorder) break;
	}

}

bool Enemies::checkPlayerCollision(sf::Sprite* sprite)
{
	for (Enemy* enemy : enemies) {

		int enemyLeft = enemy->getStartPos().x;
		int enemyRight = enemy->getEndPos().x;
		if (enemyLeft < winRightBorder && enemyRight > winLeftBorder) {

			if (!enemy->enemyDied) {
				enemy->checkCollisionWithPlayer(*sprite);
				if (enemy->enemyDied) return true;
			}
		}
		else if (enemyLeft > winRightBorder) break;
	}
	return false;
}

void Enemies::draw(sf::RenderWindow* window)
{
	for (Enemy* enemy : enemies) {
		int enemyLeft = enemy->getStartPos().x;
		int enemyRight = enemy->getEndPos().x;
		if (enemyLeft < winRightBorder && enemyRight > winLeftBorder) enemy->draw(window);
		else if (enemyLeft > winRightBorder) break;
	}
}
