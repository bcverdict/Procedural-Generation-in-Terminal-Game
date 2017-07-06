#ifndef NODE_H
#define NODE_H
#include <ncurses.h>
#include <string>
using namespace std;
template<typename T>
class Node
{
	public:
		Node();
		void setName(T Name);
		void setFile(const char * File);
		void setNext(Node<T> * Next);
		void setPrev(Node<T> * Prev);
		T getName();
		Node<T> * getNext();
		Node<T> * getPrev();

	private:
	T m_Name;
	const char * m_File;
	Node<T> * m_Next;
	Node<T> * m_Prev;
};
#include "Node.hpp"
#endif

