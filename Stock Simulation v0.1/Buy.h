#include"EmptyPage.h"
#include<string>
#include<iostream>
using std::string;

class BuyPage:public EmptyPage
{
private:  
    string  stock_name;
    int     shares;
public:
    static BuyPage* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    BuyPage(){}
    BuyPage(const BuyPage& ){}
    BuyPage& operator = (const BuyPage& ){}
    void transform(StockSystem *stock_system);
};