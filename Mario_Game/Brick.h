
#include <SFML/Graphics.hpp>
#pragma once
class Brick
{
	sf::RectangleShape tile;
	sf::Sprite topLeft;
	sf::Sprite topRight;
	sf::Sprite bottomLeft;
	sf::Sprite bottomRight;

	sf::Clock clock;

	bool isBouncing;
	bool bounce;
	bool breakIt;

	void breakBounce();

public:
	bool isBig;
	Brick(sf::Texture& texture, float x, float y);
	int checkRightCollision(sf::Sprite* sprite , bool isBig);
	int checkLeftCollision(sf::Sprite* sprite, bool isBig);
	int checkDownCollision(sf::Sprite* sprite, bool isBig);
	int checkUpCollision(sf::Sprite* sprite, bool isBig);
	
	sf::Vector2f getStartPos();
	sf::Vector2f getEndPos();
	void draw(sf::RenderWindow* window);
};
