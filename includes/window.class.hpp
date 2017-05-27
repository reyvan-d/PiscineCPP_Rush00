#ifndef PISCINE_CPP_WINDOW_CLASS_HPP
#define PISCINE_CPP_WINDOW_CLASS_HPP

#include <ncurses.h>

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
		WINDOW* getWindow();
private:
	int width;
	int height;
	int startPosX;
	int startPosY;
	int posX;
	int posY;
	int keyPressed;
	WINDOW *window;
};

#endif
