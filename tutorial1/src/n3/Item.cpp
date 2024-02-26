// Not yet finished

#include "Item.hpp"

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : serialNum(totalItems + 1)
{
    /* Ctor default: stok adalah 0 dan harga barang adalah 0 */
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1)
{
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item &item) : serialNum(totalItems + 1)
{
    /* cctor item, mengkopi seluruh atribut item, termasuk atribut sold */
    this->stock = item.stock;
    this->price = item.price;
    this->sold = item.sold;
    totalItems++;
}

Item::~Item() {}

int Item::getSerialNum() const
{
    return this->serialNum;
}

int Item::getSold() const
{
    return this->sold;
}
int Item::getPrice() const
{
    return this->price;
}

void Item::addStock(int addedStock)
{
    /* Menambahkan stok item. Tidak akan bernilai negatif. */
    this->stock += addedStock;
}

void Item::sell(int soldStock)
{
    /* Menjual item. Jika item tidak cukup, maka item terjual hanya sampai stok item habis */
    if (soldStock >= this->stock) // should be <
    {
        this->stock -= soldStock;
        this->sold += soldStock;
        totalRevenue += soldStock * this->price;
    }
    else
    {
        this->sold += this->stock;
        totalRevenue += this->stock * this->price;
        this->stock = 0;
    }
}

void Item::setPrice(int newPrice)
{
    this->price = newPrice;
}
