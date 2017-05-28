#include "../includes/star.class.hpp"
#include <stdlib.h>

Star::Star(): ticks(0){
}

void Star::update(Window *window) {
	if (this->xPosition > 2 && this->xPosition < window->getWidth() + 2) {
		mvwprintw(window->getWindow(),this->yPosition, this->xPosition, " ");
		if (this->yPosition < window->getHeight() - 3) {
			if (this->ticks <= 0) {
				this->yPosition++;
				mvwprintw(window->getWindow(),this->yPosition, this->xPosition, ".");
				this->ticks = this->defaultTicks;
			} else {
				mvwprintw(window->getWindow(),this->yPosition, this->xPosition, ".");
				this->ticks--;
			}
		} else {
			this->yPosition = 1;
			this->ticks = this->defaultTicks;
		}
	}
}

Star::Star(const Star& star)
{
	*this = star;
}

void Star::operator = (const Star& star) {
}

Star::~Star()
{

}

int Star::getColor() {
	return this->color;
}

void Star::setColor(int color) {
	this->color = color;
}

int Star::getDefaultTicks() {
	return this->ticks;
}

void Star::setDefaultTicks(int ticks) {
	this->defaultTicks = ticks;
}

void Star::setWindow(Window *window) {
	this->window = window;
}

void Star::randomPos() {
	this->xPosition = rand() % (this->window->getWidth() - 2);
	this->yPosition = rand() % this->window->getHeight();
}
