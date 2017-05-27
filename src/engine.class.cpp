#include "../includes/engine.class.hpp"

Engine::Engine() {
	this->window = new Window();
	this->player = new Player();
	this->enemy = new Enemy();
	this->ammo = new Ammo(150);
}

Engine::~Engine() {
	delete enemy;
	delete player;
	delete window;
	delete[] bullets;
}

Engine::Engine(const Engine& engine)
{
	*this = engine;
}

void Engine::operator = (const Engine& engine)
{
}

void Engine::update()
{

}

void Engine::retro()
{
	int milisec = 30; // length of time to sleep, in miliseconds
	struct timespec req = {0};
	req.tv_sec = 0;
	req.tv_nsec = milisec * 1000000L;

	this->player->setX(this->window->getPosX());
	this->player->setY(this->window->getPosY());
	while (1) {
		move(this->window->getPosY(), this->window->getPosX());
		this->player->setX(this->window->getPosX());
		this->player->setY(this->window->getPosY());
		printw("A");
		box(this->window->getWindow(), 0, 0);
		this->window->keyhook();

		if (this->window->getKeyPressed() == KEY_EXIT)
			break;
		else if (this->window->getKeyPressed() == ' ') {
			if (mvgetch(this->player->getY() - 1, this->player->getX()) != '|'){
				for (int i = 0; i < this->ammo->getMaxBullets(); i++){
					if (!this->ammo->getBullets()[i].getIsShot()){
						this->ammo->getBullets()[i].setIsShot(true);
						this->ammo->getBullets()[i].setPosX(this->player->getX());
						this->ammo->getBullets()[i].setPosY(this->player->getY() - 1);
					}
				}
			}
		}
		this->ammo->update();
		nanosleep(&req, (struct timespec *) NULL);
//		bullet->setPosY(bullet->getPosY() - 1);
//		move(bullet->getPosY(), bullet->getPosX());
//		printw("|");

		wrefresh(this->window->getWindow());
	}
}