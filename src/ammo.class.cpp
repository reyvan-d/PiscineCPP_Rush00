#include "../includes/ammo.class.hpp"

Ammo::Ammo()
{

}

Ammo::Ammo(int bullets)
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

void Ammo::update() {
	for (int i = 0; i < this->maxBullets; i++) {
		if (bullets[i].getIsShot()) {
			move(bullets[i].getPosY(), this->bullets[i].getPosX());
			printw("|");
			this->bullets[i].setPosY(this->bullets[i].getPosY() - 1);
		}
		if (bullets[i].getPosY() == 0){
			bullets[i].setIsShot(false);
		}
	}
}