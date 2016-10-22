#include "stdafx.h"
#pragma once
#include "particle.h"

sf::Vector2f speed;
float acceleration;
float lifespan;

particle::particle(sf::Vector2f speed, float lifespan, sf::Vector2f spawnPosition): CircleShape(1.f)
{
	setFillColor(sf::Color::White);
	setPosition(spawnPosition);
	particle::speed = speed;
	particle::lifespan = lifespan;
}
particle::particle() {};
particle::~particle() {}
void particle::setSpeed(sf::Vector2f speed)
{
	particle::speed = speed;
}

void particle::setAcceleration(float acceleration)
{
	particle::acceleration = acceleration;
}

void particle::setLifespan(float lifespan)
{
	particle::lifespan = lifespan;
}
void particle::setSpawnpoint(sf::Vector2f spawnpoint)
{
	particle::setPosition(spawnpoint);
}
void particle::update()
{
	if (clock > lifespan) isDead = true;
	particle::move(speed);
	clock++;
}
