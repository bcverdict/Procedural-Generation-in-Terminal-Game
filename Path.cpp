#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <mutex>
#include "Path.h"
#define WIDTH 60
#define HEIGHT 50
using namespace std;
using namespace this_thread;
using namespace chrono;
mutex mu;
Path::Path()
{
	TT1 = false;
	Exit = false;
	initscr();
	noecho();
	D = new Dialog();
	H = new Highlight();
	Des = new Designs();
	Des->Title();
//	Des->Guides(1);
	m_Counter = 0;
	m_StartRow = 15;
	m_StartCol = 10;
	m_MenuCounter = 1;
	PWindow(FirstMenu);
	
}
Path::~Path()
{
	delete D;
	delete H;
	delete Des;
}
void Path::MenuSwitch(WINDOW * win, int Screen, int choice)
{
	int Selection = 0;
	if(Screen == 1)
	{
		if(choice == 0)
		{
			m_MenuCounter+=1;
			werase(win);
			box(win, 0, 0);
			Selection = H->print_menu(win, SecondMenu, 3);
			MenuSwitch(win, m_MenuCounter, Selection);
			wrefresh(win);
		}
		else if(choice == 1)
		{
			WINDOW * Helpwin = newwin(3, 60, 25, 50);
			refresh();
			//box(Helpwin, 0, 0);
			mvwprintw(Helpwin, 0, 0, "Use the Arrow keys to move LEFT, RIGHT, UP, or DOWN");
			wrefresh(Helpwin);
			getch();
			wclear(Helpwin);
			mvwprintw(Helpwin, 0, 0, "Beware of traps set by the one called 'the creator'");
			wrefresh(Helpwin);
			getch();
			wclear(Helpwin);
			mvwprintw(Helpwin, 0, 0, "Talk to characters for help in finding and making it through the traps alive");
			wrefresh(Helpwin);
			getch();
			wclear(Helpwin);
			wrefresh(Helpwin);
			delete Helpwin;
			PWindow(FirstMenu);
			wrefresh(win);
		}
		else if(choice == 2)
		{
			clear();
			mvprintw(0, 0, "Goodbye!");
			wrefresh(win);
		}
	}
	else if(Screen == 2)
	{
		if(choice == 0)
		{
			m_FieldRow = 31;
			m_FieldCol = 93;
			for(int i=0; i<m_FieldRow; i++)
			{
				for(int j = 0; j<m_FieldCol; j++)
				{
					m_Field[i][j]=" ";
				}
			}
			m_Field[m_StartRow][m_StartCol]="1";
			wclear(win);
			wrefresh(win);
			//Print();
			Keys();
		}
		else if(choice == 1)
		{
			m_FieldRow = 21;
			m_FieldCol = 31;
			for(int i=0; i<m_FieldRow; i++)
			{
				for(int j = 0; j<m_FieldCol; j++)
				{
					m_Field[i][j]=" ";
				}
			}
			wclear(win);
			wrefresh(win);
			m_Field[m_StartRow][m_StartCol]="1";
			//Print();
			Keys();
		}
		else if(choice == 2)
		{
			m_MenuCounter-=1;
			werase(win);
			box(win, 0, 0);
			Selection = H->print_menu(win, FirstMenu, 3);
			MenuSwitch(win, m_MenuCounter, Selection);
			wrefresh(win);
		}
	}

	wclear(win);
	wrefresh(win);
}
void Path::PWindow(char * Menu[3])
{
	initscr();
	noecho();
	WINDOW * win = newwin(5, 20, 20, 65);
	refresh();
	box(win, 0, 0);
	wrefresh(win);
	int Highlight = H->print_menu(win, Menu, 3);
	MenuSwitch(win, m_MenuCounter, Highlight);
	endwin();

}

