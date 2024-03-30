#include "Walikota.hpp"
#include <iostream>

using namespace std;

/*
    Membuat objek Walikota dengan jumlah default kayu, gulden, dan pekerja
*/
Walikota::Walikota()
{
    kayu = DEFAULT_KAYU;
    gulden = DEFAULT_GULDEN;
    pekerja = DEFAULT_PEKERJA;
}

/*
    Membuat objek Walikota dengan jumlah kayu, gulden, pekerja, dan bangunan sesuai argumen.
*/
Walikota::Walikota(int kayu, int gulden, int pekerja)
{
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja;
}

/*
    Menghancurkan objek walikota
*/
Walikota::~Walikota() {}

/*
    Membangun bangunan baru sesuai nama yang diberikan. Metode ini menggunakan metode pakaiKayu, pakaiGulden, perkejakanPekerja secara urut. Untuk membuat satu bangunan, akan menghabiskan kayu dan gulden sesuai input dan akan dialokasikan 1 pekerja.

    Bangunan gagal dibangun apabila:
    1. Kayu habis. Keluarkan pesan dari exception ditambah dengan ", beli kayu dulu."
    2. Gulden habis. Keluarkan pesan dari exception ditambah dengan ", tagih pajak dulu."
    3. Tidak ada pekerja. Keluarkan pesan dari exception ditambah dengan ", rekrut pekerja dulu."

    Jika gagal dibangun, jumlah kayu, gulden, dan pekerja tidak berkurang. Gunakan metode batalPakaiKayu, batalPakaiGulden, dan batalkanPekerja.

    Jika berhasil, masukkan bangunan ke daftar bangunan dengan metode push_back(Bangunan b) dari vector. Selain itu, tampilkan pesan "Bangunan [<nomor_bangunan>] <nama_bangunan> berhasil dibangun". Untuk mengetahui panjang list saat ini gunakan metode size()

    (semua output ditambah newline)
*/
void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden)
{
    try
    {
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();
        bangunan.push_back(Bangunan(namaBangunan));
        cout << "Bangunan [" << bangunan.size() << "] " << namaBangunan << " berhasil dibangun" << '\n';
    }
    catch (const KayuTidakCukupException &e)
    {
        cout << e.what() << ", beli kayu dulu." << '\n';
    }
    catch (const GuldenTidakCukupException &e)
    {
        cout << e.what() << ", tagih pajak dulu." << '\n';
        batalPakaiKayu(kayu);
    }
    catch (const PekerjaTidakCukupException &e)
    {
        cout << e.what() << ", rekrut pekerja dulu." << '\n';
        batalPakaiKayu(kayu);
        batalPakaiGulden(gulden);
    }
}

/*
    Menambahkan kayu sesuai num
*/
void Walikota::tambahKayu(int num)
{
    kayu += num;
}

/*
    Menambahkan gulden sesuai num
*/
void Walikota::tambahGulden(int num)
{
    gulden += num;
}

/*
    Menambahkan pekerja sesuai num
*/
void Walikota::tambahPekerja(int num)
{
    pekerja += num;
}

/*
    Menggunakan kayu sesuai num

    Lemparkan exception KayuTidakCukupException jika kayu tidak cukup. Kayu tidak digunakan.
*/
void Walikota::pakaiKayu(int num)
{
    if (kayu < num)
    {
        throw KayuTidakCukupException();
    }

    kayu -= num;
}

/*
    Menggunakan gulden sesuai num

    Lemparkan exception GuldenTidakCukupException jika gulden tidak cukup. Gulden tidak digunakan.
*/
void Walikota::pakaiGulden(int num)
{
    if (gulden < num)
    {
        throw GuldenTidakCukupException();
    }

    gulden -= num;
}

/*
    Mempekerjakan 1 pekerja

    Lemparkan exception PekerjaTidakCukupException jika pekerja tidak cukup. Pekerja batal bekerja.
*/
void Walikota::pekerjakanPekerja()
{
    if (pekerja < 1)
    {
        throw PekerjaTidakCukupException();
    }

    --pekerja;
}

/*
    Membatalkan penggunaan kayu sesuai num
*/
void Walikota::batalPakaiKayu(int num)
{
    kayu += num;
}

/*
    Membatalkan penggunaan gulden sesuai num
*/
void Walikota::batalPakaiGulden(int num)
{
    gulden += num;
}

/*
    Membatalkan 1 pekerja
*/
void Walikota::batalkanPekerja()
{
    ++pekerja;
}

/*
    Menyebut bangunan pada index idx. Gunakan metode at(int idx) untuk mengakses bangunan. Tampilkan "<nama_bangunan>" jika idx valid.

    Tampilkan exception yang dilemparkan c++ ketika idx tidak valid. Akhiri dengan newline.
*/
void Walikota::sebutBangunan(int idx)
{
    try
    {
        cout << bangunan.at(idx).getNamaBangunan() << '\n';
    }
    catch (const exception &e)
    {
        cout << e.what() << '\n';
    }
}

/*
    Menampilkan status kota dengan format:

    Status
      Kayu: <jumlah_kayu>
      Gulden: <jumlah_gulden>
      Pekerja: <jumlah_pekerja>
      Bangunan:
        Bangunan[i]: <nama_bangunan>
*/
void Walikota::statusKota()
{
    cout << "Status" << '\n';
    cout << "  Kayu: " << kayu << '\n';
    cout << "  Gulden: " << gulden << '\n';
    cout << "  Pekerja: " << pekerja << '\n';
    cout << "  Bangunan:" << '\n';
    int i = 0;
    for (vector<Bangunan>::iterator it = bangunan.begin(); it != bangunan.end(); ++it)
    {
        cout << "Bangunan[" << ++i << "]: " << it->getNamaBangunan() << '\n';
    }
}
