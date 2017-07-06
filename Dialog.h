#ifndef Dialog_h
#define Dialog_h
#include "Highlight.h"
#include "Designs.h"
#include <string>
class Dialog
{
	public:
		Dialog();
		void Chat(int counter, Designs * Des);
		void Boxes(WINDOW * win, const char * chatter, const char * Message);
	private:
		Highlight * H;
		char * Chat0[3] = {"Yes", "No", "I don't know"};
		char * Chat1_2[2] = {"I'm the creator", "I'm a visitor"}; 
		char * Chat2_0[2] = {"I'm not sure", "I have to go"};
		char * Chat2_1[2] = {"Nickname?", "Thank you"};
		char * Chat2_2[2] = {"I have questions", "I have to go"};
		char * Chat3_0[2] = {"The exit?", "Nevermind"};
		char * Chat4_1[2] = {"Of course not", "Traps?"};
		char * Chat5_0[2] = {"I'm going alone", "Any more help?"};
		char * Chat5_1[3] = {"Wasted my time", "No pressure", "That's ok"};
		bool Follow;
		bool TalkedTo1;

};
#endif
