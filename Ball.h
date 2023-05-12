#pragma once

#include <SFML/Graphics.hpp>
#include"Player.h"
#include "Brique.h"

class Ball
{
private:
	sf::CircleShape shape;
	sf::Vector2f oldPosition;
	sf::Vector2f position;
	float speed;
	int radius;
	int lives;
	sf::Vector2f direction;
	static bool isRandInitialized;
	double randomizeAngle();
	void setAngle(double angle);
public:
	Ball(int x, int y, int radius, float speed);
	~Ball();
	void move(float ellapsedTime);
	void draw(sf::RenderWindow& window);
	float getSpeed();
	void setSpeed(float newSpeed);
	void setPosition(sf::Vector2f newPosition);
	sf::Vector2f getPosition();
	void setDirection(sf::Vector2f newDirection);

	void manageCollisionWithWindow(sf::RenderWindow& window);
	void manageCollisionWithPlayer(Player& player);
	void manageCollisionWith(Brique* Brique);


	
};

