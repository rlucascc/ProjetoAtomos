#ifndef ATOMO_H
#define	ATOMO_H

#include <SFML/Graphics.hpp>
#include "Texturas.hpp"

//ELETRON
class Eletron
{
	public:
	sf::CircleShape particle;
	sf::Vector2f pos;
	sf::Vector2f origin;
	sf::Texture texture;
	float radiusOrbit;
	float angle;
	float speed;

public:
	Eletron();
	
	Eletron(float x, float y, float radiusOrbit);

	void draw(sf::RenderWindow& wind);

	void updatePosition();
};


//NUCLEO
class Nucleo
{
public:
	sf::CircleShape particle;
	sf::Vector2f origin;
	sf::Texture texture;

public:
	Nucleo(float x, float y);

	void draw(sf::RenderWindow& wind);
	
	sf::Vector2f getPosition();
};

#endif