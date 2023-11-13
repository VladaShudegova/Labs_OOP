#include "List.h"
#include "Node.h"

enum Errors_and_Exceptions
{
	/* Для Node */

	/* Для List */
	errorArraySizeLessZero,
	errorArrayAdressNotPassed,
	errorNumberOfListElementsWasPassedIncorrectly,
	errorElementIndexWasPassedIncorrectly,
};

/* Конструктор по умолчанию */
List::List()
{
	m_Head = NULL;
	m_Tail = NULL;
}

/* Конструктор с параметром */
List::List(int arraySize)
{
	if (arraySize < 0)
	{
		throw errorArraySizeLessZero;
	}

	else if (arraySize == 0)
	{
		m_Head = NULL;
		m_Tail = NULL;
	}

	else
	{
		Node* pointer = NULL;
		pointer = new Node(rand());
		m_Head = pointer;

		for (int i = 1; i < arraySize; i++, pointer = pointer->Next())
		{
			pointer->Next() = new Node(rand(), pointer);
		}

		m_Tail = pointer;
	}
}

/* Конструктор из массива int */
List::List(int* listArray, int arraySize)
{
	if (!listArray)
	{
		throw errorArrayAdressNotPassed;
	}

	if (arraySize < 0)
	{
		throw errorNumberOfListElementsWasPassedIncorrectly;
	}

	else if (arraySize == 0)
	{
		m_Head = NULL;
		m_Tail = NULL;
	}

	else
	{
		int i = 0;
		Node* pointer = NULL;
		pointer = new Node(listArray[i]);
		m_Head = pointer;

		for (i++; i < arraySize; i++, pointer = pointer->Next())
		{
			pointer->Next() = new Node(listArray[i], pointer);
		}

		m_Tail = pointer;
	}
}

/* Конструктор копирования */
List::List(const List& other)
{
	if (other.m_Head)
	{
		Node* pointerA = other.m_Head;
		Node* pointerB = NULL;

		pointerB = new Node(pointerA->Key());
		m_Head = pointerB;

		for (pointerA = pointerA->Next(); pointerA; pointerA = pointerA->Next(), pointerB = pointerB->Next())
		{
			pointerB->Next() = new Node(pointerA->Key(), pointerB);
		}

		m_Tail = pointerB;
	}

	else
	{
		m_Head = NULL;
		m_Tail = NULL;
	}
}

/* Деструктор */
List:: ~List()
{
	Node* pointer = m_Head;

	if (pointer)
	{
		while (pointer->Next())
		{
			pointer = pointer->Next();
			delete pointer->Previous();
		}

		delete pointer;
	}
}

/* Потоковый вывод */
ostream& operator << (ostream& os, List& list)
{
	Node* pointer = list.m_Head;

	while (pointer)
	{
		os << pointer->Key() << " ";

		pointer = pointer->Next();
	}

	return os;
}

/* Потоковый ввод */
istream& operator >> (istream& is, List& list)
{
	Node* pointer = list.m_Head;
	int number;

	while (pointer)
	{
		is >> number;

		pointer->Key() = number;
		pointer = pointer->Next();
	}

	return is;
}

/* Поиск элемента по ключу */
Node* List::searchKeyElement(int key)
{
	if (m_Head) {
		Node* pointer = m_Head->Next();
		for (; pointer != m_Tail; pointer = pointer->Next())
		{
			if (key == pointer->Key())
			{
				return pointer;
			}
		}
	}
	return nullptr;

}

int List::min() {
	if (m_Head) {
		Node* pointer = m_Head->Next();
		int minEl = m_Head->Key();
		if (m_Head->Next()) {
			for (; pointer != m_Tail; pointer = pointer->Next())
			{
				if (minEl > pointer->Key())
				{
					minEl = pointer->Key();
				}
			}
			if (minEl > pointer->Key())
			{
				minEl = pointer->Key();
			}
		}
		return minEl;
	}
	return NULL;	//что лучше возвращать в случае пустого списка? Null or -1

}

