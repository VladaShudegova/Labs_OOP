#pragma once

/* Класс "Узел списка" */
class Node
{
private:
    int m_Key;				// Ключ
    Node* m_Previous;		// Предыдущий
    Node* m_Next;			// Следующий

public:
    Node(int key = 0, Node* previous = 0, Node* next = 0);				// Конструктор по умолчанию (и с аргументом)
    int& Key();															//
    Node*& Previous();													//
    Node*& Next();														//
};



