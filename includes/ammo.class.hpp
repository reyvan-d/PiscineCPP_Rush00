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

		Bullet *getBullets();
		int getMaxBullets();
		void update();
		bool getIsShooting();
		void setIsShooting(bool isShooting);
	protected:
		Bullet *bullets;
		int maxBullets;
		bool isShooting;
};

#endif