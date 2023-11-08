#include "BoolVector.h"
#include <cmath>
#include <cstring> 
#include <iostream> 

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

BoolVector::BoolVector(int lenght_BV, int fillingMethod)
{
    if (lenght_BV <= 0)
    {
        throw errorLenghtLessZero;
    }

    m_lenBv = lenght_BV;
    m_memoryBv = (m_lenBv + 7) / 8;
    m_bv = new unsigned char[m_memoryBv];

    if (fillingMethod == 0)
    {
        for (int i = 0; i < m_memoryBv; i++)
        {
            m_bv[i] = 0;
        }
    }

    else if (fillingMethod == 1)
    {
        for (int i = 0; i < m_memoryBv - 1; i++)
        {
            m_bv[i + 1] = pow(2, 8) - 1;
        }

        if (m_lenBv % 8 == 0)
        {
            m_bv[0] = pow(2, 8) - 1;
        }

        else
        {
            m_bv[0] = 0;
            m_bv[0] = ~m_bv[0];
            m_bv[0] = m_bv[0] >> (8 - m_lenBv % 8);
        }
    }

    else
    {
        m_bv[0] = 0;

        for (int i = 0; i < m_lenBv; i++)
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

    m_lenBv = lenght_BV;
    m_memoryBv = (m_lenBv + 7) / 8;
    m_bv = new unsigned char[m_memoryBv];

    for (i = 0; i < m_memoryBv; i++)
    {
        m_bv[i] = 0;
    }

    if (nextString >= m_lenBv)
    {
        i = m_lenBv - 1;
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
    m_lenBv = bv.m_lenBv;
    m_memoryBv = bv.m_memoryBv;
    m_bv = new unsigned char[m_memoryBv];

    for (int i = 0; i < m_memoryBv; i++)
    {
        m_bv[i] = bv.m_bv[i];
    }
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


BoolVector& BoolVector:: operator<<=(int shiftBit)
{
    if (shiftBit < 0)
    {
        throw errorShiftLenghtLessZero;
    }

    int i;
    int k;
    for (i = m_lenBv - 1 - shiftBit, k = m_lenBv - 1; i >= 0; i--, k--)
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
    for (i = shiftBit, k = 0; i < m_lenBv; i++, k++)
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

    for (k; k < m_lenBv; k++)
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

    if (m_lenBv > lenght_BV.m_lenBv)
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

    for (i = min->m_memoryBv - 1, k = result.m_memoryBv - 1; i >= 0; i--, k--)
    {
        result.m_bv[k] |= min->m_bv[i];
    }

    return result;
}

inline BoolVector& BoolVector::operator |= (BoolVector& lenght_BV)
{
    (*this) = ((*this) | lenght_BV);

    return *this;
}

BoolVector BoolVector:: operator & (BoolVector& lenght_BV)
{
    BoolVector* min;
    BoolVector* max;

    int i;
    int k;

    if (m_lenBv > lenght_BV.m_lenBv)
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

    for (i = min->m_memoryBv - 1, k = result.m_memoryBv - 1; i >= 0; i--, k--)
    {
        result.m_bv[k] &= min->m_bv[i];
    }

    for (i = 0; i < max->m_memoryBv - min->m_memoryBv; i++)
    {
        result.m_bv[i] = 0;
    }

    return result;
}

inline BoolVector& BoolVector::operator &= (BoolVector& lenght_BV)
{
    (*this) = ((*this) & lenght_BV);

    return *this;
}


BoolVector& BoolVector::operator ~()
{
    int nmem = (m_lenBv + 7) / 8;

    for (int i = m_memoryBv - 1; i >= m_memoryBv - nmem; i--)
    {
        m_bv[i] = ~m_bv[i];
    }

    unsigned char mask = (~0) << ((m_lenBv - 1) % 8 + 1);
    m_bv[m_memoryBv - nmem] = m_bv[m_memoryBv - nmem] & (~mask);

    return *this;
}

BoolVector BoolVector:: operator ^ (BoolVector& lenght_BV)
{
    if (m_memoryBv > lenght_BV.m_memoryBv)
    {
        BoolVector result(*this);

        for (int i = 0; i < lenght_BV.m_memoryBv; i++)
        {
            result.m_bv[i + m_memoryBv - lenght_BV.m_memoryBv] ^= lenght_BV.m_bv[i];
        }

        return result;
    }

    else
    {
        BoolVector result(lenght_BV);

        for (int i = 0; i < m_memoryBv; i++)
        {
            result.m_bv[i + lenght_BV.m_memoryBv - m_memoryBv] ^= m_bv[i];
        }

        return result;
    }
}

inline BoolVector& BoolVector::operator ^= (BoolVector& lenght_BV)
{
    (*this) = ((*this) ^ lenght_BV);

    return *this;
}


ostream& operator << (ostream& os, BoolVector& lenght_BV)
{
    for (int i = lenght_BV.m_lenBv - 1; i >= 0; i--)
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
    is >> lenght_BV.m_lenBv;

    if (lenght_BV.m_lenBv <= 0)
    {
        throw errorLenghtLessZero;
    }

    std::cout << "Input vector: ";
    char* s = new char[lenght_BV.m_lenBv];
    lenght_BV.m_memoryBv = (lenght_BV.m_lenBv + 7) / 8;
    lenght_BV.m_bv = new unsigned char[lenght_BV.m_memoryBv];

    char c;
    for (int i = lenght_BV.m_lenBv - 1; i >= 0; i--)
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

    if (m_lenBv != other.m_lenBv)
    {
        delete[] m_bv;
        m_bv = new unsigned char[other.m_lenBv];
        m_lenBv = other.m_lenBv;
        m_memoryBv = other.m_lenBv;

    }
    m_lenBv = other.m_lenBv;

    for (int i = 0; i < m_lenBv; ++i)
    {
        m_bv[i] = other.m_bv[i];
    }
    return *this;
}
