#pragma once
#include "BoolVector.h"
class BoolMatrix
{

private:
    BoolVector* m_BM;            // ��
    int m_Row_BM;                   // ������ ��
    int m_Column_BM;                // ������� ��

public:
    BoolMatrix();                                                // ����������� �� ���������
    BoolMatrix(int, int, bool);                                  // ����������� � �����������
    BoolMatrix(char**, int, int);                                // ����������� �� ������� char
    BoolMatrix(const BoolMatrix&);                            // ����������� �����������

    ~BoolMatrix();                                               // ����������

    BoolMatrix operator = (const BoolMatrix&);                // �������� ������������
    BoolVector& operator [](const int);                          // ��������� ������

    friend istream& operator>>(istream&, BoolMatrix&);           // ��������� ����
    friend ostream& operator<<(ostream&, const BoolMatrix&);     // ��������� �����

    BoolVector rowConjuction() const;                            // ���������� �����
    BoolVector rowDisjunction() const;                           // ���������� �����

    BoolMatrix operator & (const BoolMatrix&) const;          // ���������� �������
    BoolMatrix& operator &= (const BoolMatrix&);              // ���������� ������� (� ����������) 
    BoolMatrix operator | (const BoolMatrix&) const;          // ���������� �������
    BoolMatrix& operator |= (const BoolMatrix&);              // ���������� ������� (� �����������) 

    int weightBM() const;                                           // ��� ��

};



inline BoolMatrix& BoolMatrix:: operator |= (const BoolMatrix& other)
{
    (*this) = (*this) | other;

    return *this;
}

inline BoolMatrix& BoolMatrix:: operator &= (const BoolMatrix& other)
{
    (*this) = (*this) & other;

    return *this;
}

