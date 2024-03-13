#include "DepreciatingAsset.hpp"
#include <cmath>

double DepreciatingAsset::getValue(int years)
{
    return x->getValue(years) * pow(1 - rate, years);
}
