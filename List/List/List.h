#define LIST_LIST_H
#include "Node.h"
#include <iostream>
using std::ostream;
using std::istream;
using std::cin;
using std::cout;

/* Класс "Список" */
class List
{
private:
	Node* m_Head;
	Node* m_Tail;

public:
	List();																// Конструктор по умолчанию
	List(int arraySize);												// Конструктор с параметром (формирование списка из n случайных чисел)
	List(int* listArray, int arraySize);								// Конструктор из массива int
	List(const List& other);											// Конструктор копирования

	~List();															// Деструктор

	friend ostream& operator << (ostream& os, List& list);				// Потоковый вывод
	friend istream& operator >> (istream& is, List& list);				// Потоковый ввод

	Node* searchKeyElement(int key);									// Поиск элемента по ключу

	void addToHead(int necessaryElement);								// Добавление элемента (в голову)
	void addToTail(int necessaryElement);								// Добавление элемента (в голову)

	void deleteTail();													// Удаление элемента (с хвоста)
	void deleteHead();													// Удаление элемента (с хвоста)

	int min();
	int max();

	List& operator = (const List& other);								// Оператор присваивания

	int& operator [] (int keyElement);									// Получение ссылки на ключ элемента

	bool operator == (const List other);								// Оператор сравнения (проверка на равенство)
	bool operator != (const List other);								// Оператор сравнения (проверка на неравенство)

	List operator + (const List other);
	bool isEmpty();														// Проверка списка на пустоту

	void inputList(int arraySize);										// Ввод списка (из n элементов)
	void printList();													// Вывод списка

	void clearList();	// Очистка списка
	
};


/* Оператор сравнения (проверка на неравенство) */
inline bool List:: operator != (const List other)
{
	if (*this == other)
	{
		return false;
	}

	return true;
}


/* Проверка списка на пустоту */
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

/* Удаление элемента (с хвоста) */
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


/* Удаление элемента (с хвоста) */
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


/* Добавление элемента (в голову) */
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

/* Добавление элемента (в хвост) */
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