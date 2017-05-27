#ifndef PISCINE_CPP_WINDOW_CLASS_HPP
#define PISCINE_CPP_WINDOW_CLASS_HPP

#include <ncurses.h>
#include <time.h>


class Window {
	public:
		Window();
		Window(const Window& window);
		void keyhook();
		void operator = (const Window& window);
		~Window();

		void setPosX(int x);
		int getPosX();
		void setPosY(int y);
		int getPosY();
		void setWidth(int width);
		int getWidth();
		void setHeight(int height);
		int getHeight();
		int getKeyPressed();
		void updateTime();
		WINDOW* getWindow();
private:
	int width;
	int height;
	int startPosX;
	int startPosY;
	int posX;
	int posY;
	int keyPressed;
	time_t startTime;
	time_t elapsedTime;
	WINDOW *window;
};

#endif
