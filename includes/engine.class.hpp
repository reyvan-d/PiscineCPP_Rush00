#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include "player.class.hpp"
#include "enemy.class.hpp"
#include "window.class.hpp"
#include "bullet.class.hpp"

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
};

#endif