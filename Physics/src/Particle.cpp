#include "../include/Particle.h"

Ougi::Vector3 Ougi::Particle::Position() const
{
	return position;
}

Ougi::Vector3 Ougi::Particle::Velocity() const
{
	return velocity;
}

Ougi::Vector3 Ougi::Particle::Acceleration() const
{
	return acceleration;
}

float Ougi::Particle::Damping() const
{
	return damping;
}

float Ougi::Particle::Mass() const
{
	if (inverseMass == 0.0f) return inverseMass;
	return (1.0f / inverseMass);
}

void Ougi::Particle::SetPosition(const float x, const float y, const float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void Ougi::Particle::SetVelocity(const float x, const float y, const float z)
{
	velocity.x = x;
	velocity.y = y;
	velocity.z = z;
}

void Ougi::Particle::SetAcceleration(const float x, const float y, const float z)
{
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = z;
}

void Ougi::Particle::SetDamping(const float d)
{
	damping = d;
}

void Ougi::Particle::SetMass(const float m)
{
	if (m == 0.0f) inverseMass = m;
	else inverseMass = (1.0f / m);
}

void Ougi::Particle::Update(float time)
{
	if (inverseMass <= 0.0f) return;
	
	position += velocity * time;
	velocity += acceleration * time * exp(damping, time);
}