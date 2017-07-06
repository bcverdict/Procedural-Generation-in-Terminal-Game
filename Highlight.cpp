#include "Highlight.h"
#include <string>
using namespace std;
Highlight::Highlight()
{
}
int Highlight::print_menu(WINDOW * win, char * Menu[], int size)
{
	int highlightNum = 0;
	keypad(win, true);
	while(1)
	{
		for(int i = size; i > 0; i--)
		{
			if(highlightNum == i-1)
			{
				wattron(win, A_REVERSE);
				mvwprintw(win, i, 1, Menu[i-1]);
				wattroff(win, A_REVERSE);
			}
			else
			{
				mvwprintw(win, i, 1, Menu[i-1]);
			}
		}
		wrefresh(win);
		int Arrows = wgetch(win);
		switch(Arrows)
		{
			case KEY_UP:
				highlightNum-=1;
				if(highlightNum == -1)
				{
					highlightNum = 0;
				}
			break;
			case KEY_DOWN:
				highlightNum+=1;
				if(highlightNum == size)
				{
					highlightNum = size - 1;
				}
			break;
			default:
			break;
		}
		if(Arrows == 10)
		break;
	}
	return(highlightNum);
}

