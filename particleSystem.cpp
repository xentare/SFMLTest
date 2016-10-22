#include "stdafx.h"
#include "particleSystem.h"

std::list<particle*> particles;
sf::Vector2f _spawnPoint;
std::random_device rd;
std::default_random_engine generator(rd()); // rd() provides a random seed
std::uniform_real_distribution<float> distribution(0.1);

particleSystem::particleSystem()
{
	particles = std::list<particle*>();
};

particle *particleSystem::generateParticle()
{
	return new particle(sf::Vector2f((distribution(generator)* 1) - 0.5,(distribution(generator) * 1) - 0.5), rand() % 2000 + 1, _spawnPoint);
	//return new particle(sf::Vector2f(1.f, 1.f), 1000, _spawnPoint);
};

void particleSystem::update()
{
	particles.push_back(generateParticle());
	for (std::list<particle*>::iterator it = particles.begin(); it != particles.end(); ++it) {
		if ((*it)->isDead){
			delete (*it);
			particles.erase(it++);
		}
		else {
			(*it)->update();
		}
	}

};

void particleSystem::setSpawnpoint(sf::Vector2f spawnPoint)
{
	_spawnPoint = spawnPoint;
}

std::list<particle*> particleSystem::getParticles()
{
	return particles;
}
