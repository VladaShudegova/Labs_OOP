#pragma once
#include <fstream> 
using std::ostream;
using std::istream;

class BoolVector
{
private:
    unsigned char* m_bv;                   // БВ
    int m_lenBv;            // Длина БВ
    int m_memoryBv;            // Количество выделенной памяти

public:
    BoolVector();                                                // Конструктор по умолчанию
    BoolVector(int lenght_BV, int fillingMethod = 0);            // Конструктор с параметрами размера и значения для всех разрядов
    BoolVector(const char* string_BV, int lenght_BV);            // Конструктор char* со строкой и числом
    BoolVector(const BoolVector&);                            // Конструктор копирования

    ~BoolVector();                                               // Деструктор

    void setOne(int necessaryBit, int lenght_BV = 1);               // Установить 1 в определённом бите
    void setZero(int necessaryBit, int lenght_BV = 1);              // Установить 0 в определённом бите
    void inverseComponent(int necessaryBit, int lenght_BV = 1);     // Инверсия определённого бита

    int operator[](int);                                            // Получение компоненты

    BoolVector& operator<<=(int);                                // Побитовый сдвиг влево (с присвоением)
    BoolVector operator<<(int);                                  // Побитовый сдвиг влево
    BoolVector& operator>>=(int);                                // Побитовый сдвиг вправо (с присвоением)
    BoolVector operator>>(int);                                  // Побитовый сдвиг вправо 

    BoolVector operator| (BoolVector&);                       // Побитовое ИЛИ
    BoolVector& operator|= (BoolVector&);                     // побитовое ИЛИ (с присвоением) 
    BoolVector operator& (BoolVector&);                       // Побитовое И
    BoolVector& operator&= (BoolVector&);                     // Побитовое И (с присвоением) 
    BoolVector operator ^(BoolVector&);                       // Побитовове исключающее ИЛИ
    BoolVector& operator ^=(BoolVector&);                     // Побитовове исключающее ИЛИ (с присвоением)


    BoolVector operator=(const BoolVector& other);
    

    BoolVector& operator~ ();                                    // Побитовое НЕ

    friend ostream& operator << (ostream&, BoolVector&);         // Потоковый ввод
    friend istream& operator >> (istream&, BoolVector&);         // Потоковый ввывод


};

