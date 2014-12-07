#include"EmptyPage.h"
#include<string>
#include<iostream>

class Logout:public EmptyPage
{
public:
    static Logout* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    Logout(){}
    Logout(const Logout& ){}
    Logout& operator = (const Logout& ){}
    void transform(StockSystem *stock_system);
};