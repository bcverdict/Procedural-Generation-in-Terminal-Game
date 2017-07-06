#ifndef Inventory_h
#define Inventory_h
#include "Node.h"
class Inventory
{
	public:
		Inventory();
		void Add(WINDOW * win, std::string Name);
	private:
		Node<string> * m_Front;
		int m_size;
};
#endif
