#include"EmptyPage.h"
#include<string>
#include<iostream>
using std::string;

class SellPage:public EmptyPage
{
    string  stock_name;
    int     shares;
public:
    static SellPage* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    SellPage(){}
    SellPage(const SellPage& ){}
    SellPage& operator = (const SellPage& ){}
    void transform(StockSystem *stock_system);
};