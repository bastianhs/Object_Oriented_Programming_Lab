#include "RestoranRamen.hpp"

// Menambah jumlah order yang dipesan oleh meja n, dengan harga p
// Jika meja sudah diisi maka akan menambah total yang telah dipesan
void RestoranRamen::tambahOrder(int n, int p)
{
    if (daftarMeja.find(n) == daftarMeja.end())
    {
        daftarMeja.insert(pair<int, int>(n, p));
    }
    else
    {
        daftarMeja[n] += p;
    }
}

// Mengembalikan total harga pesanan pada meja n, menghapus entri untuk meja tersebut
int RestoranRamen::tutupOrder(int n)
{
    int totalHarga = daftarMeja[n];
    daftarMeja.erase(n);
    return totalHarga;
}

// Mengembalikan total harga pesanan pada meja n
int RestoranRamen::cekTotal(int n)
{
    return daftarMeja[n];
}

// Mengembalikan jumlah meja yang terisi saat itu
// Restoran mungkin kosong
int RestoranRamen::totalMeja()
{
    return daftarMeja.size();
}

// Mencetak semua meja yang terisi pada restoran diakhiri dengan new line
// Contoh :
/*
    Meja 1 = 5000
    Meja 2 = 3000
    Meja 4 = 10000
*/
// Jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
void RestoranRamen::cetakMeja()
{
    if (daftarMeja.empty())
    {
        cout << "Restoran kosong" << endl;
    }
    else
    {
        for (map<int, int>::iterator it = daftarMeja.begin(); it != daftarMeja.end(); it++)
        {
            cout << "Meja " << it->first << " = " << it->second << endl;
        }
    }
}
