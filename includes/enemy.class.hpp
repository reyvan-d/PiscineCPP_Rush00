#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include "entities.class.hpp"
#include "ship.class.hpp"

class Enemy : public Entities {
	public:
		Enemy();
		Enemy(int ships);
		Enemy(const Entities& enemy);
		void operator = (const Entities& enemy);
		~Enemy();

		Ship* getShips();
		int getMaxShips();
		bool getIsAlive();
		void setIsAlive(bool alive);
		void reset(Ship& ship);
		void update();
	protected:
		Ship *ships;
		int maxShips;
		bool isAlive;
};

#endif
