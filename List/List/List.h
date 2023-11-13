#define LIST_LIST_H
#include "Node.h"
#include <iostream>
using std::ostream;
using std::istream;
using std::cin;
using std::cout;

/* ����� "������" */
class List
{
private:
	Node* m_Head;
	Node* m_Tail;

public:
	List();																// ����������� �� ���������
	List(int arraySize);												// ����������� � ���������� (������������ ������ �� n ��������� �����)
	List(int* listArray, int arraySize);								// ����������� �� ������� int
	List(const List& other);											// ����������� �����������

	~List();															// ����������

	friend ostream& operator << (ostream& os, List& list);				// ��������� �����
	friend istream& operator >> (istream& is, List& list);				// ��������� ����

	Node* searchKeyElement(int key);									// ����� �������� �� �����

	void addToHead(int necessaryElement);								// ���������� �������� (� ������)
	void addToTail(int necessaryElement);								// ���������� �������� (� ������)

	void deleteTail();													// �������� �������� (� ������)
	void deleteHead();													// �������� �������� (� ������)

	int min();
	int max();

	List& operator = (const List& other);								// �������� ������������

	int& operator [] (int keyElement);									// ��������� ������ �� ���� ��������

	bool operator == (const List other);								// �������� ��������� (�������� �� ���������)
	bool operator != (const List other);								// �������� ��������� (�������� �� �����������)

	List operator + (const List other);
	bool isEmpty();														// �������� ������ �� �������

	void inputList(int arraySize);										// ���� ������ (�� n ���������)
	void printList();													// ����� ������

	void clearList();	// ������� ������
	
};


/* �������� ��������� (�������� �� �����������) */
inline bool List:: operator != (const List other)
{
	if (*this == other)
	{
		return false;
	}

	return true;
}


/* �������� ������ �� ������� */
inline bool List::isEmpty()
{
	if (m_Head == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}
}

/* �������� �������� (� ������) */
inline void List::deleteHead()
{
	if (m_Head->Next())
	{
		if (m_Head->Next())
		{
			m_Head = m_Head->Next();
			delete m_Head->Previous();
			m_Head->Previous() = 0;
		}

		else
		{
			delete m_Head;
			m_Head = NULL;
			m_Tail = NULL;
		}
	}
}


/* �������� �������� (� ������) */
inline void List::deleteTail()
{
	if (m_Tail)
	{
		if (m_Tail->Previous())
		{
			m_Tail = m_Tail->Previous();
			delete m_Tail->Next();
			m_Tail->Next() = 0;
		}

		else
		{
			delete m_Tail;
			m_Head = NULL;
			m_Tail = NULL;
		}
	}
}


/* ���������� �������� (� ������) */
inline void List::addToHead(int necessaryElement)
{
	if (m_Head)
	{
		m_Head->Previous() = new Node(necessaryElement, 0, m_Head);
		m_Head = m_Head->Previous();
	}

	else
	{
		m_Head = new Node(necessaryElement);
		m_Tail = m_Head;
	}
}

/* ���������� �������� (� �����) */
inline void List::addToTail(int necessaryElement)
{
	if (m_Tail)
	{
		m_Tail->Next() = new Node(necessaryElement, m_Tail, 0);
		m_Tail = m_Tail->Next();
	}

	else
	{
		m_Tail = new Node(necessaryElement);
		m_Head = m_Tail;
	}
}