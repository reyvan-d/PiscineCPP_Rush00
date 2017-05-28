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

void Enemy::reset(Ship& ship)
{
	srand(time(NULL));
	int r = 10 + rand() % (80 - 10);
	ship.setPosX(r);
	ship.setPosY(3);
}

void Enemy::update() {
	for (int i = 0; i < this->maxShips; i++) {
		if (ships[i].getIsDeployed()) {
			/*mvdelch(ships[i].getPosY(), ships[i].getPosX());*/
			move(ships[i].getPosY(), ships[i].getPosX());
			addch(' ');
			this->ships[i].setPosY(this->ships[i].getPosY() + 1);
			move(ships[i].getPosY(), ships[i].getPosX());
			/*std::cout << ships[i].getPosX() << std::endl;*/
			addch('0');
			
		}
		if (ships[i].getPosY() >= 40 || mvgetch(ships[i].getPosY() + 1, ships[i].getPosX()) == '|' || mvgetch(ships[i].getPosY(), ships[i].getPosX()) == '|') {
			ships[i].setIsDeployed(false);
			reset(ships[i]);
		}
	}
}