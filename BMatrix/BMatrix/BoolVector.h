#pragma once
#include <fstream> 
using std::ostream;
using std::istream;




class BoolVector
{
private:
    unsigned char* m_bv;                   
    int m_lenBV;            
    int m_memoryBV;            
  
public:
    BoolVector();                                                
    BoolVector(int lenght_BV, int fillingMethod = 0);            
    BoolVector(const char* string_BV, int lenght_BV);           
    BoolVector(const BoolVector&);                            

    ~BoolVector();                                              

    void setOne(int necessaryBit, int lenght_BV = 1);              
    void setZero(int necessaryBit, int lenght_BV = 1);             
    void inverseComponent(int necessaryBit, int lenght_BV = 1);    
    int size() const { return m_memoryBV * 8; }
    int weight() const;

    int operator[](const int) const;                                            

    BoolVector& operator<<=(const int shiftNumber);                               
    BoolVector operator<<(const int shiftNumber) const;                                 
    BoolVector& operator>>=(const int shiftNumber);                               
    BoolVector operator>>(const int shiftNumber) const;                                 

    BoolVector operator| (BoolVector& other) ;                       
    BoolVector& operator|= ( BoolVector& other);                    
    BoolVector operator& ( BoolVector& other) ;                      
    BoolVector& operator&= ( BoolVector& other);                     
    BoolVector operator ^(const BoolVector& other) const;                      
    BoolVector& operator ^=( BoolVector& other);                     


    BoolVector operator=(const BoolVector& other);
    

    BoolVector operator~ () const;                                    

    friend ostream& operator << (ostream&, BoolVector&);         
    friend istream& operator >> (istream&, BoolVector&);         


};

/* Обработка исключений */
enum Errors_and_Exceprions
{
    /* Для БВ */
    errorLenghtLessZero = 1,
    errorRangeIndexOutBooleanVector,
    errorShiftLenghtLessZero,
    errorWrongSymbol,

    /* Для БМ */
    errorRowOrColumn,
    errorArraySringsNotPassed,
    errorStringAdressIsMissing,
    errorRangeIndexOutBooleanMatrix,
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
    int index_vector = m_memoryBV - 1 - necessaryBit / 8;
    char mask = 1 << (necessaryBit % 8);
    return ((m_bv[index_vector] & mask) >> (necessaryBit % 8)) & 1;
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


