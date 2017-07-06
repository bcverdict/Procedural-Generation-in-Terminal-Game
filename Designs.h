#ifndef Designs_h
#define Designs_h
#include "Node.h"
#include "Highlight.h"
#include <vector>
class Designs
{
	public:
		Designs();
		void Title();
		void Guides(int i);
		int VecPrint(WINDOW * win);
		void Add(const char * File, char * Name);
		void Print(WINDOW * win);
		int getSize();
	private:
		Node<char *> * m_Front;
		vector<char *> VecList;
		int m_size;
		Highlight * H;
		bool Exit;
};
#endif
