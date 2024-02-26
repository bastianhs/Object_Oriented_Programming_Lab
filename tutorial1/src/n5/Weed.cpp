#include "Weed.hpp"

Weed::Weed()
{
    // Membuat Weed dengan jumlah kawanan 1
    this->many = 1;
}

Weed::Weed(int n)
{
    // Membuat Weed dengan jumlah kawanan n
    if (1 <= n && n <= 1000)
    {
        this->many = n;
    }
}

Weed::Weed(const Weed &b)
{
    this->many = b.many;
}

Weed::~Weed() {}

void Weed::step()
{
    // Menghasilkan bunyi "kresek..." berulang
    // sebanyak n kawanan
    for (int i = 0; i < this->many; i++)
    {
        std::cout << "kresek...";
    }

    std::cout << std::endl;
}
