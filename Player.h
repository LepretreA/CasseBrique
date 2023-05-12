#pragma once

#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::RectangleShape Shape;
	sf::Vector2f Position;
	sf::Vector2f Size;
	int y;
public:
	Player(int y, int width, int height);
	~Player();
	
	void draw(sf::RenderWindow& window);
	
	sf::RectangleShape getShape();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();



	
};