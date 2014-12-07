#include"Utility.h"
#include"Buy.h"
#include"Selection.h"
using namespace std;

BuyPage* BuyPage::getInstance()
{
    static BuyPage instance;
    return &instance;
}

void BuyPage::enter(StockSystem *stock_system)
{
    cout << "*** Please input stock name: ***" << endl;
    cin>>stock_name;
    cout << "*** Please input the shares: ***" << endl;
    cin>>shares;
}

void BuyPage::excute(StockSystem *stock_system)
{
    int _op;
    cout << "*** Do you want to buy it? Please choose: *** " << endl;
    cout << "*** 1. BUY         *** " << endl;
    cout << "*** 2. GO BACK     *** " << endl;
    cin>>_op;
    
    if(_op == 1)
    {
        if(stock_system->user->buyStock(stock_name, shares) == true)    //¹ºÂò³É¹¦
        {
            cout << "Buy successfully!" << endl;
        }
        else
        {
            cout << "Buy failure!" << endl;
        }
    }
    transform(stock_system);
}

void BuyPage::leave(StockSystem *stock_system)
{
    stock_name.clear();
    stock_name = "";
    shares = 0;
}

void BuyPage::transform(StockSystem *stock_system)
{
    stock_system->fsm->changePage(SelectionPage::getInstance());
}