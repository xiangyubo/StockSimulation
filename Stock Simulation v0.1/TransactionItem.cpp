#include"TransactionItem.h"
#include<cstdio>
using std::string;

TransactionItem::TransactionItem(const string& n, TransType t, int s, float p):
    name(n), type(t), shares(s), price(p)
{
    
}

void TransactionItem::printTransItem()
{
    if(type == TransType::BUY)
    {
        printf("buy     %8d share(s)     at price %.2f\n", shares, price);
    }
    else if(type == TransType::SELL)
    {
        printf("sell    %8d share(s)     at price %.2f\n", shares, price);
    }
}

string TransactionItem::saveItem()
{
    string ret(name);
    ret += " ";
    ret += std::to_string(int(type));
    ret += " ";
    ret += std::to_string(shares);
    ret += " ";
    ret += std::to_string(price);
    return ret;
}

TransactionItem::TransType TransactionItem::getType()
{
    return type;
}

int TransactionItem::getShares()
{
    return shares;
}

float TransactionItem::getPrice()
{
    return price;
}