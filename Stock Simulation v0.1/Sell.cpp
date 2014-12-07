#include"Utility.h"
#include"Sell.h"
#include"Selection.h"
using namespace std;

SellPage* SellPage::getInstance()
{
    static SellPage instance;
    return &instance;
}

void SellPage::enter(StockSystem *stock_system)
{
    cout << "*** Please input stock name: ***" << endl;
    cin>>stock_name;
    cout << "*** Please input the shares: ***" << endl;
    cin>>shares;
}

void SellPage::excute(StockSystem *stock_system)
{
    int op;
    cout << "*** Do you want to sell it? Please choose: *** " << endl;
    cout << "*** 1. SELL         *** " << endl;
    cout << "*** 2. GO BACK     *** " << endl;
    cin>>op;
    if(op == 1)
    {
        if(stock_system->user->sellStock(stock_name, shares) == true)
        {
            cout << "Sell successfully!" << endl;
        }
        else
        {
            cout << "Sell failure!" << endl;
        }
    }
    transform(stock_system);
}

void SellPage::leave(StockSystem *stock_system)
{
    stock_name.clear();
    stock_name = "";
    shares = 0;
}

void SellPage::transform(StockSystem *stock_system)
{
    stock_system->fsm->changePage(SelectionPage::getInstance());
}