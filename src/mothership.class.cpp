#include "../includes/mothership.class.hpp"

Mothership::Mothership() {}

Mothership::Mothership(Window* window) {
	this->alive = false;
	this->direction = 0;
	this->width = 18;
	this->height = 4;
	this->xPosition = (window->getWidth() / 2) - (this->width / 2);
	this->yPosition = -1;
}


void Mothership::update(Window* window) {
		std::string shape[] = {"    [_^___^_]    ", "<--------------->", "  [_]\\     /[_]  ", "       \\_/      "};
		if (this->alive) {
			for (int i = 0; i < this->height; i++) {
				mvwprintw(window->getWindow(), this->yPosition, this->xPosition, "                  ");
			}
			if (this->yPosition < 3) {
				this->yPosition++;
			}
			mvwprintw(window->getWindow(), this->yPosition + 1, this->xPosition , shape[0].c_str());
			mvwprintw(window->getWindow(), this->yPosition + 2, this->xPosition , shape[1].c_str());
			mvwprintw(window->getWindow(), this->yPosition + 3, this->xPosition , shape[2].c_str());
			mvwprintw(window->getWindow(), this->yPosition + 4, this->xPosition , shape[3].c_str());
		}
}

void Mothership::setAlive(bool newAlive){
	this->alive = newAlive;
}

Mothership::Mothership(const Mothership& mothership)
{
	*this = mothership;
}

void Mothership::operator = (const Mothership& mothership) {
}

Mothership::~Mothership()
{

}