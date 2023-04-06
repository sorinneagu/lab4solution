#pragma once
#include<string>
#include<iostream>


class BigInteger {
private:

    char* pBigNr = nullptr;
    char sign = 0;
    int size = 0;

    void trimStartingZeros(const std::string& number, int startIndex, int& outFirstNonZero);
public:
    BigInteger() = default;
    BigInteger(const std::string& number);
    BigInteger(const BigInteger& other);
    BigInteger& operator=(const BigInteger& other);
    ~BigInteger();

    int compare(const BigInteger& other);
    char sgn() const;

    bool operator==(const BigInteger& other);
    bool operator<(const BigInteger& other);
    bool operator<=(const BigInteger& other);
    bool operator>(const BigInteger& other);
    bool operator>=(const BigInteger& other);

};
