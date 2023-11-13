#include "BoolVector.h"
#include <cmath>
#include <cstring> 
#include <iostream> 


BoolVector::BoolVector(int lenght_BV, int fillingMethod)
{
    if (lenght_BV <= 0)
    {
        throw errorLenghtLessZero;
    }

    m_lenBV = lenght_BV;
    m_memoryBV = (m_lenBV + 7) / 8;
    m_bv = new unsigned char[m_memoryBV];

    if (fillingMethod == 0)
    {
        for (int i = 0; i < m_memoryBV; i++)
        {
            m_bv[i] = 0;
        }
    }

    else if (fillingMethod == 1)
    {
        for (int i = 0; i < m_memoryBV - 1; i++)
        {
            m_bv[i + 1] = pow(2, 8) - 1;
        }

        if (m_lenBV % 8 == 0)
        {
            m_bv[0] = pow(2, 8) - 1;
        }

        else
        {
            m_bv[0] = 0;
            m_bv[0] = ~m_bv[0];
            m_bv[0] = m_bv[0] >> (8 - m_lenBV % 8);
        }
    }

    else
    {
        m_bv[0] = 0;

        for (int i = 0; i < m_lenBV; i++)
        {
            if ((rand() % 2) == 1)
            {
                setOne(i);
            }

            else
            {
                setZero(i);
            }
        }
    }
}

BoolVector::BoolVector(const char* string_BV, int lenght_BV)
{
    int i;
    int nextString = strlen(string_BV);

    m_lenBV = lenght_BV;
    m_memoryBV = (m_lenBV + 7) / 8;
    m_bv = new unsigned char[m_memoryBV];

    for (i = 0; i < m_memoryBV; i++)
    {
        m_bv[i] = 0;
    }

    if (nextString >= m_lenBV)
    {
        i = m_lenBV - 1;
    }

    else
    {
        i = nextString - 1;
    }

    for (int k = 0; i >= 0; i--, k++)
    {
        if (string_BV[i] == '1')
        {
            setOne(k);
        }
    }
}



BoolVector::BoolVector(const BoolVector& bv)
{
    m_lenBV = bv.m_lenBV;
    m_memoryBV = bv.m_memoryBV;
    m_bv = new unsigned char[m_memoryBV];

    for (int i = 0; i < m_memoryBV; i++)
    {
        m_bv[i] = bv.m_bv[i];
    }
}



BoolVector& BoolVector:: operator<<=(int shiftBit)
{
    if (shiftBit < 0)
    {
        throw errorShiftLenghtLessZero;
    }

    int i;
    int k;
    for (i = m_lenBV - 1 - shiftBit, k = m_lenBV - 1; i >= 0; i--, k--)
    {
        if (operator[](i) == 1)
        {
            setOne(k);
        }

        else
        {
            setZero(k);
        }
    }

    for (k; k >= 0; k--)
    {
        setZero(k);
    }

    return *this;
}

BoolVector BoolVector:: operator<< (int shiftBit)
{
    BoolVector result(*this);
    result <<= shiftBit;

    return result;
}

BoolVector& BoolVector:: operator>>=(int shiftBit)
{
    if (shiftBit < 0)
    {
        throw errorShiftLenghtLessZero;
    }

    int i;
    int k;
    for (i = shiftBit, k = 0; i < m_lenBV; i++, k++)
    {
        if (operator[](i) == 1)
        {
            setOne(k);
        }

        else
        {
            setZero(k);
        }
    }

    for (k; k < m_lenBV; k++)
    {
        setZero(k);
    }

    return *this;
}

BoolVector BoolVector:: operator>> (int shiftBit)
{
    BoolVector result(*this);
    result >>= shiftBit;

    return result;
}


