#include "../includes/ammo.class.hpp"

Ammo::Ammo()
{

}

Ammo::Ammo(int bullets) : isShooting(false)
{
	this->bullets = new Bullet[bullets];
	this->maxBullets = bullets;
}

Ammo::Ammo(const Ammo& ammo)
{
	*this = ammo;
}

void Ammo::operator = (const Ammo& ammo)
{

}

Ammo::~Ammo()
{

}

Bullet *Ammo::getBullets() {
	return this->bullets;
}

int Ammo::getMaxBullets() {
	return this->maxBullets;
}

bool Ammo::getIsShooting() {
	return this->isShooting;
}

void Ammo::setIsShooting(bool isShooting) {
	this->isShooting = isShooting;
}

void Ammo::update() {
	for (int i = 0; i < this->maxBullets; i++) {
		if (bullets[i].getIsShot()) {
			mvprintw(bullets[i].getPosY(), bullets[i].getPosX(), " ");
			this->bullets[i].setPosY(this->bullets[i].getPosY() - 1);
			mvprintw(bullets[i].getPosY(), bullets[i].getPosX(), "|");
		}
		if (bullets[i].getPosY() <= 0){
			bullets[i].setIsShot(false);
		}
	}
}