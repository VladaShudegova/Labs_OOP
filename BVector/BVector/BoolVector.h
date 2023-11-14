#pragma once
#include <fstream> 
using std::ostream;
using std::istream;




class BoolVector
{
private:
    unsigned char* m_bv;                   // ��
    int m_lenBV;            // ���������� ��������� � ��
    int m_memoryBV;            // ���������� ���������� ������
  
public:
    BoolVector();                                                // ����������� �� ���������
    BoolVector(int lenght_BV, int fillingMethod = 0);            // ����������� � ����������� ������� � �������� ��� ���� ��������
    BoolVector(const char* string_BV, int lenght_BV);            // ����������� char* �� ������� � ������
    BoolVector(const BoolVector&);                            // ����������� �����������

    ~BoolVector();                                               // ����������

    void setOne(int necessaryBit, int lenght_BV = 1);               // ���������� 1 � ����������� ����
    void setZero(int necessaryBit, int lenght_BV = 1);              // ���������� 0 � ����������� ����
    void inverseComponent(int necessaryBit, int lenght_BV = 1);     // �������� ������������ ����
    int size() const { return m_memoryBV * 8; }
    int weight() const;

    int operator[](const int) const;                                            // ��������� ����������

    BoolVector& operator<<=(const int shiftNumber);                                // ��������� ����� ����� (� �����������)
    BoolVector operator<<(const int shiftNumber) const;                                  // ��������� ����� �����
    BoolVector& operator>>=(const int shiftNumber);                                // ��������� ����� ������ (� �����������)
    BoolVector operator>>(const int shiftNumber) const;                                  // ��������� ����� ������ 

    BoolVector operator| (BoolVector& other) ;                       // ��������� ���
    BoolVector& operator|= ( BoolVector& other);                     // ��������� ��� (� �����������) 
    BoolVector operator& ( BoolVector& other) ;                       // ��������� �
    BoolVector& operator&= ( BoolVector& other);                     // ��������� � (� �����������) 
    BoolVector operator ^(const BoolVector& other) const;                       // ���������� ����������� ���
    BoolVector& operator ^=( BoolVector& other);                     // ���������� ����������� ��� (� �����������)


    BoolVector operator=(const BoolVector& other);
    

    BoolVector operator~ () const;                                    // ��������� ��

    friend ostream& operator << (ostream&, BoolVector&);         // ��������� ����
    friend istream& operator >> (istream&, BoolVector&);         // ��������� ������


};

enum Errors_and_Exceprions
{
    errorLenghtLessZero = 1,
    errorRangeIndexOutBooleanVector,
    errorShiftLenghtLessZero,
};

inline BoolVector::BoolVector()
{
    m_lenBV = 0;
    m_memoryBV = 1;
    m_bv = new unsigned char[m_memoryBV];
}

inline BoolVector::~BoolVector()
{
    delete[] m_bv;
    m_bv = NULL;
}


inline int BoolVector::operator[] (int necessaryBit) const
{
    if (necessaryBit >= m_lenBV || necessaryBit < 0)
    {
        throw errorRangeIndexOutBooleanVector;
    }

    int indexBit;
    int positionBit;
    unsigned char mask = 1;
    indexBit = m_memoryBV - necessaryBit / 8 - 1;
    positionBit = necessaryBit % 8;

    if (m_bv[indexBit] & (mask << positionBit))
    {
        return 1;
    }

    return 0;
}




inline BoolVector& BoolVector::operator |= (BoolVector& lenght_BV)
{
    (*this) = ((*this) | lenght_BV);

    return *this;
}


inline BoolVector& BoolVector::operator &= (BoolVector& lenght_BV)
{
    (*this) = ((*this) & lenght_BV);

    return *this;
}

inline BoolVector& BoolVector::operator ^= ( BoolVector& lenght_BV) 
{
    (*this) = ((*this) ^ lenght_BV);

    return *this;
}


