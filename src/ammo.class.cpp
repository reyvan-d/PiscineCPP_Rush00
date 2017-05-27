#include "../includes/ammo.class.hpp"

Ammo::Ammo()
{

}

Ammo::Ammo(int bullets)
{
	this->bullets = new Bullet[bullets];
	for (int i = 0; i < bullets; i++)
	{

	}
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