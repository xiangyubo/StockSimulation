#include"Stock.h"
Stock::Stock(const string& n, float p):
    price(p), name(n)
{
    
}

float Stock::getPrice()
{
    return price;
}

string Stock::getName()
{
    return name;
}

void Stock::update()
{
    //price changes
}