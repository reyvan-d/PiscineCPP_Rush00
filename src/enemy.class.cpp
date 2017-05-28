#include "../includes/enemy.class.hpp"
#include <math.h>
#include <stdlib.h>
#include <time.h>

Enemy::Enemy()
{
	this->ships = NULL;
	this->maxShips = 0;
}

Enemy::Enemy(int ships) : isAlive(false)
{
	this->ships = new Ship[ships];
	this->maxShips = ships;
}

Enemy::Enemy(const Entities& entities)
{
	*this = entities;
}

void Enemy::operator = (const Entities& entities)
{

}

Enemy::~Enemy()
{

}

Ship *Enemy::getShips() {
	return this->ships;
}

int Enemy::getMaxShips() {
	return this->maxShips;
}

bool Enemy::getIsAlive() {
	return this->isAlive;
}

void Enemy::setIsAlive(bool alive) {
	this->isAlive = alive;
}

void Enemy::reset(Ship& ship, Window* window)
{
	srand(time(NULL));
	int r = rand() % (window->getWidth() - 2);
	ship.setPosX(r);
	ship.setPosY(3);
}

bool Enemy::checkColision(int posX, int posY, Window* window)
{
	if (mvinch(posY + 1, posX) == '|' || mvinch(posY, posX) == '|')
		return true;
	else
		return false;
}

int Enemy::update(Window* window) {
	int	k = 0;
	for (int i = 0; i < this->maxShips; i++) {
		if (ships[i].getPosX() > 2 && ships[i].getPosX() < window->getWidth() - 2) {
			// mvdelch(ships[i].getPosY(), ships[i].getPosX());
			// move(ships[i].getPosY(), ships[i].getPosX());
			// mvwprintw(window->getWindow(), ships[i].getPosY(), ships[i].getPosX(), " ");
			// this->ships[i].setPosY(this->ships[i].getPosY() + 1);
			// move(ships[i].getPosY(), ships[i].getPosX());
			/*std::cout << ships[i].getPosX() << std::endl;*/
			// mvwprintw(window->getWindow(), ships[i].getPosY(), ships[i].getPosX(), "0");
			// move(ships[i].getPosY(), ships[i].getPosX());
			// wdelch(window->getWindow());
			// this->ships[i].setPosY(this->ships[i].getPosY() + 1);
			// mvwprintw(window->getWindow(), ships[i].getPosY(), ships[i].getPosX(), "0");
			if (checkColision(ships[i].getPosX(), ships[i].getPosY(), window))
			{
				mvprintw(ships[i].getPosY(), ships[i].getPosX(), " ");
				ships[i].setIsDeployed(false);
				reset(ships[i], window);
				k++;
				return k;
			}
			mvprintw(ships[i].getPosY(), ships[i].getPosX(), " ");
			if (ships[i].getPosY() < window->getHeight() - 2) {
					ships[i].setPosY(ships[i].getPosY() + 1);
					mvprintw(ships[i].getPosY(), ships[i].getPosX(), "0");
			}
			if (ships[i].getPosY() == window->getHeight() - 2) {
				ships[i].setIsDeployed(false);
				reset(ships[i], window);
			}
		}
	}
	// for (int i = 0; i < this->maxShips; i++) {
	// 	if (ships[i].getPosX() > 2 && ships[i].getPosX() < window->getWidth() - 2) {
			// mvprintw(ships[i].getPosY(), ships[i].getPosX(), " ");
			// if (ships[i].getPosY() < window->getHeight() - 2) {
			// 		ships[i].setPosY(ships[i].getPosY() + 1);
			// 		mvprintw(ships[i].getPosY(), ships[i].getPosX(), "0");
	// 		} else if (ships[i].getPosY() == window->getHeight() - 2) {
	// 			ships[i].setIsDeployed(false);
	// 	 		reset(ships[i], window);
	// 		}
	// 	}
	// }
	return 0;
}