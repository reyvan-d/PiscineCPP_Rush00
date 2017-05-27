#include "retro.h"

Engine * engine;

int main()
{
	srand( (unsigned)time(0) );
	engine = new Engine();
	engine->retro();
	endwin();
	return 0;
}