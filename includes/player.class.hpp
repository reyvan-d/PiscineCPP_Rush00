#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "retro.h"

class Player : public Entities {
    public:
        Player();
        Player(const Player& player);
        void operator = (const Player& player);
        ~Player();

        void movePlayer(int key);
        void setX(int pos);
        void setY(int pos);
        int getX();
        int getY();
    private:
};

#endif