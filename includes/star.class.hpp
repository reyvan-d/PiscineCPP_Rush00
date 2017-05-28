#ifndef STAR_CLASS_H
#define STAR_CLASS_H

#include "entities.class.hpp"
#include "window.class.hpp"

class Star : public Entities{
	public:

	Star();
	Star(Window* window);
	Star(const Star& star);
	void operator = (const Star& star);
	~Star();

	int getDefaultTicks();
	int getColor();
	void setDefaultTicks(int ticks);
	void setColor(int color);
	void setWindow(Window* window);

	void update(Window* window);
	void randomPos();
	private:
		int color;
		int ticks;
		int defaultTicks;
		Window* window;
};

#endif
