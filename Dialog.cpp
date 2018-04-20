#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include "Dialog.h"
using namespace std;

Dialog::Dialog()
{
	Follow = false;
	TalkedTo1 = false;
	H = new Highlight();
}
void Dialog::Chat(int counter, Designs * Des)
{
	initscr();
	noecho();
	WINDOW * dialog = newwin(5, 95, 43, 35);
	refresh();
	WINDOW * choices = newwin(5, 20, 43, 130);
	refresh();
	int scroll = 0;
	switch(counter)
	{
		case 1:
		{
			if(!(TalkedTo1))
			{
				box(dialog, 0, 0);
				box(choices, 0, 0);
				mvwprintw(dialog, 0, 1, "????:");
				mvwprintw(dialog, scroll + 1, 1, "Can I help you?");
				wrefresh(dialog);
				wrefresh(choices);
				int Pick = H->print_menu(choices, Chat0, 3);
				wclear(choices);	
				box(choices, 0, 0);
				wrefresh(choices);
				if(Pick == 0)
				{
					Boxes(dialog, "Name:", "Yes actually. I'm a bit lost. I'm just trying to find a way out.");
					Boxes(dialog, "????:", "Hmm? Are you the creator or a visitor?");
					Pick = H->print_menu(choices, Chat1_2, 2);
					wclear(choices);	
					box(choices, 0, 0);
					wrefresh(choices);
					if(Pick == 0)
					{
						Boxes(dialog, "Name:", "I'm the creator but I seem to have missplaced the exit. I figured you might know the way?");
						Boxes(dialog, "????:", "It's very unlike you to missplace anything. I hope you're feeling ok. Did you arm the traps?");
						Pick = H->print_menu(choices, Chat2_0, 2);
						wclear(choices);	
						box(choices, 0, 0);
						wrefresh(choices);
						if(Pick == 0)
						{
							Boxes(dialog, "????:", "You're not sure!? Really? You're not sure? Name, you built a closing wall not 10 steps away!");
							Boxes(dialog, "Name:", "Ok...Well how would you suggest I get passed it?");
							Boxes(dialog, "????:", "You are truly crazy. *sigh* Well the wall comes from the left. Anything it touches will be deleted. I can't come. But be carefull.");
						}
						else if(Pick == 1)
						{
							Boxes(dialog, "????:", "...whatever you say creator");
						}
					}
					else if(Pick == 1)
					{
						Boxes(dialog, "Name:", "I'm a visitor. I came alone but I didn't expect to get lost. Any help would be much appriciated.");
						Boxes(dialog, "????:", "WELL FEAR NOT! Your loyal and new found friend is hear to help! My name is h^W#89m2@ and you can count on me to get you out.");
						Pick = H->print_menu(choices, Chat2_1, 2);
						wclear(choices);	
						box(choices, 0, 0);
						wrefresh(choices);
						if(Pick == 0)
						{
							Boxes(dialog, "Name:", "Do you have a nickname I can call you by maybe?");
							Boxes(dialog, "h^W#89m2@:", "Actually yes. The creator alway called me Brody. I'm not sure exactly why but he did say it was easier to remember.");
							Boxes(dialog, "Name:", "Brody. Cool. Well after you then Brody.");
							Boxes(dialog, "Brody:", "Oh...well I didn't mean to misslead. But I can't come with you.");
							Pick = H->print_menu(choices, Chat5_1, 3);
							wclear(choices);
							box(choices, 0, 0);
							wrefresh(choices);
							if(Pick == 0)
							{
								Boxes(dialog, "Name:", "Well at least I now know that you aren't totally useless. You can be used as a bad example. How can you even help me? Was your job just to confuse visitors? Who would make something like you?");
								Boxes(dialog, "Name:", "Thanks for wasting my times");
								Boxes(dialog, "Brody:", "...");
							}
							else if(Pick == 1)
							{
								Boxes(dialog, "Name:", "Brody...no preasure...but I realy need you to PLEASE give me some good news here.");
								Boxes(dialog, "Brody:", "Uhhhmmm...well the trap comes from the left? It's a wall. You have to get over the wall to make it stop...I can't remember much else. This is a lot of pressure.");
								Boxes(dialog, "Name:", "That's alright. I'll be on my way now. Thanks for the tip.");
							}
							else if(Pick == 2)
							{
								Boxes(dialog, "Name:", "That's alright. I didn't expact you too. But can you help me in anyway? I don't really know much about this place.");
								Boxes(dialog, "Brody:", "Actually yes! I almost forgot! The creator left me with a guide for a time like this!");
								Des->Guides(1);
								Boxes(dialog, "Name:", "Alright! Thank you Brody. I'll be on my way");
								Boxes(dialog, "Brody:", "Good luck!");
							}

						}
						else if(Pick == 1)
						{
							Boxes(dialog, "Name:", "Thanks. Lead the way");
							Boxes(dialog, "Brody:", "Oh...Well here's the thing. I can't exactly come with you. There are traps setup everywhere. But I know how to get through them.");
							Boxes(dialog, "Brody:", "The first trap is 10 steps from here. Take this. It's a guide to the first trap. I'll meet you on the other side. Good luck.");
							Des->Guides(1);
						}
						Follow = true;
					}

				}
				else if(Pick == 1)
				{
					Boxes(dialog, "Name:", "No I was just passing by.");
					Boxes(dialog, "????:", "Well ok. See ya later I guess...");
				}
				else if(Pick == 2)
				{
					Boxes(dialog, "Name:", "...I don't know I was just curious what you were.");
					Boxes(dialog, "????:", "Hmm? Are you the creator or a visitor?");
					Pick = H->print_menu(choices, Chat1_2, 2);
					wclear(choices);	
					box(choices, 0, 0);
					wrefresh(choices);
					if(Pick == 0)
					{
						Boxes(dialog, "Name:", "The creator of course. But I don't ever remember creating you.");
						Boxes(dialog, "????:", "--sigh--So you've forget about me then. That's fine. I'm sure you've created a million more of my type since you've last talked to me. My names h^W#89m2@ but you always called me Brody. I don't doubt that the nickname was unrelated though.");
						Pick = H->print_menu(choices, Chat2_2, 2);
						wclear(choices);	
						box(choices, 0, 0);
						wrefresh(choices);
						if(Pick == 0)
						{
							Boxes(dialog, "Name:", "I just have some questions.");
							Boxes(dialog, "Brody:", "Ask away.");
							Pick = H->print_menu(choices, Chat3_0, 2);
							wclear(choices);	
							box(choices, 0, 0);
							wrefresh(choices);
							if(Pick == 0)
							{
								Boxes(dialog, "Name:", "I seem to have missplaced the exit. Do you know where I can find it?");
								Boxes(dialog, "Brody:", "Hmm. The creater missplaces the exit. That really is worrisome. You didn't missplace the traps as well did you?");
								Pick = H -> print_menu(choices, Chat4_1, 2);
								wclear(choices);
								box(choices, 0, 0);
								wrefresh(choices);
								if(Pick == 0)
								{
									Boxes(dialog, "????:", "Well good. Then just keep going forawrd and I'm sure you'll find it.");
								}
								else if(Pick == 1)
								{
									Boxes(dialog, "????:", "You've got to be kidding me...CREATOR!?");
									Boxes(dialog, "Name:", "WHAT!?");
									Boxes(dialog, "????:", "WHAT DO YOU MEAN WHAT!? YOU BUILT A CLOSING WALL THAT ERASES EVERTHING IT TOUCHES!");
									Boxes(dialog, "Name:", "And how would one get around that?");
									Boxes(dialog, "????:","...you run...fast...");
									Boxes(dialog, "Name:", "...I guess I'll be on my way then...");
									Boxes(dialog, "????:", "You really are a piece of work you know that.");
								}
							}
							else if(Pick == 1)
							{
								Boxes(dialog, "Name:", "Nevermind...");
								Boxes(dialog, "????:", "Well. I at least hope you forgot about the exit before you forgot about me. Good luck with your creation.");
							}
						}
						else if(Pick == 1)
						{
							Boxes(dialog, "Name:", "Alright well I'll be leaving now. See you later Brody.");
							Boxes(dialog, "Brody:", "Whatever you say creator...whatever you say.");
						}
					}
					else if(Pick == 1)
					{
						Boxes(dialog, "Name:", "I'm a visitor I suppose. I'm a bit lost and I'm just trying to find my way out again. If you could maybe just point me in the right direction that'd be great.");
						Boxes(dialog, "????:", "OH! Well this is exciting! You're our first visitor. My names h^W#89m2@. I haven't tried to get out myself but I know the way!. But I must warn you, It's going to be dangerous.");
						Boxes(dialog, "Name:", "Why dangerous?");
						Boxes(dialog, "h^W#89m2@", "There are a few traps here and there...BUT don't even worry because I've got your back! And I've never been caught in a single trap.");
						Boxes(dialog, "Name:", "So you've gone through them before?");
						Boxes(dialog, "h^W#89m2@", "...don't worry about me! Haha haha...");
						Pick = H->print_menu(choices, Chat5_0, 2);
						wclear(dialog);
						box(dialog, 0, 0);
						wrefresh(dialog);
					       if(Pick == 0)
					       {
							Boxes(dialog, "Name:", "You know what, I think I'll be good on my own.");
					 		Boxes(dialog, "h^W#89m2@", "Are you sure? Let me help!");
							Boxes(dialog, "Name:", "I'll be fine.");
						}
					       else if(Pick == 1)
					       {
						       Boxes(dialog, "Name:", "Is there anymore you cann give me? Anything?");
						       Boxes(dialog, "h^W#89m2@", "Oh! I almost forgot! Here!");
						       Des->Guides(1);
					       }
					}		
				}
				TalkedTo1 = true;
				wclear(dialog);
				wrefresh(dialog);
				wclear(choices);
				wrefresh(choices);
			}
			break;
		}
		case 2:
		{
			Boxes(dialog, "????:", "You made a mistake coming here. If he finds us...");
			Boxes(dialog, "Name:", "If who finds us?");
			Boxes(dialog, "????:", "The creater. Who else!?");
			Boxes(dialog, "Name:", "...");
			Boxes(dialog, "????:", "I don't know if you have one where you come from, but I wouldn't be too happy if someone made a mess of my world.");
			Boxes(dialog, "????:", "...get away from me...");
			wclear(dialog);
			wrefresh(dialog);
			break;
		}
	}
}
void Dialog::Boxes(WINDOW * win, const char * chatter, const char * Message)
{
	wclear(win);
	box(win, 0, 0);
	mvwprintw(win, 0, 1, chatter);

	string S(Message);
	int size = S.size();
	int counter = 1;
	while(size > 92)
	{	
		string Extra = "";
		for(int i = 0; i < 92; i++)
		{
			Extra +=S[i];
		}
		Message = Extra.c_str();
		mvwprintw(win, counter, 1, Message);
		counter += 1;
		S.erase(0, 92);
		size = S.size();
		Message = S.c_str();
	}
	mvwprintw(win, counter, 1, Message);
	mvwprintw(win, 4, 85, "<<Enter>>");
	wrefresh(win);

	int c = getch();
	while(c != 10)
	{
		c = getch();
	}
}
