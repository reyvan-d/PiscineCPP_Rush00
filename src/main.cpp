#include "../includes/retro.h"

int keyhook(){
	WIN_KEY_PRESSED = getch();
	int ret = 0;
	switch(WIN_KEY_PRESSED){
		case KEY_UP:
			if (WIN_CURSY > 1)
				WIN_CURSY--;
			return 0;
		case KEY_DOWN:
			if (WIN_CURSY < WIN_HEIGHT - 2)
				WIN_CURSY++;
			return 0;
		case KEY_RIGHT:
			if (WIN_CURSX < WIN_WIDTH - 2)
				WIN_CURSX++;
			return 0;
		case KEY_LEFT:
			if (WIN_CURSX > 1)
				WIN_CURSX--;
			return 0;
		case ' ':
			//firebullet function goes here
			return 0;
		case 27:
			ret = 0;
			return 0;
	}
	return ret;
}

void initGame(){
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	GAME_WIN = newwin(WIN_HEIGHT,WIN_WIDTH,WIN_STARTY, WIN_STARTX);
	// box(GAME_WIN, 0, 0);
	wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(GAME_WIN);
	move(WIN_CURSY, WIN_CURSX);
}

int main()
{
	initGame();

	while (1) {
		move(WIN_CURSY, WIN_CURSX);
		box(GAME_WIN, 0, 0);
		wrefresh(GAME_WIN);
		if (keyhook() == 1)
			break;
	}
	endwin();
	return 0;
}