#include"pch.h"
#include"Particle.hpp"
#include"Definitions.hpp"

Particle::Particle(sf::Vector2f iniPos, sf::Color color, sf::Vector2f iniVel)
{
	body.setSize(particle_size);
	body.setPosition(iniPos);
	body.setFillColor(color);
	vel = iniVel;
}

Particle::~Particle()
{
}

void Particle::update(float dT, bool randomColor = false)
{
	if (vel.x > 0) vel.x -= retardation * dT;
	else if (vel.x < 0) vel.x += retardation * dT;
	vel.y += gravity * dT;
	body.move(vel.x * dT, vel.y * dT);
	if(randomColor) body.setFillColor(randomColorGen());
}

void Particle::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

float Particle::getYpos()
{
	return body.getPosition().y;
}

bool Particle::isInScope(sf::RenderWindow& window)
{
	if (body.getPosition().y > window.getSize().y) return false;
	else if (body.getPosition().x < 0.0f || body.getPosition().x > window.getSize().x) return false;
	else return true;
}
