#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(int y, int width, int height)
{
	this->y = y;
	this->Size.x = width;
	this->Size.y = height;

	Shape.setFillColor(sf::Color(sf::Color::White));
	Shape.setSize(sf::Vector2f(Size.x, Size.y));
	Shape.setOrigin(Shape.getSize().x / 2.f, Shape.getSize().y / 2.f); // Origine au centre de la barre
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow & window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	Shape.setPosition(static_cast<float>(mousePosition.x), y);
	Position.x = mousePosition.x;
	Position.y = y;
	//shape.setPosition(window.getSize().x / 2.f, window.getSize().y - 50.f); // Position y fixe à 50 pixels du bord inférieur


	//shape.setPosition(window.getPosition().x, this->y);
	window.draw(Shape);
}

sf::RectangleShape Player::getShape()
{
	return Shape;
}

sf::Vector2f Player::getPosition()
{
	return Position;
}

sf::Vector2f Player::getSize()
{
	return Size;
}


