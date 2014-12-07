#include"EmptyPage.h"
#include<string>
#include<iostream>

class SelectionPage:public EmptyPage
{
private:
    enum Option
    {
        SELL = 1,
        BUY,
        INQUIRY,
        LOGOUT,
        STOCK_POOL
    };
    Option  op;
public:
    static SelectionPage* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    SelectionPage(){}
    SelectionPage(const SelectionPage& ){}
    SelectionPage& operator = (const SelectionPage& ){}
    void transform(StockSystem *stock_system);
};