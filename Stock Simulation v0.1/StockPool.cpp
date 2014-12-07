#include"StockPool.h"
#include"Utility.h"
#include"Selection.h"
#include"StockMarket.h"
using namespace std;
StockPoolPage* StockPoolPage::getInstance()
{
    static StockPoolPage instance;
    return &instance;
}

void StockPoolPage::enter(StockSystem *stock_system)
{
    cout << "The stocks in our stock pool are the following: " << endl;
}

void StockPoolPage::excute(StockSystem *stock_system)
{
    StockMarket::getInstance()->showStocks();
    transform(stock_system);
}

void StockPoolPage::leave(StockSystem *stock_system)
{
    
}

void StockPoolPage::transform(StockSystem *stock_system)
{
    stock_system->fsm->changePage(SelectionPage::getInstance());
}