#ifndef Highlight_h
#define Highlight_h
#include <ncurses.h>
class Highlight
{
	public:
		Highlight();
		int print_menu(WINDOW * win, char * Menu[], int size);
	private:
};
#endif

