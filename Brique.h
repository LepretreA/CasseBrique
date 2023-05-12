#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <deque>

class Brique
{
private:
	sf::Vector2f position; // Position de la brique
	sf::Vector2f size; // Taille de la brique
	sf::RectangleShape shape; // Forme de la brique
	int health; // Sant� de la brique
	float lastCollisionTime; // Temps de la derni�re collision avec la balle
	sf::Clock clock; // Horloge pour mesurer le temps �coul� depuis la derni�re collision
	void setColor(); // Changer la couleur de la brique en fonction de sa sant�
public:
	Brique(int x, int y, int width, int height, int health); // Constructeur
	~Brique(); // Destructeur
	void draw(sf::RenderWindow& window); // Dessiner la brique sur la fen�tre
	bool isAlive(); // Renvoyer true si la brique est en vie, sinon false
	void destroyAndDelete(std::deque<Brique*>& bricks); // Supprimer la brique de la m�moire et de la deque
	void hit(); // R�duire la sant� de la brique et changer sa couleur
	sf::Vector2f getPosition(); // Renvoyer la position de la brique
	sf::RectangleShape getShape(); // Renvoyer la forme de la brique
	sf::Vector2f getSize(); // Renvoyer la taille de la brique
	bool operator==(const Brique& other) const; // Comparer deux briques
};
