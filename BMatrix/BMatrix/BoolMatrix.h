#pragma once
#include "BoolVector.h"
class BoolMatrix
{

private:
    BoolVector* m_BM;            // БМ
    int m_Row_BM;                   // Строки БМ
    int m_Column_BM;                // Столбцы БМ

public:
    BoolMatrix();                                                // Конструктор по умолчанию
    BoolMatrix(int, int, bool);                                  // Конструктор с параметрами
    BoolMatrix(char**, int, int);                                // Конструктор из матрицы char
    BoolMatrix(const BoolMatrix&);                            // Конструктор копирования

    ~BoolMatrix();                                               // Деструктор

    BoolMatrix operator = (const BoolMatrix&);                // Оператор присваивания
    BoolVector& operator [](const int);                          // Получение строки

    friend istream& operator>>(istream&, BoolMatrix&);           // Потоковый ввод
    friend ostream& operator<<(ostream&, const BoolMatrix&);     // Потоковый вывод

    BoolVector rowConjuction() const;                            // Конъюнкция строк
    BoolVector rowDisjunction() const;                           // Дизъюнкция строк

    BoolMatrix operator & (const BoolMatrix&) const;          // Конъюнкция матрицы
    BoolMatrix& operator &= (const BoolMatrix&);              // Конъюнкция матрицы (с присванием) 
    BoolMatrix operator | (const BoolMatrix&) const;          // Дизъюнкция матрицы
    BoolMatrix& operator |= (const BoolMatrix&);              // дизъюнкция матрицы (с присвоением) 

    int weightBM() const;                                           // Вес БМ

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

