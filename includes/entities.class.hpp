#ifndef ENTITIES_CLASS_H
#define ENTITIES_CLASS_H

#include <iostream>
#include <ncurses.h>

class Entities {
    public:
        Entities();
        Entities(const Entities& entities);
        void operator = (const Entities& entities);
        ~Entities();

		int getPosX();
		void setPosX(int posX);
		int getPosY();
		void setPosY(int posY);

    protected:
        int xPosition;
        int yPosition;
};

#endif