BoolVector BoolVector:: operator | (BoolVector& lenght_BV)
{
    BoolVector* min;
    BoolVector* max;

    int i;
    int k;

    if (m_lenBV > lenght_BV.m_lenBV)
    {
        min = &lenght_BV;
        max = this;
    }

    else
    {
        min = this;
        max = &lenght_BV;
    }

    BoolVector result(*max);

    for (i = min->m_memoryBV - 1, k = result.m_memoryBV - 1; i >= 0; i--, k--)
    {
        result.m_bv[k] |= min->m_bv[i];
    }

    return result;
}


BoolVector BoolVector:: operator & (BoolVector& lenght_BV)
{
    BoolVector* min;
    BoolVector* max;

    int i;
    int k;

    if (m_lenBV > lenght_BV.m_lenBV)
    {
        min = &lenght_BV;
        max = this;
    }

    else
    {
        min = this;
        max = &lenght_BV;
    }

    BoolVector result(*max);

    for (i = min->m_memoryBV - 1, k = result.m_memoryBV - 1; i >= 0; i--, k--)
    {
        result.m_bv[k] &= min->m_bv[i];
    }

    for (i = 0; i < max->m_memoryBV - min->m_memoryBV; i++)
    {
        result.m_bv[i] = 0;
    }

    return result;
}



BoolVector& BoolVector::operator ~()
{
    int nmem = (m_lenBV + 7) / 8;

    for (int i = m_memoryBV - 1; i >= m_memoryBV - nmem; i--)
    {
        m_bv[i] = ~m_bv[i];
    }

    unsigned char mask = (~0) << ((m_lenBV - 1) % 8 + 1);
    m_bv[m_memoryBV - nmem] = m_bv[m_memoryBV - nmem] & (~mask);

    return *this;
}

BoolVector BoolVector:: operator ^ (BoolVector& lenght_BV)
{
    if (m_memoryBV > lenght_BV.m_memoryBV)
    {
        BoolVector result(*this);

        for (int i = 0; i < lenght_BV.m_memoryBV; i++)
        {
            result.m_bv[i + m_memoryBV - lenght_BV.m_memoryBV] ^= lenght_BV.m_bv[i];
        }

        return result;
    }

    else
    {
        BoolVector result(lenght_BV);

        for (int i = 0; i < m_memoryBV; i++)
        {
            result.m_bv[i + lenght_BV.m_memoryBV - m_memoryBV] ^= m_bv[i];
        }

        return result;
    }
}




ostream& operator << (ostream& os, BoolVector& lenght_BV)
{
    for (int i = lenght_BV.m_lenBV - 1; i >= 0; i--)
    {
        if ((lenght_BV[i]) == 1)
        {
            os << " 1";
        }

        else
        {
            os << " 0";
        }
    }

    return os;
}

istream& operator >> (istream& is, BoolVector& lenght_BV)
{
    std::cout << "Lenght vector: ";
    is >> lenght_BV.m_lenBV;

    if (lenght_BV.m_lenBV <= 0)
    {
        throw errorLenghtLessZero;
    }

    std::cout << "Input vector: ";
    char* s = new char[lenght_BV.m_lenBV];
    lenght_BV.m_memoryBV = (lenght_BV.m_lenBV + 7) / 8;
    lenght_BV.m_bv = new unsigned char[lenght_BV.m_memoryBV];

    char c;
    for (int i = lenght_BV.m_lenBV - 1; i >= 0; i--)
    {
        is >> c;

        if (c == '0')
        {
            lenght_BV.setZero(i);
        }

        else
        {
            lenght_BV.setOne(i);
        }
    }

    return is;
}


BoolVector BoolVector::operator=(const BoolVector& other)
{
    if (this == &other) return *this;

    if (m_lenBV != other.m_lenBV)
    {
        delete[] m_bv;
        m_bv = new unsigned char[other.m_lenBV];
        m_lenBV = other.m_lenBV;
        m_memoryBV = other.m_memoryBV;

    }
    m_lenBV = other.m_lenBV;

    for (int i = 0; i < m_lenBV; ++i)
    {
        m_bv[i] = other.m_bv[i];
    }
    return *this;
}

