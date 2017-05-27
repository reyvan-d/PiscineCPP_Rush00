#include "../includes/bullet.class.hpp"

Bullet::Bullet() : isShot(false)
{

}

Bullet::Bullet(const Bullet& bullet)
{
	*this = bullet;
}

void Bullet::operator = (const Bullet& bullet)
{

}

Bullet::~Bullet()
{

}

void Bullet::setPosX(int x)
{
	this->posX = x;
}

void Bullet::setPosY(int y)
{
	this->posY = y;
}

int Bullet::getPosX()
{
	return this->posX;
}

int Bullet::getPosY()
{
	return this->posY;
}

void Bullet::setIsShot(bool shot) {
	this->isShot = shot;
}

bool Bullet::getIsShot() {
	return this->isShot;
}