int List::max() {
	if (m_Head) {
		Node* pointer = m_Head->Next();
		int maxEl = m_Head->Key();
		if (m_Head->Next()) {
			for (; pointer != m_Tail; pointer = pointer->Next())
			{
				if (maxEl < pointer->Key())
				{
					maxEl = pointer->Key();
				}
			}
			if (maxEl < pointer->Key())
			{
				maxEl = pointer->Key();
			}
		}
		return maxEl;
	}
	return NULL;

}

/* Оператор присваивания */
List& List:: operator = (const List& other)
{
	if (this != &other)
	{
		Node* pointer = m_Head;

		while (pointer && pointer->Next())
		{
			pointer = pointer->Next();
			delete pointer->Previous();
		}

		if (pointer)
		{
			delete pointer;
		}

		Node* pointerA = other.m_Head;
		Node* pointerB = NULL;

		pointerB = new Node(pointerA->Key());
		m_Head = pointerB;

		for (pointerA = pointerA->Next(); pointerA; pointerA = pointerA->Next(), pointerB = pointerB->Next())
		{
			pointerB->Next() = new Node(pointerA->Key(), pointerB);
		}

		m_Tail = pointerB;
	}

	return *this;
}

/* Получение ссылки на ключ элемента */
int& List:: operator[] (int keyElement)
{
	Node* pointer = m_Head;
	int i;

	for (i = 0; pointer && i < keyElement; pointer = pointer->Next(), i++);

	if ((i == keyElement) && pointer)
	{
		return pointer->Key();
	}

	else
	{
		throw errorElementIndexWasPassedIncorrectly;
	}
}

/* Оператор сравнения (проверка на равенство) */
bool List:: operator == (const List other)
{
	Node* pointerA = m_Head;
	Node* pointerB = other.m_Head;

	for (; pointerA && pointerB && (pointerA->Key()) == (pointerB->Key()); pointerA = pointerA->Next(), pointerB = pointerB->Next());

	if (pointerA || pointerB)
	{
		return false;
	}

	return true;
}


List List::operator + (const List other) {
	if (other.m_Head == NULL) {
		return *this;
	}
	Node* pointer = m_Head;
	for (; pointer != m_Tail; pointer = pointer->Next());
	
	Node* pointerO = other.m_Head;
	pointer->Next() = new Node(pointerO->Key());

	for (pointer; pointerO; pointerO = pointerO->Next(), pointer = pointer->Next())
		{
			pointer->Next() = new Node(pointerO->Key(), pointer);
		}
	
	m_Tail = pointer;

	return *this;
}



/* Ввод списка */
void List::inputList(int arraySize)
{
	Node* pointer = m_Head;

	if (pointer)
	{
		while (pointer->Next())
		{
			pointer = pointer->Next();
			delete pointer->Previous();
		}

		delete pointer;
	}

	m_Head = NULL;
	m_Tail = NULL;

	if (arraySize < 0)
	{
		throw errorArraySizeLessZero;
	}

	else if (arraySize > 0)
	{
		cout << "Вводите список: ";
		int number;
		cin >> number;

		pointer = new Node(number);
		m_Head = pointer;

		for (int i = 1; i < arraySize; i++, pointer = pointer->Next())
		{
			cin >> number;
			pointer->Next() = new Node(number, pointer);
		}

		m_Tail = pointer;
	}
}

/* Вывод списка */
void List::printList()
{
	Node* pointer = m_Head;

	while (pointer)
	{
		cout << pointer->Key() << " ";
		pointer = pointer->Next();
	}
}

/* Очистка списка */
void List::clearList()
{
	Node* pointer = m_Head;

	if (pointer)
	{
		while (pointer->Next())
		{
			pointer = pointer->Next();
			delete pointer->Previous();
		}

		delete pointer;
	}

	m_Head = NULL;
	m_Tail = NULL;
}


