#pragma once
#include<SFML/Graphics.hpp>

constexpr auto RESOLUTION_X = 1280; //Screen Width
constexpr auto RESOLUTION_Y = 720; //Screen Height
constexpr auto COLORDEPTH = 32; //bits per pixel

const sf::Vector2f particle_size = sf::Vector2f(1.0f, 1.0f); //size of each particle in pixels (shape is rectangle)
const float retardation = 1.0f; //kinetic retardation due to air resistance
const float gravity = 1.0f; //gravitaitonal acceleration
const unsigned int initialVelocityFactor = 100u; //upper limit of magnitude of initial velocity
const unsigned int frameRateLimit = 90u; //frame rate cap
const sf::VideoMode currentVideoMode = sf::VideoMode(RESOLUTION_X, RESOLUTION_Y, COLORDEPTH); //Video Mode
const unsigned int particleDensity = 50u; //Density of particles
const float particleGenerationTimer = 1.0f; //Clock to control generation of particles
const sf::Color BaseParticleColor(255u, 0u, 255u); //base particle color

inline sf::Color randomColorGen() { return sf::Color(rand() % 255, rand() % 255, rand() % 255); } //function to generate random color in sRGB space