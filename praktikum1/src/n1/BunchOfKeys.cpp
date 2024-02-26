#include "BunchOfKeys.hpp"

// ctor
BunchOfKeys::BunchOfKeys()
{
    this->n_keys = 0;
}

// member function
void BunchOfKeys::add()
{
    this->n_keys++;
}

void BunchOfKeys::shake()
{
    if (this->n_keys <= 1)
    {
        cout << "Tidak terjadi apa-apa" << endl;
    }
    else
    {
        for (int i = 0; i < this->n_keys; i++)
        {
            cout << "krincing" << endl;
        }
    }
}
