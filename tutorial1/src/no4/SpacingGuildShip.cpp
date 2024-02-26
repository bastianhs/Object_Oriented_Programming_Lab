#include "SpacingGuildShip.hpp"

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips + 1)
{
    /* Ctor default: jumlah penumpang adalah 0, jumlah Guild Navigator adalah 3,
     * Kapasitas pesawat adalah 50 orang, dan stok spice 50 */
    this->passengerCount = 0;
    this->operatingGuildNavigator = 3;
    this->spiceStock = 50;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips + 1)
{
    /* Ctor jika diketahui jumlah Guild Navigator, kapasitas maksimal pesawat,
     * dan stok spice. Jumlah penumpang 0 */
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &ship) : maxPassengerCap(ship.maxPassengerCap), guildNavigatorCount(ship.guildNavigatorCount), serialNum(producedShips + 1)
{
    /* Cctor SpacingGuildShip */
    this->passengerCount = ship.passengerCount;
    this->operatingGuildNavigator = ship.operatingGuildNavigator;
    this->spiceStock = ship.spiceStock;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip()
{
    /* Dtor SpacingGuildShip */
}

int SpacingGuildShip::getShipSerialNum() const
{
    /* Mengembalikan serial number dari pesawat */
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
    /* Mengembalikan jumlah penumpang pesawat */
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
    /* Pesawat bergerak sebesar distance, sehingga
     * totalGuildTravel bertambah sebesar:
     *
     * distance / (E^2 * operatingGuildNavigator).
     *
     * Catatan:
     * 1. Apabila tidak ada Guild Navigator yang operasional,
     *    maka totalGuildTravel tidak bertambah;
     * 2. Apabila ada Guild Navigator yang operasional,
     *    maka jumlah Guild Navigator operasional berkurang 1 */
    if (this->operatingGuildNavigator > 0)
    {
        totalGuildTravel += distance / (E * E * this->operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers)
{
    /* Penumpang naik ke pesawat sebesar addedPassenger.
     * Jika pesawat tidak muat, penumpang pesawat menjadi penuh */
    this->passengerCount += addedPassengers;
    if (this->passengerCount > this->maxPassengerCap)
    {
        this->passengerCount = this->maxPassengerCap;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
    /* Penumpang turun dari pesawat sebesar droppedPassenger.
     * Jika jumlah penumpang kurang, kosongkan pesawat */
    this->passengerCount -= droppedPassengers;
    if (this->passengerCount < 0)
    {
        this->passengerCount = 0;
    }
}

void SpacingGuildShip::refreshNavigator(int n)
{
    /* Menambah n Guild Navigator operasional yang menghabiskan
     * n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok.
     *
     * Catatan:
     * 1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat
     * 2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh
     *    dari stok spice yang ada */
    if (n * GUILD_NAVIGATOR_SPICE_DOSE <= this->spiceStock)
    {
        this->spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
        this->operatingGuildNavigator += n;
    }
    else
    {
        this->spiceStock -= this->spiceStock / GUILD_NAVIGATOR_SPICE_DOSE * GUILD_NAVIGATOR_SPICE_DOSE;
        this->operatingGuildNavigator += this->spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
    }

    if (this->operatingGuildNavigator > this->guildNavigatorCount)
    {
        this->operatingGuildNavigator -= this->operatingGuildNavigator - this->guildNavigatorCount;
        this->spiceStock += (this->operatingGuildNavigator - this->guildNavigatorCount) * GUILD_NAVIGATOR_SPICE_DOSE;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
    /* Menambah stok spice sebesar addedSpice */
    this->spiceStock += addedSpice;
}
