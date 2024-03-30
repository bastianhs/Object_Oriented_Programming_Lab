#include "Restaurant.hpp"

/*
    Constructor untuk membuat restaurant
    Order kosong
*/
Restaurant::Restaurant() {}

/*
    Destructor
*/
Restaurant::~Restaurant() {}

/*
    Menambahkan satu order makanan sejumlah val menu

    Contoh:
    Order = (3, 4, 5)
    val = 2

    Maka order = (2, 3, 4, 5)
*/
void Restaurant::Push(int val)
{
    order.push(val);
}

/*
    Memproses order makanan sebanyak val
    Apabila val lebih banyak dari jumlah order makanan yang ada, keluarkan "Proses tidak valid"
    dan tidak ada order makanan yang diproses

    Contoh:
    Order = (3, 4, 5)
    val = 2

    maka order = (5)
*/
void Restaurant::Pop(int val)
{
    if (val > order.size())
    {
        cout << "Proses tidak valid" << '\n';
    }
    else
    {
        for (int i = 0; i < val; ++i)
        {
            order.pop();
        }
    }
}

/*
    Menambahkan k order makanan paling akhir diproses sejumlah val menu
    Apabila k lebih besar dari banyaknya order makanan, tambahkan semua order makan sejumlah val menu

    Contoh:
    Order = (1, 2, 3)
    k = 2, val = 3

    maka order = (1, 5, 6)
*/
void Restaurant::AddMenu(int k, int val)
{
    stack<int> tempOrder;
    const int orderSize = order.size();
    for (int i = 0; i < orderSize; ++i)
    {
        tempOrder.push(order.top());
        order.pop();
    }

    for (int i = 0; i < orderSize; ++i)
    {
        if (i < k)
        {
            order.push(tempOrder.top() + val);
        }
        else
        {
            order.push(tempOrder.top());
        }

        tempOrder.pop();
    }
}

/*
    Memutar urutan pemrosesan k order makanan paling bawah
    Contoh:
    k = 3
    order =  1 2 3 4 5 (1 merupakan order makanan paling atas untuk diproses)

    Hasil
    order = 1 2 5 4 3

    Jika k > jumlah order, putar seluruh urutan order makanan
*/
void Restaurant::Reorder(int k)
{
    stack<int> tempOrder;

    const int orderSize = order.size();
    for (int i = 0; i < orderSize; ++i)
    {
        tempOrder.push(order.top());
        order.pop();
    }

    stack<int> tempOrder2;

    for (int i = 0; i < orderSize && i < k; ++i)
    {
        tempOrder2.push(tempOrder.top());
        tempOrder.pop();
    }

    const int tempOrder2Size = tempOrder2.size();
    for (int i = 0; i < tempOrder2Size; ++i)
    {
        order.push(tempOrder2.top());
        tempOrder2.pop();
    }

    const int tempOrderSize = tempOrder.size();
    for (int i = 0; i < tempOrderSize; ++i)
    {
        order.push(tempOrder.top());
        tempOrder.pop();
    }
}

/*
    Mencetak order makanan pada restaurant dimulai dari paling awal diproses
    Contoh = (1, 2, 3, 4, 5)
    Apabila order kosong cetak ()
*/
ostream &operator<<(ostream &out, Restaurant restaurant)
{
    out << '(';

    const int orderSize = restaurant.order.size();
    for (int i = 0; i < orderSize; ++i)
    {
        out << restaurant.order.top();
        if (i < orderSize - 1)
        {
            out << ", ";
        }
        restaurant.order.pop();
    }

    out << ")\n";
    return out;
}
