#include "retro.h"

Engine * engine;

int main()
{
	engine = new Engine();
	engine->retro();
	endwin();
	return 0;
}