#ifndef SCORE_CLASS_H
#define SCORE_CLASS_H

#include "window.class.hpp"
#include <ncurses.h>

class Score{
	public:
		Score();
		Score(const Score& score);
		void operator = (const Score& score);
		~Score();

		int getScore();

		void update(int kills, Window *window);
	private:
		int score;

};

#endif
