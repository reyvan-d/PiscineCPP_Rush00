#include "../includes/window.class.hpp"
#include <iostream>

Window::Window() {
	startPosX = 0;
	startPosY = 0;
	posY = this->height / 2;
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	timeout(1);
	keypad(stdscr, TRUE);
	int tempWidth;
	int tempHeight;
	getmaxyx(stdscr, tempHeight, tempWidth);
	this->height = tempHeight - 2;
	this->width = tempWidth;
	this->window = newwin(this->height, this->width, this->startPosY, this->startPosX);
	this->posX = this->width / 2;
	this->posY = this->height - 2;
	wborder(this->window, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(this->window);
	move(this->posY, this->posX);
}

Window::~Window() {}

Window::Window(const Window& window)
{
	*this = window;
}

void Window::operator = (const Window& window)
{
}

void Window::keyhook(){
	this->keyPressed = getch();
	switch(keyPressed){
		case KEY_UP:
			if (this->posY > 1)
				this->posY--;
			return ;
		case KEY_DOWN:
			if (this->posY < this->height - 2)
				this->posY++;
			return ;
		case KEY_RIGHT:
			if (this->posX < this->width - 2)
				this->posX++;
			return ;
		case KEY_LEFT:
			if (this->posX > 1)
				this->posX--;
			return ;
	}
}

void Window::setPosX(int x)
{
	this->posX = x;
}

void Window::setPosY(int y)
{
	this->posY = y;
}

int Window::getPosX()
{
	return this->posX;
}

int Window::getPosY()
{
	return this->posY;
}

void Window::setHeight(int height) {
	this->height = height;
}

int Window::getHeight() {
	return this->height;
}

void Window::setWidth(int width) {
	this->width = width;
}

int Window::getWidth() {
	return this->width;
}

int Window::getKeyPressed()
{
	return this->keyPressed;
}

WINDOW* Window::getWindow()
{
	return this->window;
}
