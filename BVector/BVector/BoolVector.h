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

enum Errors_and_Exceprions
{
    errorLenghtLessZero = 1,
    errorRangeIndexOutBooleanVector,
    errorShiftLenghtLessZero,
};

inline BoolVector::BoolVector()
{
    m_lenBv = 0;
    m_memoryBv = 1;
    m_bv = new unsigned char[m_memoryBv];
}

inline BoolVector::~BoolVector()
{
    delete[] m_bv;
    m_bv = NULL;
}


inline void BoolVector::setOne(int necessaryBit, int lenght_BV)
{
    for (; lenght_BV > 0; necessaryBit++, lenght_BV--)
    {
        if (lenght_BV >= m_lenBv || lenght_BV < 0)
        {
            throw errorRangeIndexOutBooleanVector;
        }

        int indexBit;
        int positionBit;
        unsigned char mask = 1;
        indexBit = m_memoryBv - necessaryBit / 8 - 1;
        positionBit = necessaryBit % 8;
        m_bv[indexBit] |= (mask << positionBit);
    }
}

inline void BoolVector::setZero(int necessaryBit, int lenght_BV)
{
    for (; lenght_BV > 0; necessaryBit++, lenght_BV--)
    {
        if (necessaryBit >= m_lenBv || necessaryBit < 0)
        {
            throw errorRangeIndexOutBooleanVector;
        }

        int indexBit;
        int positionBit;
        unsigned char mask = 1;
        indexBit = m_memoryBv - necessaryBit / 8 - 1;
        positionBit = necessaryBit % 8;
        m_bv[indexBit] &= ~(mask << positionBit);
    }
}

inline void BoolVector::inverseComponent(int necessaryBit, int lenght_BV)
{
    for (; lenght_BV > 0; necessaryBit++, lenght_BV--)
    {
        if (necessaryBit < 0 || necessaryBit >= m_lenBv)
        {
            throw errorRangeIndexOutBooleanVector;
        }

        if (operator[](necessaryBit) == 0)
        {
            setOne(necessaryBit);
        }

        else
        {
            setZero(necessaryBit);
        }
    }
}


inline int BoolVector::operator[] (int necessaryBit)
{
    if (necessaryBit >= m_lenBv || necessaryBit < 0)
    {
        throw errorRangeIndexOutBooleanVector;
    }

    int indexBit;
    int positionBit;
    unsigned char mask = 1;
    indexBit = m_memoryBv - necessaryBit / 8 - 1;
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

inline BoolVector& BoolVector::operator ^= (BoolVector& lenght_BV)
{
    (*this) = ((*this) ^ lenght_BV);

    return *this;
}


