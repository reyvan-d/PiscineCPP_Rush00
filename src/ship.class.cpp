#include "../includes/ship.class.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

Ship::Ship()
{
	srand(time(NULL));
	int r = 10 + rand() % (80 - 10);
	this->posX = r;
	this->posY = 3;
	this->isDeployed = false;
}

Ship::Ship(const Ship& ship)
{
	*this = ship;
}

void Ship::operator = (const Ship& enemy)
{

}

Ship::~Ship()
{

}

void Ship::setPosX(int x)
{
	this->posX = x;
}

void Ship::setPosY(int y)
{
	this->posY = y;
}

int Ship::getPosX()
{
	return this->posX;
}

int Ship::getPosY()
{
	return this->posY;
}

void Ship::setIsDeployed(bool deployed) {
	this->isDeployed = deployed;
}

bool Ship::getIsDeployed() {
	return this->isDeployed;
}