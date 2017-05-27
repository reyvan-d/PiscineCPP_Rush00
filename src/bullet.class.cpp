#include "../includes/bullet.class.hpp"

Bullet::Bullet()
{

}

Bullet::Bullet(int x, int y)
{
	this->xPosition = x;
	this->yPosition = y - 1;
//	shot();
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
	this->xPosition = x;
}

void Bullet::setPosY(int y)
{
	this->yPosition = y;
}

int Bullet::getPosX()
{
	return this->xPosition;
}

int Bullet::getPosY()
{
	return this->yPosition;
}

void Bullet::setIsShot(bool shot) {
	this->isShot = shot;
}

bool Bullet::getIsShot() {
	return this->isShot;
}

void Bullet::shot()
{
	int milisec = 100; // length of time to sleep, in miliseconds
	struct timespec req = {0};
	req.tv_sec = 0;
	req.tv_nsec = milisec * 1000000L;
	if (mvinch(this->yPosition, this->xPosition) == ' ')
	{
		nanosleep(&req, (struct timespec *) NULL);
		this->yPosition--;
		move(this->yPosition, this->xPosition);
		printw("|");
	}
}
