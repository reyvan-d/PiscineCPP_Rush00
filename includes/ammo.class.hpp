#ifndef AMMO_CLASS_H
#define AMMO_CLASS_H

#include "entities.class.hpp"
#include "bullet.class.hpp"

class Ammo : public Entities {
	public:
		Ammo();
		Ammo(int bullets);
		Ammo(const Ammo& ammo);
		void operator = (const Ammo& ammo);
		~Ammo();
	private:
		Bullet* bullets;
};

#endif