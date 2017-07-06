#include "Node.h"
using namespace std;

template<typename T>
Node<T>::Node()
{
	m_Name = "";
}
template<typename T>
void Node<T>::setName(T Name)
{
	m_Name = Name;
}
template<typename T>
void Node<T>::setFile(const char * File)
{
	m_File = File;
}
template<typename T>
void Node<T>::setNext(Node<T> * Next)
{
	m_Next = Next;
} 
template<typename T>
void Node<T>::setPrev(Node<T> * Prev)
{
	m_Prev = Prev;
}
template<typename T>
T Node<T>::getName()
{
	return(m_Name);
}

template<typename T>
Node<T> * Node<T>::getNext()
{
	return(m_Next);
}
template<typename T>
Node<T> * Node<T>::getPrev()
{
	return(m_Prev);
}

