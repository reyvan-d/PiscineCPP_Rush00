#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include "entities.class.hpp"

class Enemy : public Entities {
	public:
		Enemy();
		Enemy(const Entities& enemy);
		void operator = (const Entities& enemy);
		~Enemy();
};

#endif
