#include"EmptyPage.h"
#include<iostream>

class Welcome:public EmptyPage
{
public:
    static Welcome* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    Welcome(){}
    Welcome(const Welcome& ){}
    Welcome& operator = (const Welcome& ){}
    void transform(StockSystem *stock_system);
};