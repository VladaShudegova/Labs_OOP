#pragma once
#include <fstream> 
using std::ostream;
using std::istream;

class BoolVector
{
private:
    unsigned char* m_bv;                   // ��
    int m_lenBv;            // ����� ��
    int m_memoryBv;            // ���������� ���������� ������

public:
    BoolVector();                                                // ����������� �� ���������
    BoolVector(int lenght_BV, int fillingMethod = 0);            // ����������� � ����������� ������� � �������� ��� ���� ��������
    BoolVector(const char* string_BV, int lenght_BV);            // ����������� char* �� ������� � ������
    BoolVector(const BoolVector&);                            // ����������� �����������

    ~BoolVector();                                               // ����������

    void setOne(int necessaryBit, int lenght_BV = 1);               // ���������� 1 � ����������� ����
    void setZero(int necessaryBit, int lenght_BV = 1);              // ���������� 0 � ����������� ����
    void inverseComponent(int necessaryBit, int lenght_BV = 1);     // �������� ������������ ����

    int operator[](int);                                            // ��������� ����������

    BoolVector& operator<<=(int);                                // ��������� ����� ����� (� �����������)
    BoolVector operator<<(int);                                  // ��������� ����� �����
    BoolVector& operator>>=(int);                                // ��������� ����� ������ (� �����������)
    BoolVector operator>>(int);                                  // ��������� ����� ������ 

    BoolVector operator| (BoolVector&);                       // ��������� ���
    BoolVector& operator|= (BoolVector&);                     // ��������� ��� (� �����������) 
    BoolVector operator& (BoolVector&);                       // ��������� �
    BoolVector& operator&= (BoolVector&);                     // ��������� � (� �����������) 
    BoolVector operator ^(BoolVector&);                       // ���������� ����������� ���
    BoolVector& operator ^=(BoolVector&);                     // ���������� ����������� ��� (� �����������)


    BoolVector operator=(const BoolVector& other);
    

    BoolVector& operator~ ();                                    // ��������� ��

    friend ostream& operator << (ostream&, BoolVector&);         // ��������� ����
    friend istream& operator >> (istream&, BoolVector&);         // ��������� ������


};

