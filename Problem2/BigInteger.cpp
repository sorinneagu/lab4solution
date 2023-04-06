#include "BigInteger.h"

#include <cctype> // for isdigit
#include <iostream>
#include <iomanip>
using namespace std;

void BigInteger::trimStartingZeros(const string& number, int startIndex, int& outFirstNonZero)
{
    outFirstNonZero = startIndex;
    for (int i = startIndex; i < number.size() - 1 and number.at(i) == '0'; ++i)
        outFirstNonZero++;
}


BigInteger::BigInteger(const string& number)
{
    int startingIndex = 0;
    sign = 1;
    if (number.at(0) == '-')
    {
        sign = -1;
        startingIndex++;
    }
    else if (number.at(0) == '+')
    {
        sign = 1;
        startingIndex++;
    }
    trimStartingZeros(number, startingIndex, startingIndex);

    int newSize = number.size() - startingIndex;

    pBigNr = new char[newSize];

    size = newSize;

    for (int i = 0; i < size; ++i)
    {
        pBigNr[i] = number.at(size - 1 - i + startingIndex) - '0';
    }

    if (size == 1 and pBigNr[0] == 0)
        sign = 0;

}


BigInteger::BigInteger(const BigInteger& other)
{
    this->size = other.size;
    this->sign = other.sign;

    this->pBigNr = new char[this->size];
    for (int i = 0; i < other.size; ++i)
        this->pBigNr[i] = other.pBigNr[i];

}

BigInteger& BigInteger::operator=(const BigInteger& other)
{
    if (this == &other)
        return *this;

    this->sign = other.sign;
    if (this->size != other.size)
    {
        delete[] this->pBigNr;

        this->size = other.size;
        this->pBigNr = new char[this->size];
    }

    for (int i = 0; i < other.size; ++i)
        this->pBigNr[i] = other.pBigNr[i];

    return *this;
}


BigInteger::~BigInteger()
{
    delete[] pBigNr;
    pBigNr = nullptr;
}

int BigInteger::compare(const BigInteger& other)
{
    if (this->size == 0 and this->pBigNr[0] == 0 and
        other.size == 0 and other.pBigNr[0] == 0)
        return 0;

    if (this->sign == -1 and other.sign == 1)
        return -1;
    else if (this->sign == 1 and other.sign == -1)
        return 1;

    if (this->size < other.size)
        return -1;
    else if (this->size > other.size)
        return 1;
    else
    {
        for (int i = this->size - 1; i >= 0; --i)
        {
            if (this->pBigNr[i] < other.pBigNr[i])
                return -1;
            else if (this->pBigNr[i] > other.pBigNr[i])
                return 1;
        }

        return 0;
    }
}

char BigInteger::sgn() const
{
    return sign;
}

bool BigInteger::operator==(const BigInteger& other)
{
    return this->compare(other) == 0;
}

bool BigInteger::operator<(const BigInteger& other)
{
    return this->compare(other) == -1;
}

bool BigInteger::operator<=(const BigInteger& other)
{
    return *this < other or *this == other;
}

bool BigInteger::operator>(const BigInteger& other)
{
    return this->compare(other) == 1;
}

bool BigInteger::operator>=(const BigInteger& other)
{
    return *this > other or *this == other;
}


