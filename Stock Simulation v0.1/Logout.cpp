#include"Utility.h"
#include"Logout.h"
#include"Login.h"
#include"Selection.h"
using namespace std;

Logout* Logout::getInstance()
{
    static Logout instance;
    return &instance;
}

void Logout::enter(StockSystem *stock_system)
{
    cout << "*** THANK YOU FOR USING XYB'S STOCK TRADING SYSTEM! ***" << endl;
}

void Logout::excute(StockSystem *stock_system)
{
    stock_system->user->saveStocks();
    stock_system->state = StockSystem::SystemState::NONE;
    transform(stock_system);
}

void Logout::leave(StockSystem *stock_system)
{
    
}

void Logout::transform(StockSystem *stock_system)
{
    stock_system->fsm->changePage(Login::getInstance());
}