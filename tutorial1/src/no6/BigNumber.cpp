#include "BigNumber.hpp"
#include <iostream>
using namespace std;

const int BigNumber::max_digit = 20;

BigNumber::BigNumber()
{
    this->digit = new int[BigNumber::max_digit];
}

BigNumber::BigNumber(int number)
{
    this->digit = new int[BigNumber::max_digit];
    for (int i = 0; i < BigNumber::max_digit; i++)
    {
        this->digit[i] = number % 10;
        number /= 10;
    }
}

BigNumber::BigNumber(string aVeryBigNumber)
{
    this->digit = new int[BigNumber::max_digit];
    int strSize = aVeryBigNumber.size();
    for (int i = 0; i < strSize; i++)
    {
        this->digit[i] = aVeryBigNumber[strSize - 1 - i] - '0';
    }
}

BigNumber::BigNumber(const BigNumber &bn)
{
    this->digit = new int[BigNumber::max_digit];
    for (int i = 0; i < BigNumber::max_digit; i++)
    {
        this->digit[i] = bn[i];
    }
}

int BigNumber::getMaxDigit()
{
    return BigNumber::max_digit;
}

void BigNumber::setDigit(int i, int digit)
{
    this->digit[i] = digit;
}

int &BigNumber::operator[](int i)
{
    return this->digit[i];
}

int BigNumber::operator[](int i) const
{
    return this->digit[i];
}

BigNumber::~BigNumber()
{
    delete[] this->digit;
}

// hint   : gunakan operator overload [] untuk mengakses digit
// contoh : other[i]
// hint   : untuk this, dapat langsung menggunakan this->digit[i]
bool BigNumber::operator==(const BigNumber &other)
{
    bool result = true;
    int i = BigNumber::getMaxDigit() - 1;
    while (i >= 0 && result)
    {
        // implementasikan disini
        if (this->digit[i] != other.digit[i])
        {
            result = false;
        }
        else
        {
            i--;
        }
    }

    return result;
}

bool BigNumber::operator<(const BigNumber &other)
{
    bool stop = false;
    int i = BigNumber::getMaxDigit() - 1;
    while (i >= 0 && !stop)
    {
        // implementasikan disini
        if (this->digit[i] != other.digit[i])
        {
            stop = true;
        }
        else
        {
            i--;
        }
    }

    return this->digit[i] < other.digit[i];
}

bool BigNumber::operator>(const BigNumber &other)
{
    bool stop = false;
    int i = BigNumber::getMaxDigit() - 1;
    while (i >= 0 && !stop)
    {
        // implementasikan disini
        if (this->digit[i] != other.digit[i])
        {
            stop = true;
        }
        else
        {
            i--;
        }
    }

    return this->digit[i] > other.digit[i];
}

BigNumber BigNumber::operator+(const BigNumber &other)
{
    BigNumber c;
    // hint: gunakan operator overload [] untuk mengakses dan mengubah digit
    // contoh:
    // - c[i] = this->digit[i]
    // - c[i] = other[i]
    int carry = 0;
    for (int i = 0; i < BigNumber::getMaxDigit(); i++)
    {
        // implementasikan disini
        int sumOfDigit = this->digit[i] + other[i] + carry;
        if (sumOfDigit < 10)
        {
            c[i] = sumOfDigit;
            carry = 0;
        }
        else
        {
            c[i] = sumOfDigit % 10;
            carry = 1;
        }
    }

    return c;
}
