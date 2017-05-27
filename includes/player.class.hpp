#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "entities.class.hpp"

class Player : public Entities {
    public:
        Player();
        Player(const Player& player);
        void operator = (const Player& player);
        ~Player();

        void movePlayer(int key, Player* player);
        void setX(int pos);
        void setY(int pos);
		void update(int key, Player* player, int x, int y);
        int getX();
        int getY();
    private:
};

#endif