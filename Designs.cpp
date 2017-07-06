#include "Designs.h"
#include <fstream>
using namespace std;
Designs::Designs()
{
	m_Front = nullptr;
	m_size = 0;
	Exit = false;
}
void Designs::Title()
{
	ifstream InFile("Title.txt");
	string Cover((istreambuf_iterator<char>(InFile)), istreambuf_iterator<char>());
	const char * TitleValue = Cover.c_str();
	initscr();
	WINDOW * Top = newwin(10, 82, 0, 40);
	refresh();
	mvwprintw(Top, 1, 1, TitleValue);
	box(Top, 0, 0);
	wrefresh(Top);
}
void Designs::Guides(int i)
{
	ifstream InFile;
	if(i == 1)
	{
		InFile.open("Guide1.txt");
	}
	string Cover((istreambuf_iterator<char>(InFile)), istreambuf_iterator<char>());
	const char * Guide = Cover.c_str();
	initscr();
	WINDOW * WinGuide = newwin(33, 120, 10, 30);
	refresh();
	mvwprintw(WinGuide, 1, 1, Guide);
	box(WinGuide, 0, 0);
	wrefresh(WinGuide);
	getch();
	werase(WinGuide);
	wrefresh(WinGuide);
	delete WinGuide;
	refresh();
	Add(Guide, "Guide1");
	m_size += 1;
}
int Designs::VecPrint(WINDOW * win)
{

}
void Designs::Print(WINDOW * win)
{
	Node<char *> * temp = m_Front;
	if(m_size != 0)
	{
		int highlightNum = 0;
		keypad(win, true);
		while(1)
		{
			for(int i = m_size; i > 0; i--)
			{
				if(highlightNum == i-1)
				{
					wattron(win, A_REVERSE);
					mvwprintw(win, i, 1, temp->getName());
					wattroff(win, A_REVERSE);
				}
				else
				{
					mvwprintw(win, i, 1, temp->getName());
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
						temp = temp->getPrev();
						highlightNum = 0;
					}
				break;
				case KEY_DOWN:
					highlightNum+=1;
					if(highlightNum == m_size)
					{
						temp = temp->getNext();
						highlightNum = m_size - 1;
					}
				break;
				default:
				break;
			}
			if((Arrows == 10)||(Arrows == 105))
			break;
		}
	}

}
int Designs::getSize()
{
	return(m_size);
}
void Designs::Add(const char * File, char * Name)
{
	Node<char *> * N = new Node<char *>();
	N->setName(Name);
	N->setFile(File);
	if(m_size == 0)
	{
		m_Front = N;
		N->setNext(nullptr);
		N->setPrev(nullptr);
	}
	else if(m_size == 1)
	{
		if(N->getName() < m_Front->getName())
		{
			N->setNext(m_Front);
			N->setPrev(nullptr);
			m_Front->setPrev(N);
			m_Front = N;
		}
		else
		{
			m_Front->setNext(N);
			N->setNext(nullptr);
			N->setPrev(m_Front);
		}
	}
	else
	{
		Node<char *> * temp = m_Front;
		while((N->getName() > temp->getName())&&(temp->getNext() != nullptr))
		{
			temp = temp->getNext();
		}
		if(temp == m_Front)
		{
			N->setNext(temp);
			N->setPrev(nullptr);
			temp->setPrev(N);
			m_Front = N;
		}
		else if(N->getName() > temp->getName())
		{
			temp->setNext(N);
			N->setPrev(temp);
			N->setNext(nullptr);
		}
		else
		{
			N->setNext(temp);
			Node<char *> * temp2 = m_Front;
			while(temp2->getNext() != temp)
			{
				temp2 = temp2->getNext();
			}
			temp->setPrev(N);
			temp2->setNext(N);
			N->setPrev(temp2);
			temp2 = nullptr;
			delete temp2;
		}
		temp = nullptr;
		delete temp;
	
	}	
//	m_size += 1;	
}