void Path::Wall()
{
	while(!Exit)
	{
		if(m_Counter >= 54)
		{
			for(int j = 0; j < m_FieldCol; j++)
			{
				for(int k = 0; k < m_FieldRow; k++)
				{
					m_Field[k][0] = "E";
				}
				Update();
				for(int i = 0; i < m_FieldRow; i++)
				{
					m_Field[i][j] = ".";
				}
				Update();
				if(m_StartCol == j)
				{
					Exit = true;
					break;
				}
				sleep_until(system_clock::now()+seconds(1));
				if(m_StartCol == 0)
				{
					Exit = true;
					break;
				}
			}
			if(m_StartCol == 0)
			{
				break;
			}
		}
	}
}
void Path::Ending()
{
	while(1)
	{
		if(Exit)
		{
			ifstream InFile("Title.txt");
			string Cover((istreambuf_iterator<char>(InFile)), istreambuf_iterator<char>());
			const char * TitleValue = Cover.c_str();
			initscr();
			WINDOW * Top = newwin(10, 82, 0, 40);
			refresh();
			mvwprintw(Top, 1, 1, TitleValue);
			box(Top, 0, 0);
			int sizex = 10;
			int sizey = 82;
			int spacey = 40;
			int titlex = 1;
			for(int x = 0; x<17; x++)
			{
				if(x>12)
				{
					sizex += 1;
				}
				sizex += 1;
				sizey += 2;
				spacey -= 1;
				wclear(Top);
				wrefresh(Top);
				Top = newwin(sizex, sizey, x, spacey);
				refresh();
				box(Top, 0, 0);
				wrefresh(Top);
				sleep_until(system_clock::now()+nanoseconds(500000000));
				if(x == 16)
				{
					for(sizey; sizey > 38; sizey-=8)
					{
						wclear(Top);
						wrefresh(Top);
						Top = newwin(sizex, sizey, x, spacey);
						refresh();
						box(Top, 0, 0);
						wrefresh(Top);
						sleep_until(system_clock::now()+nanoseconds(500000000));
					}
				}
			}
			wclear(Top);
			ifstream DoorFile("Door.txt");
			string Door((istreambuf_iterator<char>(DoorFile)), istreambuf_iterator<char>());
			const char * DoorValue = Door.c_str();
			mvwprintw(Top, 0, 0, DoorValue);
			wrefresh(Top);
			sleep_until(system_clock::now()+seconds(2));
			break;
		}
	}
}
void Path::Keys()
{
	initscr();
	noecho();
	Playwin = newwin(m_FieldRow+2, m_FieldCol+2, 10, 35);
 	InvWin = newwin(m_FieldRow + 2, 20, 10, 10);
	refresh();
	box(Playwin, 0, 0);
	Update();
	keypad(Playwin, true);
	thread t1 = thread(&Path::Wall, this);
	thread t2 = thread(&Path::Ending, this);
	while(!Exit)
	{
		int Arrows = wgetch(Playwin);
		switch(Arrows)
		{
			if(!Exit)
			{
				case KEY_UP:
					m_Counter += 1;
					if(m_Field[m_StartRow-1][m_StartCol] == "T")
					{
						TokenKeys();
						box(Playwin, 0, 0);
						Update();
					}
					else if((m_Field[m_StartRow-1][m_StartCol]!=".")&&(m_StartRow > 3))
					{
						m_Field[m_StartRow][m_StartCol]=" ";
						m_StartRow-=1;
						m_Field[m_StartRow][m_StartCol]="1";
						Update();
					}
					else if((m_Field[m_StartRow-1][m_StartCol]!=".")&&(m_StartRow == 3))
					{
						MovementDown();
						Sky();
						Update();
					}
				break;
				case KEY_RIGHT:
					if(m_Field[m_StartRow][m_StartCol + 1] == "T")
					{
						TokenKeys();
						box(Playwin, 0, 0);
						Update();
					}
					else if((m_Field[m_StartRow][m_StartCol+1]!=".")&&(m_StartCol < m_FieldCol - 1))
					{
						m_Field[m_StartRow][m_StartCol]=" ";
						m_StartCol+=1;
						m_Field[m_StartRow][m_StartCol]="1";
						Update();
					}
				break;
				case KEY_DOWN:
					m_Counter -= 1;
					if(m_Field[m_StartRow+1][m_StartCol] == "T")
					{
						TokenKeys();
						box(Playwin, 0, 0);
						Update();
					}
					else if((m_Field[m_StartRow+1][m_StartCol]!=".")&&(m_StartRow < m_FieldRow - 3))
					{
						m_Field[m_StartRow][m_StartCol]=" ";
						m_StartRow+=1;
						m_Field[m_StartRow][m_StartCol]="1";
						Update();
					}
					else if((m_Field[m_StartRow+1][m_StartCol]!=".")&&(m_StartRow == m_FieldRow - 3))
					{
						MovementUp();
						Ground();
						Update();
					}
				break;
				case KEY_LEFT:
				if(m_Field[m_StartRow][m_StartCol-1] == "T")
				{
					TokenKeys();
					box(Playwin, 0, 0);
					Update();
				}
				else if((m_Field[m_StartRow][m_StartCol-1]!=".")&&(m_StartCol > 0))
				{
					m_Field[m_StartRow][m_StartCol]=" ";
					m_StartCol-=1;
					m_Field[m_StartRow][m_StartCol]="1";
					Update();
				}
				break;
				case 105:
				{		
					box(InvWin, 0, 0);
					Des->Print(InvWin);
					wclear(InvWin);
					wrefresh(InvWin);
				}
				break;
				default:
				break;
			}
		}
	}
	t1.join();
	t2.join();
	endwin();
}
void Path::Update()
{
	mu.lock();
	for(int k = 1; k<=m_FieldRow; k++)
	{
		for(int l = 1; l<=m_FieldCol; l++)
		{
			if(m_Field[k-1][l-1] == ".")
			{
				wattron(Playwin, A_REVERSE);
				mvwprintw(Playwin, k, l, " ");
				wattroff(Playwin, A_REVERSE);
			}
			else
			{
				mvwprintw(Playwin, k, l, m_Field[k-1][l-1]);
			}
		}
	}
	wrefresh(Playwin);
	mu.unlock();
}

