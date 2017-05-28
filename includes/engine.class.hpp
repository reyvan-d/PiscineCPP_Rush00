#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include "player.class.hpp"
#include "enemy.class.hpp"
#include "window.class.hpp"
#include "ammo.class.hpp"
#include "bullet.class.hpp"
#include "score.class.hpp"
#include "background.class.hpp"
#include "star.class.hpp"
#include "mothership.class.hpp"

class Engine {
	public:
		Engine();
		Engine(const Engine& engine);
		void operator = (const Engine& engine);
		~Engine();

		void update();
		void retro();
	protected:
		Player* player;
		Enemy* enemy;
		Window* window;
		Bullet* bullets;
		Ammo* ammo;
		Score* score;
		Background* background;
		Mothership* mothership;
};

#endif