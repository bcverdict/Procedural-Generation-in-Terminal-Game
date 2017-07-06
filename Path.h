#include <string>
#include <fstream>
#include <ncurses.h>
#include "Dialog.h"
#include "Highlight.h"
#include "Designs.h"
#include <string>
#ifndef PATH_H
#define PATH_H
class Path
{
	public:
		Path();
		~Path();
		void MenuSwitch(WINDOW * win, int Screen, int choice);
		void PWindow(char * Menu[3]);
		void Keys();
		void Wall();
		void Update();
		void Sky();
		void TokenKeys();
		void Ground();
		void MovementDown();
		void MovementUp();
		void setArray(int Screen);

	private:
		const char * m_Field[100][100];
		std::string m_Name;
		WINDOW * Playwin;
		int m_FieldRow;
		int m_FieldCol;
		int m_StartRow;
		int m_StartCol;
		int m_Counter;
		int m_ForC;
		int m_SpawnEnemy;
		int m_MenuCounter;
		char * FirstMenu[3] = {"Play", "Help", "Exit"};
		char * SecondMenu[3]={"Fullscreen", "Mini-screen", "Exit to main menu"};
		bool TT1;
		WINDOW * InvWin;
		bool TalkedTo1;
		Dialog * D;
		Highlight * H;
		Designs * Des;

};
#endif
