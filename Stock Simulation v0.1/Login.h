#include"EmptyPage.h"
#include<string>
#include<iostream>
using std::string;

class Login:public EmptyPage
{
private:
    string user_name;
    string password;
public:
    static Login* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    Login(){}
    Login(const Login& ){}
    Login& operator = (const Login& ){}
    void transform(StockSystem *stock_system);
};