#pragma once

/* ����� "���� ������" */
class Node
{
private:
    int m_Key;				// ����
    Node* m_Previous;		// ����������
    Node* m_Next;			// ���������

public:
    Node(int key = 0, Node* previous = 0, Node* next = 0);				// ����������� �� ��������� (� � ����������)
    int& Key();															//
    Node*& Previous();													//
    Node*& Next();														//
};



