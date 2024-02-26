#include "Penganan.hpp"
#include <iostream>

using std::cout;
using std::endl;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
Penganan::Penganan()
{
    this->keik = 0;
    this->panekuk = 0;
}

// ctor dengan parameter
Penganan::Penganan(int keik, int panekuk)
{
    this->keik = keik;
    this->panekuk = panekuk;
}

// mengembalikan bagian jumlah keik
int Penganan::GetKeik() const
{
    return this->keik;
}

// mengembalikan bagian jumlah panekuk
int Penganan::GetPanekuk() const
{
    return this->panekuk;
}

// mengisi bagian keik
void Penganan::SetKeik(int keik)
{
    this->keik = keik;
}

// mengisi bagian panekuk
void Penganan::SetPanekuk(int panekuk)
{
    this->panekuk = panekuk;
}

// operator overloading

// operator+
Penganan operator+(const Penganan &penganan1, const Penganan &penganan2)
{
    Penganan penganan3;
    penganan3.SetKeik(penganan1.GetKeik() + penganan2.GetKeik());
    penganan3.SetPanekuk(penganan1.GetPanekuk() + penganan2.GetPanekuk());
    Penganan::n_rumah++;
    return penganan3;
}

// operator-
Penganan operator-(const Penganan &pengananStok, const Penganan &pengananBeli)
{
    const int hargaKeik = 51;
    const int hargaPanekuk = 37;

    Penganan pengananSisa;

    int selisihKeik = pengananStok.GetKeik() - pengananBeli.GetKeik();
    if (selisihKeik >= 0)
    {
        pengananSisa.SetKeik(selisihKeik);
        Penganan::uang += pengananBeli.GetKeik() * hargaKeik;
    }
    else
    {
        Penganan::uang += pengananStok.GetKeik() * hargaKeik;
    }

    int selisihPanekuk = pengananStok.GetPanekuk() - pengananBeli.GetPanekuk();
    if (selisihPanekuk >= 0)
    {
        pengananSisa.SetPanekuk(selisihPanekuk);
        Penganan::uang += pengananBeli.GetPanekuk() * hargaPanekuk;
    }
    else
    {
        Penganan::uang += pengananStok.GetPanekuk() * hargaPanekuk;
    }

    return pengananSisa;
}

// operator^
Penganan operator^(const Penganan &pengananStok, const int n)
{
    const int hargaKeik = 51;
    const int hargaPanekuk = 37;

    Penganan pengananSisa;

    int selisihKeik = pengananStok.GetKeik() - n;
    if (selisihKeik >= 0)
    {
        pengananSisa.SetKeik(selisihKeik);
    }
    else
    {
        Penganan::uang += selisihKeik * hargaKeik;
    }

    int selisihPanekuk = pengananStok.GetPanekuk() - n;
    if (selisihPanekuk >= 0)
    {
        pengananSisa.SetPanekuk(selisihPanekuk);
    }
    else
    {
        Penganan::uang += selisihPanekuk * hargaPanekuk;
    }

    return pengananSisa;
}

// operator^ (sifat komutatif)
Penganan operator^(const int n, const Penganan &pengananStok)
{
    const int hargaKeik = 51;
    const int hargaPanekuk = 37;

    Penganan pengananSisa;

    int selisihKeik = pengananStok.GetKeik() - n;
    if (selisihKeik >= 0)
    {
        pengananSisa.SetKeik(selisihKeik);
    }
    else
    {
        Penganan::uang += selisihKeik * hargaKeik;
    }

    int selisihPanekuk = pengananStok.GetPanekuk() - n;
    if (selisihPanekuk >= 0)
    {
        pengananSisa.SetPanekuk(selisihPanekuk);
    }
    else
    {
        Penganan::uang += selisihPanekuk * hargaPanekuk;
    }

    return pengananSisa;
}

// mengembalikan jumlah uang yang diperoleh
int Penganan::JumlahUang()
{
    return uang;
}

// mengembalikan jumlah kunjungan ke rumah
int Penganan::HitungNRumah()
{
    return n_rumah;
}

// mencetak isi kantong
// Jangan lupa tambahkan endline di akhir print
// Contoh:
// 0keik-0panekuk
// 111keik-122panekuk
void Penganan::Print()
{
    cout << this->keik << "keik-" << this->panekuk << "panekuk" << endl;
}