void Path::TokenKeys()
{
	int i = 0;
	if((m_Counter > 20)&&(m_Counter < 30))
	{
		i = 1;
	}
	else if((m_Counter > 290)&&(m_Counter < 300))
	{
		i = 2;
	}
	switch(i)
	{
		case 1:
		{
			D->Chat(i, Des);
			break;
		}
		case 2:
		{
			D->Chat(i, Des);
			break;
		}
	}
	box(Playwin, 0, 0);
	Update();
}

void Path::Sky()
{
	int Counter = 5;
	srand(m_Counter+3);
	for(int i = 0; i < Counter; i++)
	{
		int Val=rand()%(m_FieldCol+0);
		if(m_Field[0][Val]==" ")
		{
			m_Field[0][Val]=".";
		}
	}
	if((m_Counter == 21)||(m_Counter == 292))
	{
		m_Field[0][12] = "T";
	}
	string i = to_string(m_Counter);
	const char  * number = i.c_str();
//	mvwprintw(Playwin, 0, 0, number);
}

void Path::Ground()
{
	int Counter = 5;
	srand(m_Counter-3);
	for(int i = 0; i < Counter; i++)
	{
		int Val=rand()%(m_FieldCol+0);
		if(m_Field[m_FieldRow-1][Val]==" ")
		{
			m_Field[m_FieldRow-1][Val]=".";
		}
	}
	if((m_Counter == 26)||(m_Counter == 297))
	{
		m_Field[m_StartRow + 2][12] = "T";
	}
	string i = to_string(m_Counter);
	const char  * number = i.c_str();
//	mvwprintw(Playwin, 0, 0, number);
}
void Path::MovementDown()
{
	m_Field[m_StartRow][m_StartCol]=" ";
	for(int i = m_FieldRow-2; i>=0; i--)
	{
		for(int j = 0; j < m_FieldCol; j++)
		{
			m_Field[i+1][j]=m_Field[i][j];
		}
	}
	for(int k = 0; k < m_FieldCol; k++)
	{
		m_Field[0][k]=" ";
	}
	m_Field[m_StartRow][m_StartCol]="1";
}

void Path::MovementUp()
{
	m_Field[m_StartRow][m_StartCol]=" ";
	for(int i = 0; i < m_FieldRow; i++)
	{
		for(int j = 0; j < m_FieldCol; j++)
		{
			m_Field[i][j]=m_Field[i+1][j];
		}
	}
	for(int k = 0; k < m_FieldCol; k++)
	{
		m_Field[m_FieldRow-1][k]=" ";
	}
	m_Field[m_StartRow][m_StartCol]="1";
}
void Path::setArray(int Screen)
{
	if(Screen==1)
	{
		m_FieldRow = 20;
		m_FieldCol = 31;
		m_StartRow = 15;
		m_StartCol = 10;
	}
	else if(Screen==2)
	{
		m_FieldRow = 15;
		m_FieldCol = 25;
		m_StartRow = 7;
		m_StartCol = 5;
	}

	m_Field[m_StartRow][m_StartCol]="1";
}
