#ifndef BACKGROUND_CLASS_H
#define BACKGROUND_CLASS_H

#include "star.class.hpp"

class Background{
	public:
		Background();
		Background(int totalStars, Window* window);
		Background(const Background& background);
		void operator = (const Background& background);
		~Background();

		void update(Window *window);

	private:
		Star* closeStars;
		Star* mediumStars;
		Star* farStars;
		int totalStars;


};
#endif
