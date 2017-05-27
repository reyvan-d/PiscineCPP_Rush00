#ifndef BULLET_CLASS_H
#define BULLET_CLASS_H

#include "ammo.class.hpp"

class Bullet : public Ammo
{
	public:
		Bullet();
		Bullet(int x, int y);
		Bullet(const Bullet& bullet);
		void operator = (const Bullet& bullet);
		~Bullet();

		void setPosX(int x);
		void setPosY(int y);
		int getPosX();
		int getPosY();
		void setIsShot(bool shot);
		bool getIsShot();
		void shot();
	private:
		bool isShot;
};

#endif