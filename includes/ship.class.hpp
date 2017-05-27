#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

class Ship {
	public:
		Ship();
		Ship(const Ship& ship);
		void operator = (const Ship& ship);
		~Ship();

		void setPosX(int x);
		void setPosY(int y);
		int getPosX();
		int getPosY();
		void setIsDeployed(bool deployed);
		bool getIsDeployed();
	private:
		int posX;
		int posY;
		bool isDeployed;
};

#endif