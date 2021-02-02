#include"pch.h"
#include<iostream> 
#include<SFML/Graphics.hpp>
#include"Particle.hpp"
#include"Definitions.hpp"

int main()
{
	sf::RenderWindow window(currentVideoMode, "ParticleSystem", sf::Style::None | sf::Style::Close);
	window.setFramerateLimit(frameRateLimit);

	std::vector<Particle*> particles;

	sf::Vector2f iniVel;
	sf::Vector2f mousePos;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/consola.ttf");
	sf::Text stats;
	stats.setFont(font);
	stats.setPosition(10.0f, 10.0f);
	stats.setCharacterSize(10);
	sf::Text ctrls(stats);
	ctrls.setPosition(10.0f, currentVideoMode.height - 35.0f);
	ctrls.setString("[Q]Change Animation Factor\t[X]Toggle Color Randomization\t[Space]Destroy all Particles\n[C]Toggle Controls Visibility\t[S]Toggle Stats Visibility");
	
	srand(time(NULL));

	int velx, vely;

	float animFac = 1.0f;

	sf::Clock fclk, gclk;

	bool randCol = false;

	float frameTime = 0.0f;

	bool vis_C = true, vis_S = true;

	gclk.restart().asMilliseconds();

	while (window.isOpen())
	{
		frameTime = fclk.restart().asSeconds();
		mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					for (auto& value : particles) delete value;
					particles.clear();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				{
					std::cout << "Enter new Animation Factor (0.0f-1.0f) : ";
					std::cin >> animFac;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) randCol = !randCol;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) vis_S = !vis_S;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) vis_C = !vis_C;
			}	
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			if (gclk.getElapsedTime().asMilliseconds() > particleGenerationTimer)
				for (int i = 0; i < particleDensity; i++)
				{
					velx = (rand() % initialVelocityFactor) - (initialVelocityFactor / 2);
					vely = (rand() % initialVelocityFactor) - (initialVelocityFactor / 2);
					iniVel = sf::Vector2f(velx, vely);
					particles.push_back(new Particle(mousePos, BaseParticleColor, iniVel));
					gclk.restart().asMilliseconds();
				}
		
		for (int i = 0; i < particles.size(); i++)
		{
			particles[i]->update(animFac, randCol);
			if (!particles[i]->isInScope(window))
			{
				delete particles[i];
				particles.erase(particles.begin() + i);
			}
		}
		
		stats.setString("FPS : " + std::to_string(1.0f/frameTime) 
			+ "\nParticles : " + std::to_string(particles.size()) 
			+ "\nAnimation Factor : " + std::to_string(animFac) 
			+ "\nParticle Density : " + std::to_string(particleDensity)
			+ "\nColor Randomization : " + (randCol ? "On" : "Off"));

		window.clear();
		for (int i = 0; i < particles.size(); i++) particles[i]->draw(window);
		if(vis_S) window.draw(stats);
		if(vis_C) window.draw(ctrls);
		window.display();
	}

	
	return 0;
}
