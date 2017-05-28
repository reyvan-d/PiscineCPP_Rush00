#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include "entities.class.hpp"
#include "window.class.hpp"
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
		void reset(Ship& ship, Window* window);
		int update(Window* window);
		bool checkColision(int posX, int posY, Window* window);
	protected:
		Ship *ships;
		int maxShips;
		bool isAlive;
};

#endif
