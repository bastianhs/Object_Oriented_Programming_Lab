#include "GlassCup.hpp"

/**
 * @return Apakah cangkir kaca masih dapat digunakan?
 */
bool GlassCup::is_usable()
{
    return Glass::is_usable();
}

/**
 * Mengisi air ke dalam cangkir
 *
 * Jika cangkir tidak usable, tidak melakukan apapun
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 * @param type
 */
void GlassCup::fill(int volume, enum WaterType type)
{
    if (is_usable())
    {
        Cup::fill(volume, type);
    }
}

/**
 * Meminum air dari cangkir
 *
 * Jika cangkir tidak usable, tidak melakukan apapun
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 */
void GlassCup::drink(int volume)
{
    if (is_usable())
    {
        Cup::drink(volume);
    }
}

/**
 * Menjatuhkan cangkir dari ketinggian height
 *
 * Mengaplikasikan force sejumlah <height * volume air saat ini>
 * Jika volume air saat ini = 0, mengaplikasikan force hanya sejumlah <height>
 *
 * @param height Dijamin dalam range [0, 100]
 */
void GlassCup::drop(int height)
{
    int water_volume = get_water_volume();
    if (water_volume > 0)
    {
        apply_force(height * water_volume);
    }
    else
    {
        apply_force(height);
    }
}
