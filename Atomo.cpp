#include "Atomo.hpp"

#define PI 3.14159265359

//ELETRON
Eletron::Eletron()
{
	texture.loadFromFile(eletronsTexture);

	particle.setFillColor(sf::Color::White);
	particle.setRadius(18);
	particle.setTexture(&texture);

	origin.x = 800;
	origin.y = 500;
	angle = 0;
	radiusOrbit = 250;
	speed = 1;
}


Eletron::Eletron(float x, float y, float radiusOrbit)
{	
	texture.loadFromFile(eletronsTexture);

	particle.setFillColor(sf::Color::White);
	particle.setRadius(10);
	particle.setTexture(&texture);
	
	angle = 0;
	this->radiusOrbit = radiusOrbit;
	this->origin.x = x;
	this->origin.y = y;
}

void Eletron::draw(sf::RenderWindow &wind)
{
	particle.setPosition(pos);
	wind.draw(particle);
}

void Eletron::updatePosition()
{
	pos.x = (cos(angle * PI / 180) * radiusOrbit) + origin.x;    //Transformando em radiano e somando às coordenadas do centro da tela
	pos.y = (sin(angle * PI / 180) * radiusOrbit) + origin.y;	 //Transformando em radiano e somando às coordenadas do centro da tela

	angle += speed;												 //Incrementando o ângulo, para rotacionar a posição do eletron
}


//NUCLEO
Nucleo::Nucleo(float x, float y)
{

	this->origin.x = x / 2;
	this->origin.y = y / 2;

	particle.setFillColor(sf::Color::White);
	particle.setRadius(40);
	particle.setPosition(origin);

	texture.loadFromFile(nucleoTexture);
	particle.setTexture(&texture);

}

void Nucleo::draw(sf::RenderWindow& wind)
{
	wind.draw(particle);
}

sf::Vector2f Nucleo::getPosition()
{
	return origin;
}