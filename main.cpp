

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Brique.h"
#include <deque>

double mapValue(double value, double min, double max, double nMin, double nMax)
{
	// Y = (X-A)/(B-A) * (D-C) + C
	double newVal = (((value - min) / (max - min)) * (nMax - nMin)) + nMin;
	return newVal;
}

int main(int argc, char **argv)
{

	std::deque<Brique*> Briques;

	// Ajout des Briques
	const int BRICK_WIDTH = 50;
	const int BRICK_HEIGHT = 20;
	const int BRICK_MARGIN = 10;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 15; j++) {
			int x = j * (BRICK_WIDTH + BRICK_MARGIN) + BRICK_MARGIN;
			int y = i * (BRICK_HEIGHT + BRICK_MARGIN) + BRICK_MARGIN;
			Briques.push_back(new Brique(x, y, BRICK_WIDTH, BRICK_HEIGHT, 2));
		}
	}

		sf::RenderWindow window(sf::VideoMode(920, 600), "My window");
		Ball ball(460, 500, 10, 500);//coordonné X,coordonné Y, radius, speed
		Player player(window.getSize().y - 40, 70, 20);
		Brique Brique(25, 50, 50, 20, 2);


		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(100, 50));
		rectangle.setFillColor(sf::Color::Cyan);
		rectangle.setOutlineColor(sf::Color::Magenta);
		rectangle.setOutlineThickness(2);
		rectangle.setPosition(100, 100);

		sf::CircleShape circle;
		circle.setRadius(10);
		circle.setPosition(200, 170);
		circle.setFillColor(sf::Color::Red);
		circle.setOutlineColor(sf::Color::Green);
		circle.setOutlineThickness(2);

		sf::RectangleShape rdr2;
		rdr2.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

		sf::Clock clock;
		sf::Vector3f xFactor(10, 20, 30);
		float ellapsedTime = 0;



		// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
		while (window.isOpen())
		{
			ellapsedTime = clock.restart().asSeconds();
			// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
			sf::Event event;
			while (window.pollEvent(event))
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
				if (event.type == sf::Event::Closed)
					window.close();


			}

			ball.manageCollisionWithPlayer(player);
			ball.move(ellapsedTime);
			ball.manageCollisionWithWindow(window);
			for (int i = 0; i < Briques.size(); i++)
			{
				if (Briques[i]->isAlive())
				{
					Briques[i]->draw(window);
					ball.manageCollisionWith(Briques[i]);
				}
				else
				{
					Briques[i]->destroyAndDelete(Briques);
				}
			}



			window.clear();

			// Dessin des Briques
			for (int i = 0; i < Briques.size(); i++) {
				Briques[i]->draw(window);
			}

			//for (int i = 0; i < window.getSize().y; i++)
			//{
			double mappedValue = mapValue(ball.getPosition().x, 0, window.getSize().x, 0, 255);
			double mappedValue2 = mapValue(ball.getPosition().y, 0, window.getSize().y, 0, 255);
			double mappedValue3 = (mappedValue + mappedValue2) / 2.0;
			rdr2.setFillColor(sf::Color(mappedValue, 255 - mappedValue2, mappedValue3));

			//}

			//rdr2.setPosition(0, 0);
			//window.draw(rdr2);
			player.draw(window);
			ball.draw(window);
			for (auto& Brique : Briques) {
				Brique->draw(window);
			}

			//window.draw(rectangle);
			//window.draw(circle);

			window.display();
		}

		for (int i = 0; i < Briques.size(); i++) {
			delete Briques[i];
		}
		Briques.clear();

		return 0;
	}
