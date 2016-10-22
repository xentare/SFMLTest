#include "stdafx.h"
#pragma once

class particle : public sf::CircleShape
{
private:
	sf::Vector2f speed;
	float acceleration;
	float lifespan;
	int clock = 0;

public:
	particle(sf::Vector2f speed, float lifespan, sf::Vector2f spawnPosition);
	particle();
	~particle();
	void setSpeed(sf::Vector2f speed);

	void setAcceleration(float acceleration);

	void setLifespan(float lifespan);

	void setSpawnpoint(sf::Vector2f spawnpoint);

	void update();

	bool isDead = false;
};