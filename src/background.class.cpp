#include "../includes/background.class.hpp"


Background::Background(){

}

Background::Background(int stars, Window* window) : totalStars(stars)
{
	this->closeStars = new Star[totalStars];
	this->mediumStars = new Star[totalStars];
	this->farStars = new Star[totalStars];
	for(int i = 0; i < totalStars; i++){
		this->closeStars[i].setColor(1);
		this->closeStars[i].setWindow(window);
		this->closeStars[i].setDefaultTicks(0);
		this->closeStars[i].randomPos();
		this->mediumStars[i].setColor(2);
		this->mediumStars[i].setWindow(window);
		this->mediumStars[i].setDefaultTicks(3);
		this->mediumStars[i].randomPos();
		this->farStars[i].setColor(3);
		this->farStars[i].setWindow(window);
		this->farStars[i].setDefaultTicks(8);
		this->farStars[i].randomPos();
	}
}

void Background::update(Window* window){
	for (int i = 0; i < this->totalStars; i++){
		this->closeStars[i].update(window);
		this->mediumStars[i].update(window);
		this->farStars[i].update(window);
	}
}

Background::Background(const Background& background)
{
	*this = background;
}

void Background::operator = (const Background& background) {
}

Background::~Background()
{

}
