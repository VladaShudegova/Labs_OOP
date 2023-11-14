#include "BoolMatrix.h"
#include <iostream>



BoolMatrix::BoolMatrix()
{
    m_Row_BM = 8;
    m_Column_BM = 8;
    m_BM = new BoolVector[m_Row_BM];

    for (int i = 0; i < m_Row_BM; ++i)
    {
        m_BM[i] = BoolVector(m_Column_BM, 0);
    }
}


BoolMatrix::BoolMatrix(int row, int column, bool value)
{
    if (row <= 0 || column <= 0)
    {
        throw errorRowOrColumn;
    }

    m_Row_BM = row;
    m_Column_BM = column;
    m_BM = new BoolVector[m_Row_BM];

    for (int i = 0; i < m_Row_BM; ++i)
    {
        m_BM[i] = BoolVector(m_Column_BM, value);
    }
}


BoolMatrix::BoolMatrix(char** string_BM, int row, int column)
{
    if (!string_BM)
    {
        throw errorArraySringsNotPassed;
    }

    if (row <= 0 || column <= 0)
    {
        throw errorRowOrColumn;
    }

    m_Row_BM = row;
    m_Column_BM = column;
    m_BM = new BoolVector[m_Row_BM];

    for (int i = 0; i < m_Row_BM; i++)
    {
        if (!(string_BM[i]))
        {
            throw errorStringAdressIsMissing;
        }

        BoolVector bm(string_BM[i], m_Column_BM);
        m_BM[i] = bm;
    }
}

BoolMatrix::BoolMatrix(const BoolMatrix& other)
{
    m_Row_BM = other.m_Row_BM;
    m_Column_BM = other.m_Column_BM;
    m_BM = new BoolVector[m_Row_BM];

    for (int i = 0; i < m_Row_BM; i++)
    {
        m_BM[i] = other.m_BM[i];
    }
}


BoolMatrix::~BoolMatrix()
{
    delete[] m_BM;
}

BoolMatrix BoolMatrix:: operator = (const BoolMatrix& other)
{
    if (this != &other)
    {
        if (m_BM)
        {
            delete[] m_BM;
        }

        m_Row_BM = other.m_Row_BM;
        m_Column_BM = other.m_Column_BM;
        m_BM = new BoolVector[m_Row_BM];

        for (int i = 0; i < m_Row_BM; i++)
        {
            m_BM[i] = other.m_BM[i];
        }
    }

    return (*this);
}



BoolVector& BoolMatrix:: operator [](const int indexBit)
{
    if (indexBit < 0 || indexBit >= m_Row_BM)
    {
        throw errorRangeIndexOutBooleanMatrix;
    }

    return m_BM[indexBit];
}



istream& operator>>(istream& is, BoolMatrix& bm)
{
    std::cout << "Количество строк: ";
    is >> bm.m_Row_BM;

    std::cout << "Количество столбцов: ";
    is >> bm.m_Column_BM;

    delete[] bm.m_BM;
    bm.m_BM = new BoolVector[bm.m_Row_BM];
    std::cout << "Вводите матрицу:\n";

    for (int i = 0; i < bm.m_Row_BM; i++)
    {
        is >> bm.m_BM[i];
    }

    return is;
}


ostream& operator<<(ostream& os, const BoolMatrix& bm)
{
    for (int i = 0; i < bm.m_Row_BM; i++)
    {
        os << bm.m_BM[i] << std::endl;
    }

    return os;
}

BoolVector BoolMatrix::rowConjuction() const
{
    BoolVector result(m_Column_BM, 1);

    for (int i = 0; i < m_Row_BM; i++)
    {
        result &= m_BM[i];
    }

    return result;
}


BoolVector BoolMatrix::rowDisjunction() const
{
    BoolVector result(m_Column_BM, 0);

    for (int i = 0; i < m_Row_BM; i++)
    {
        result |= m_BM[i];
    }

    return result;
}

BoolMatrix BoolMatrix:: operator & (const BoolMatrix& other) const
{
    const BoolMatrix* min;
    const BoolMatrix* max;

    int maxColumn;

    if (m_Column_BM > other.m_Column_BM)
    {
        maxColumn = m_Column_BM;
    }

    else
    {
        maxColumn = other.m_Column_BM;
    }

    int i;
    int k;

    if (m_Row_BM > other.m_Row_BM)
    {
        min = &other;
        max = this;
    }

    else
    {
        min = this;
        max = &other;
    }

    BoolMatrix result(*max);
    BoolVector saveMax(maxColumn);

    for (i = 0; i < min->m_Row_BM; i++)
    {
        result.m_BM[i] &= min->m_BM[i];
    }

    for (i = min->m_Row_BM; i < max->m_Row_BM; i++)
    {
        result.m_BM[i] = saveMax;
    }

    return result;
}


BoolMatrix BoolMatrix:: operator | (const BoolMatrix& other) const
{
    const BoolMatrix* min;
    const BoolMatrix* max;

    int maxColumn;

    if (m_Column_BM > other.m_Column_BM)
    {
        maxColumn = m_Column_BM;
    }

    else
    {
        maxColumn = other.m_Column_BM;
    }

    int i;
    int k;

    if (m_Row_BM > other.m_Row_BM)
    {
        min = &other;
        max = this;
    }

    else
    {
        min = this;
        max = &other;
    }

    BoolMatrix result(*max);
    BoolVector saveMax(maxColumn);

    for (i = 0; i < min->m_Row_BM; i++)
    {
        result.m_BM[i] |= min->m_BM[i];
    }

    for (i = min->m_Row_BM; i < max->m_Row_BM; i++)
    {
        result.m_BM[i] |= saveMax;
    }

    return result;
}

int BoolMatrix::weightBM() const
{
    int weightBM = 0;

    for (int i = 0; i < m_Row_BM; i++)
    {
        weightBM += m_BM[i].weight();
    }

    return weightBM;
}









