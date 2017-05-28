#ifndef MOTHERSHIP_CLASS_H
#define MOTHERSHIP_CLASS_H

#include "entities.class.hpp"
#include "score.class.hpp"

class Mothership : public Entities{
	public:
		Mothership();
		Mothership(Window* window);
		Mothership(const Mothership& mothership);
		void operator = (const Mothership& mothership);
		~Mothership();

		void setAlive(bool newAlive);

		void update(Window *window);

	private:
		int xp;
		int width;
		int height;
		int direction;
		bool alive;
		Score *score;
};

#endif