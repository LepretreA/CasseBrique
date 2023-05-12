#include "Ball.h"
#include <SFML/Graphics.hpp>

bool Ball::isRandInitialized = false;
/*
bool intersects(const sf::CircleShape &c, const sf::RectangleShape &r) {
	sf::FloatRect fr = r.getGlobalBounds();
	sf::Vector2f topLeft(fr.left, fr.top);
	sf::Vector2f topRight(fr.left + fr.width, fr.top);
	sf::Vector2f botLeft(fr.left, fr.top + fr.height);
	sf::Vector2f botRight(fr.left + fr.width, fr.top + fr.height);

	return contains(c, topLeft) ||
		contains(c, topRight) ||
		contains(c, botLeft) ||
		contains(c, botRight);
}

bool contains(const sf::CircleShape &c, const sf::Vector2f &p) {
	sf::Vector2f center = c.getPosition();
	float a = (p.x - center.x);
	float b = (p.y - center.y);
	a *= a;
	b *= b;
	float r = c.getRadius() * c.getRadius();

	return ((a + b) < r);
}
*/
double Ball::randomizeAngle()
{
	if (!isRandInitialized)
	{
		srand(time(NULL));
		isRandInitialized = true;
	}

	return (((double)rand() / (double)RAND_MAX) * 60.0) - 30.0;
}

void Ball::setAngle(double angle)
{
	direction.x = sin(angle);
	direction.y = -cos(angle);
}

Ball::Ball(int x, int y, int radius, float speed)
{
	position.x = x;
	position.y = y;
	oldPosition = position;
	shape.setFillColor(sf::Color(sf::Color::White));
	shape.setPosition(position);
	this->radius = radius;
	shape.setRadius(radius);
	this->speed = speed;
	
	setAngle(randomizeAngle());
}

Ball::~Ball()
{
}

void Ball::move(float ellapsedTime)
{
	oldPosition = position;
	position += ellapsedTime * speed * direction;
	shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow & window)
{
	
	window.draw(shape);
}

float Ball::getSpeed()
{
	return speed;
}

void Ball::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

void Ball::setPosition(sf::Vector2f newPosition)
{
	position = newPosition;
	oldPosition = position;
}

sf::Vector2f Ball::getPosition()
{
	return position;
}

void Ball::setDirection(sf::Vector2f newDirection)
{
	direction = newDirection;
}

void Ball::manageCollisionWithWindow(sf::RenderWindow & window)
{
	// Si la balle sort de l'écran (par en haut)
	if (position.y <= 0)
	{
		// Inverse la direction sur l'axe y :
		direction.y *= -1;
		position.y = 0;
	}
	else if (position.y + 2 * radius >= window.getSize().y)
	{
		direction.y *= -1;
		position.y = window.getSize().y - 2 * radius;
	}

	if (position.x <= 0)
	{
		direction.x *= -1;
		position.x = 0;
	}
	else if (position.x + 2 * radius >= window.getSize().x)
	{
		direction.x *= -1;
		position.x = window.getSize().x - 2 * radius;
	}
}

void Ball::manageCollisionWithPlayer(Player & player)
{

	sf::FloatRect ballBounds = shape.getGlobalBounds();
	sf::FloatRect platformBounds = player.getShape().getGlobalBounds();

	

	// Vérifie si la balle touche la plateforme
	if (ballBounds.intersects(platformBounds))
	{
		// Calcule la position relative de la balle par rapport à la plateforme
		double x = player.getPosition().x;
		double sizeX = player.getSize().x;

		double relativeIntersectX = position.x + radius - player.getPosition().x;

		// Normalise la position relative de la balle
		double normalizedRelativeIntersectionX = relativeIntersectX / (sizeX / 2.0);

		// Calcule l'angle de rebond de la balle
		double angle = normalizedRelativeIntersectionX;

		// Change la direction de la balle en fonction de l'angle de rebond
		setAngle(angle);

		// Déplace la balle en dehors de la plateforme
		position.y = player.getPosition().y - (2 * radius) - 10.0f;
		direction.y = -std::abs(direction.y);
	}
}
void Ball::manageCollisionWith(Brique * Brique)
{
	sf::FloatRect ballBounds = shape.getGlobalBounds();
	sf::FloatRect BriqueBounds = Brique->getShape().getGlobalBounds();
	// Vérifie si la balle touche la brique
	if (ballBounds.intersects(BriqueBounds))
	{
		// Calcule la position relative de la balle par rapport à la brique
		double intersectX = position.x + radius - Brique->getPosition().x;
		double intersectY = position.y + radius - Brique->getPosition().y;
		double deltaX = Brique->getSize().x / 2.0 - std::abs(intersectX);
		double deltaY = Brique->getSize().y / 2.0 - std::abs(intersectY);

		// Inverse la direction de la balle en fonction de l'axe de la collision
		if (deltaX > deltaY)
		{
			// Collision horizontale
			direction.x *= -1;
		}
		else
		{
			// Collision verticale
			direction.y *= -1;
		}

		// Réduit la santé de la brique et change sa couleur
		Brique->hit();

		// Changer la direction de la balle immédiatement après la collision
		// en fonction de la position de la brique relative à la balle
		if (intersectX > 0)
		{
			// La balle touche la brique sur le côté droit
			direction.x = std::abs(direction.x);
		}
		else
		{
			// La balle touche la brique sur le côté gauche
			direction.x = -std::abs(direction.x);
		}

		if (intersectY > 0)
		{
			// La balle touche la brique en bas
			direction.y = std::abs(direction.y);
		}
		else
		{
			// La balle touche la brique en haut
			direction.y = -std::abs(direction.y);
		}
	}

}
//je suis juif et adopter aidezr moi 

/*if (shape.getGlobalBounds().intersects(player.getGlobalBounds()))
{
	// Inversion de la direction verticale de la balle en cas de collision
	direction.y *= -1;
}

sf::FloatRect ball(getPosition().x, getPosition().y, 2 * radius, 2 * radius);

ball.setFillColor(sf::Color::Red);
sf::FloatRect playerRect(player.getPosition().x, player.getPosition().y, player.getSize().x, player.getSize().y);
playerRect.setFillColor(sf::Color::Cyan);


if (ball.intersects(playerRect))
{
	// Gestion de la collision ...
	direction.y *= -1;
}


//if (position.y >= player.getPosition().y)
{
	//if(position.x <= player.getPosition().x + player.getSize().x && position.x >= player.getPosition().x)
	{

	}
}*/