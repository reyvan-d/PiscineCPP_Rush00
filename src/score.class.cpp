#include "../includes/score.class.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Score::Score()
{

}

Score::Score(const Score& score)
{
	*this = score;
}

void Score::operator = (const Score& score)
{

}

Score::~Score()
{

}

int Score::getScore() {
	return this->score;
}

void Score::update(int kills, Window *window) {
	if (kills)
		this->score += 100;
	this->score += 1;
	std::string newString = "SCORE: " + std::to_string(score);
	mvwprintw(stdscr, window->getHeight(), 3, newString.c_str());
}

