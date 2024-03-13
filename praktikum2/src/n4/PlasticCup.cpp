#include "PlasticCup.hpp"

/**
 * Cangkir plastik layak digunakan jika plastik masih layak,
 * DAN kandungan microplastic di dalamnya di bawah maximum_microplastics.
 *
 * @return Apakah cangkir plastik masih layak digunakan?
 */
bool PlasticCup::is_usable()
{
    return Plastic::is_usable() && current_microplastics < maximum_microplastics;
}

/**
 * Mengisi air ke dalam cangkir.
 *
 * 1. Kandungan air bertambah.
 * 2. Plastik "digunakan".
 * 3. Microplastic terurai berdasarkan rasio <volume air setelah ditambah / kapasitas maksimum>.
 *    Penguraian microplastic menjadi dua kali lipatnya jika air adalah air panas.
 * 4. Kandungan microplastic bertambah sesuai hasil no. 3
 *
 * Jika cangkir tidak usable, tidak melakukan apapun.
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 * @param type
 */
void PlasticCup::fill(int volume, enum WaterType type)
{
    if (is_usable())
    {
        Cup::fill(volume, type);
        Plastic::use();
        int shreded_microplastics;
        if (type == HOT_WATER)
        {
            shreded_microplastics = 2 * Plastic::shred_microplastics(get_water_volume(), capacity);
        }
        else
        {
            shreded_microplastics = Plastic::shred_microplastics(get_water_volume(), capacity);
        }

        current_microplastics += shreded_microplastics;
    }
}

/**
 * Meminum air dari cangkir.
 *
 * 1. Kandungan air berkurang.
 * 2. Plastik "digunakan".
 * 3. Kandungan microplastic berkurang sejumlah parameter <volume>, bila hasil pengurangan bernilai negatif set nilai kandungan microplastic = 0.
 *
 * Jika cangkir tidak usable, tidak melakukan apapun
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 */
void PlasticCup::drink(int volume)
{
    if (is_usable())
    {
        Cup::drink(volume);
        Plastic::use();
        current_microplastics -= volume;
        if (current_microplastics < 0)
        {
            current_microplastics = 0;
        }
    }
}

/**
 * Menjatuhkan cangkir dari ketinggian height.
 *
 * Kandungan microplastic bertambah sejumlah penguraian microplastic
 * dengan rasio berupa <volume air * height / kapasitas>
 *
 * @param height Dijamin dalam range [0, 100]
 */
void PlasticCup::drop(int height)
{
    current_microplastics += shred_microplastics(get_water_volume() * height, capacity);
}
