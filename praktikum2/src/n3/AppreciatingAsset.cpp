#include "AppreciatingAsset.hpp"
#include <cmath>

double AppreciatingAsset::getValue(int years)
{
    return x->getValue(years) * pow(1 + rate, years);
}
