#pragma once
#include<SFML/Graphics.hpp>

constexpr auto RESOLUTION_X = 1280;
constexpr auto RESOLUTION_Y = 720;
constexpr auto COLORDEPTH = 32;

const sf::Vector2f particle_size = sf::Vector2f(1.0f, 1.0f);
const float retardation = 1.0f;
const float gravity = 1.0f;
const unsigned int initialVelocityFactor = 100u;
const unsigned int frameRateLimit = 90u;
const sf::VideoMode currentVideoMode = sf::VideoMode(RESOLUTION_X, RESOLUTION_Y, COLORDEPTH);
const unsigned int particleDensity = 5u;
const float particleGenerationTimer = 1.0f;
const sf::Color BaseParticleColor(255u, 0u, 255u);

inline sf::Color randomColorGen() { return sf::Color(rand() % 255, rand() % 255, rand() % 255); }