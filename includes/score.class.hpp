#ifndef SCORE_CLASS_H
#define SCORE_CLASS_H

#include "window.class.hpp"
#include <ncurses.h>

class Score{
	public:
		Score();
		Score(const Score& player);
		void operator = (const Score& player);
		~Score();

		void update(int kills, Window *window);
	private:
		int score;

};

#endif
