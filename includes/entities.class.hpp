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
    protected:
        int xPosition;
        int yPosition;
};

#endif