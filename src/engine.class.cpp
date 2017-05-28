#include "../includes/engine.class.hpp"


Engine::Engine() {
	this->window = new Window();
	this->player = new Player();
	this->enemy = new Enemy(1);
	this->ammo = new Ammo(150);
	this->score = new Score();
	this->background = new Background(20, this->window);
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
	int i = this->enemy->update(this->window);
	this->ammo->update();
	this->score->update(i, this->window);
	this->window->updateTime();
	this->background->update(this->window);
	this->player->update(this->window);
}

void Engine::retro()
{
	int milisec = 30; // length of time to sleep, in miliseconds
	struct timespec req = { 0 };
	req.tv_sec = 0;
	req.tv_nsec = milisec * 1000000L;

	this->player->setX(this->window->getPosX());
	this->player->setY(this->window->getPosY());
	while (1) {
		wborder(this->window->getWindow(), 0, 0, 0, 0, 0, 0, 0, 0);
		this->window->keyhook();
		if (this->window->getKeyPressed() == KEY_EXIT)
			break;
		else if (this->window->getKeyPressed() == ' ') {
			if (mvgetch(this->player->getY() - 1, this->player->getX()) != '|') {
				Bullet *bullets = this->ammo->getBullets();
				for (int i = 0; i < this->ammo->getMaxBullets(); i++) {
					if (!bullets[i].getIsShot() && !this->ammo->getIsShooting()) {
						bullets[i].setIsShot(true);
						bullets[i].setPosX(this->player->getX());
						bullets[i].setPosY(this->player->getY() - 1);
						this->ammo->setIsShooting(true);
					}
				}
				this->ammo->setIsShooting(false);
			}
		}
		Ship *ships = this->enemy->getShips();
		for (int i = 0; i < this->enemy->getMaxShips(); i++) {
			if (!ships[i].getIsDeployed() && !this->enemy->getIsAlive()) {
				ships[i].setIsDeployed(true);
				this->enemy->setIsAlive(true);
			}
		}
		this->enemy->setIsAlive(false);
		this->update();
		nanosleep(&req, (struct timespec *) NULL);
		wrefresh(this->window->getWindow());
	}
}