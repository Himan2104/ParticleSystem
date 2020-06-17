#pragma once
#include<SFML/Graphics.hpp>

class Particle
{
public:
	Particle(sf::Vector2f iniPos, sf::Color hex, sf::Vector2f iniVel);
	~Particle();
	void update(float dT, bool randomColor);
	void draw(sf::RenderWindow& window);
	float getYpos();
	bool isInScope(sf::RenderWindow& window);
private:
	sf::RectangleShape body;
	sf::Vector2f vel;
};
