#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
    sf::Clock clock; // Clock for animations
    sf::Sprite sprite; // Enemy sprite

    int col; // Column index for sprite sheet animation
    int row; // Row index for sprite sheet animation

    bool isMovingLeft = true; // Flag to check if enemy is moving left
    float speedX; // Horizontal Speed of the enemy
    float leftLimit; // Left boundary for the enemy movement
    float rightLimit; // Right boundary for the enemy movement

public:
	Enemy(sf::Texture& , float);
    void update(float delta);
    void draw(sf::RenderWindow* window);
};

