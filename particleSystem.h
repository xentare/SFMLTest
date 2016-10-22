#include "stdafx.h"
#pragma once
#include "particle.h"


class particleSystem
{
private:
	std::list<particle*> particles;
	sf::Vector2f spawnPoint;
	std::random_device rd;
	std::default_random_engine generator; // rd() provides a random seed
	std::uniform_real_distribution<double> distribution;

public:
	particleSystem();
	particle* generateParticle();
	void update();
	void setSpawnpoint(sf::Vector2f spawnPoint);
	std::list<particle*> getParticles();
};
