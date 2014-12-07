#include"Utility.h"
#include"Login.h"
#include"Welcome.h"
using namespace std;

Welcome* Welcome::getInstance()
{
    static Welcome instance;
    return &instance;
}

void Welcome::enter(StockSystem *stock_system)
{
    cout << "********************************************************" << endl;
    cout << "**** WELCOME TO XYB'S STOCK TRADING SYSTEM! ****" << endl;
    cout << "****            VERSON 0.1      12/7/2014           ****" << endl;
    cout << "********************************************************" << endl;
}

void Welcome::excute(StockSystem *stock_system)
{
    transform(stock_system);
}

void Welcome::leave(StockSystem *stock_system)
{
    
}


void Welcome::transform(StockSystem *stock_system)
{
    stock_system->fsm->changePage(Login::getInstance());
}