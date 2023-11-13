#include "Node.h"


/*  онструктор по умолчанию (и с аргументом) */
Node::Node(int key, Node* previous, Node* next)
{
    m_Key = key;
    m_Previous = previous;
    m_Next = next;
}

/*  */
int& Node::Key()
{
    return m_Key;
}

/*  */
Node*& Node::Previous()
{
    return m_Previous;
}

/*  */
Node*& Node::Next()
{
    return m_Next;
}
