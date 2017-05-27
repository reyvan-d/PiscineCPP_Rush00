#ifndef BULLET_CLASS_H
#define BULLET_CLASS_H

class Bullet
{
	public:
		Bullet();
		Bullet(const Bullet& bullet);
		void operator = (const Bullet& bullet);
		~Bullet();

		void setPosX(int x);
		void setPosY(int y);
		int getPosX();
		int getPosY();
		void setIsShot(bool shot);
		bool getIsShot();
	private:
		int posX;
		int posY;
		bool isShot;
};

#endif