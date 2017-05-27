#include "../includes/player.class.hpp"

Player::Player()
{
    this->xPosition = 13;
    this->yPosition = 78;
}

Player::Player(const Player& player)
{
    *this = player;
}

void Player::operator = (const Player& player)
{
    
}

Player::~Player()
{

}

int Player::getX()
{
    return this->xPosition;
}

void Player::setX(int pos)
{
    this->xPosition = pos;
}

int Player::getY()
{
    return this->yPosition;
}

void Player::setY(int pos)
{
    this->yPosition = pos;
}

void Player::movePlayer(int key)
{
    Player player;
    int x, y;
    x = player.getX();
    y = player.getY();
    mvdelch(y, x);
    if (key == KEY_LEFT && x > 1)
        x--;
    if (key == KEY_RIGHT && x < 79)
        x++;
    if (key == KEY_UP && y > 1)
        y--;
    if (key == KEY_DOWN && y < 24)
        y++;
    mvprintw(y, x, "A");
    player.setX(x);
    player.setY(y);
    return;
}