#pragma once
#include <fstream> 
using std::ostream;
using std::istream;




class BoolVector
{
private:
    unsigned char* m_bv;                   // БВ
    int m_lenBV;            // количесиво элементов в БВ
    int m_memoryBV;            // Количество выделенной памяти
  
public:
    BoolVector();                                                // Конструктор по умолчанию
    BoolVector(int lenght_BV, int fillingMethod = 0);            // Конструктор с параметрами размера и значения для всех разрядов
    BoolVector(const char* string_BV, int lenght_BV);            // Конструктор char* со строкой и числом
    BoolVector(const BoolVector&);                            // Конструктор копирования

    ~BoolVector();                                               // Деструктор

    void setOne(int necessaryBit, int lenght_BV = 1);               // Установить 1 в определённом бите
    void setZero(int necessaryBit, int lenght_BV = 1);              // Установить 0 в определённом бите
    void inverseComponent(int necessaryBit, int lenght_BV = 1);     // Инверсия определённого бита
    int size() const { return m_memoryBV * 8; }
    int weight() const;

    int operator[](const int) const;                                            // Получение компоненты

    BoolVector& operator<<=(const int shiftNumber);                                // Побитовый сдвиг влево (с присвоением)
    BoolVector operator<<(const int shiftNumber) const;                                  // Побитовый сдвиг влево
    BoolVector& operator>>=(const int shiftNumber);                                // Побитовый сдвиг вправо (с присвоением)
    BoolVector operator>>(const int shiftNumber) const;                                  // Побитовый сдвиг вправо 

    BoolVector operator| (BoolVector& other) ;                       // Побитовое ИЛИ
    BoolVector& operator|= ( BoolVector& other);                     // побитовое ИЛИ (с присвоением) 
    BoolVector operator& ( BoolVector& other) ;                       // Побитовое И
    BoolVector& operator&= ( BoolVector& other);                     // Побитовое И (с присвоением) 
    BoolVector operator ^(const BoolVector& other) const;                       // Побитовове исключающее ИЛИ
    BoolVector& operator ^=( BoolVector& other);                     // Побитовове исключающее ИЛИ (с присвоением)


    BoolVector operator=(const BoolVector& other);
    

    BoolVector operator~ () const;                                    // Побитовое НЕ

    friend ostream& operator << (ostream&, BoolVector&);         // Потоковый ввод
    friend istream& operator >> (istream&, BoolVector&);         // Потоковый ввывод


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


