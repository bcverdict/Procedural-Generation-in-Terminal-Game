#include "Inventory.h"
using namespace std;
Inventory::Inventory()
{
	m_Front = nullptr;
	m_size = 0;
}
void Inventory::Add(WINDOW * win, string Name)
{
	Node<string> * N = new Node<string>();
	N->setName(Name);
	if(m_size == 0)
	{
		m_Front = N;
		N->setNext(nullptr);
	}
	else if(m_size == 1)
	{
		if(N->getName() < m_Front->getName())
		{
			N->setNext(m_Front);
			m_Front = N;
		}
		else
		{
			m_Front->setNext(N);
			N->setNext(nullptr);
		}
	}
	else
	{
		Node<string> * temp = m_Front;
		while((N->getName() > temp->getName())&&(temp->getNext() != nullptr))
		{
			temp = temp->getNext();
		}
		if(temp == m_Front)
		{
			N->setNext(temp);
			m_Front = N;
		}
		else if(N->getName() > temp->getName())
		{
			temp->setNext(N);
			N->setNext(nullptr);
		}
		else
		{
			N->setNext(temp);
			Node<string> * temp2 = m_Front;
			while(temp2->getNext() != temp)
			{
				temp2 = temp2->getNext();
			}
			temp2->setNext(N);
			temp2 = nullptr;
			delete temp2;
		}
		temp = nullptr;
		delete temp;
	}
}
