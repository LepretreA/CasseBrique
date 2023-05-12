#include "Brique.h"

void Brique::setColor()
{
	this->shape.setOutlineColor(sf::Color::White); // Blanc
	this->shape.setOutlineThickness(1); // Largeur de 1 pixel pour le contour
	if (this->health == 2)
	{
		// Si la santé est de 2, changer la couleur à orange
		this->shape.setFillColor(sf::Color(255, 165, 0)); // Orange
	}
	else if (this->health == 1)
	{
		// Si la santé est de 1, changer la couleur à rouge
		this->shape.setFillColor(sf::Color::Red); // Rouge
	}
}

Brique::Brique(int x, int y, int width, int height, int health)
{
	// Initialisation des membres de la classe
	this->position = sf::Vector2f(x, y);
	this->size = sf::Vector2f(width, height);
	this->shape = sf::RectangleShape(size);
	this->health = health;
	shape.setFillColor(sf::Color::Green); // Couleur initiale est vert
	this->shape.setOutlineColor(sf::Color::White); // Blanc
	this->shape.setOutlineThickness(1); // Largeur de 1 pixel pour le contour
	this->lastCollisionTime = 0; // Initialisation du temps de la dernière collision à zéro
}

Brique::~Brique()
{
}

void Brique::draw(sf::RenderWindow & window)
{
	if (isAlive())
	{
		// Si la brique est encore en vie, dessiner la forme sur la fenêtre donnée
		shape.setPosition(position);
		window.draw(shape);
	}
}

bool Brique::isAlive()
{
	//indique si la brique est a une vie supérieur a 0 (pour savoir si on l'affiche)
	return health > 0;
}

void Brique::destroyAndDelete(std::deque<Brique*>& Briques)
{
	// Retirer la brique de la deque de briques
	Briques.erase(std::remove(Briques.begin(), Briques.end(), this), Briques.end());
	// Supprimer l'objet de la mémoire
	delete this;
}

void Brique::hit()
{
	if (isAlive())
	{
		// Si la brique est encore en vie et si le temps depuis la dernière collision est supérieur ou égal à une seconde,
		// réduire sa santé, changer sa couleur et mettre à jour le temps de la dernière collision
		if (clock.getElapsedTime().asSeconds() - lastCollisionTime >= 0.1) {
			health--;
			setColor();
			lastCollisionTime = clock.getElapsedTime().asSeconds();
		}
	}
}

sf::Vector2f Brique::getPosition()
{
	return position;
}

sf::RectangleShape Brique::getShape()
{
	return shape;
}

sf::Vector2f Brique::getSize()
{
	return size;
}

bool Brique::operator==(const Brique & other) const
{
	return this == &other;
}
