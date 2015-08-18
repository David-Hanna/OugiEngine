//-------------------------------------------------------------------------------------------
// Particle.h
// Author: David Hanna
// Copyright (C) 20xx David Hanna, Inc.
//
// This file is part of Ougi Engine.
//
// Ougi Engine is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Ougi Engine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Ougi Engine.  If not, see <http://www.gnu.org/licenses/>.
//-------------------------------------------------------------------------------------------

#ifndef OUGI_PHYSICS_PARTICLE_H
#define OUGI_PHYSICS_PARTICLE_H

#include "../../Math/include/Functions.h"
#include "../../Math/include/Vector3.h"

namespace Ougi
{
	class Particle
	{
	public:
		Particle();
		Particle(const Particle& other);
		~Particle();
		
		Particle& operator=(const Particle& rhs);
		
		Vector3 Position() const;
		Vector3 Velocity() const;
		Vector3 Acceleration() const;
		float Damping() const;
		float Mass() const;
		
		void SetPosition(const float x, const float y, const float z);
		void SetVelocity(const float x, const float y, const float z);
		void SetAcceleration(const float x, const float y, const float z);
		void SetDamping(const float d);
		void SetMass(const float m);
		
		// Integrates the particle forward in time by the given amount.
		// This function uses a Newton-Euler integration method, which is a
		// linear approximation to the correct integral. For this reason
		// it may be inaccurate in some cases.
		void Update(float time);
		
	protected:
		Vector3 position;
		Vector3 velocity;
		Vector3 acceleration;
		
		// Holds the amount of damping applied to linear motion.
		// Damping is required to remove energy added through numerical
		// instability in the integrator.
		float damping;
		
		// Holds the inverse of the mass of the particle. It is more useful
		// to hold the inverse mass because integration is simpler, and because
		// in real-time simulation it is more useful to have objects with
		// infinite mass (immovable) than zero mass (completely unstable).
		float inverseMass;
	}
}
	
	
#endif