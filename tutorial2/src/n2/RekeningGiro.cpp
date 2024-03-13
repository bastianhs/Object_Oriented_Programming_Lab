#include "RekeningGiro.h"

// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double saldo, double sukuBunga) : Rekening(saldo)
{
    if (sukuBunga < 0)
    {
        this->sukuBunga = 0.0;
    }
    else
    {
        this->sukuBunga = sukuBunga;
    }
}

// Getter, Setter

void RekeningGiro::setSukuBunga(double sukuBunga)
{
    this->sukuBunga = sukuBunga;
}

double RekeningGiro::getSukuBunga() const
{
    return this->sukuBunga;
}

// Member Function

// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga()
{
    return getSaldo() * this->sukuBunga;
}
