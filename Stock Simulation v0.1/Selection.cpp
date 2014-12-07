#include"Utility.h"
#include"Buy.h"
#include"Sell.h"
#include"Logout.h"
#include"Inquiry.h"
#include"Selection.h"
#include"StockPool.h"
using namespace std;

SelectionPage* SelectionPage::getInstance()
{
    static SelectionPage instance;
    return &instance;
}

void SelectionPage::enter(StockSystem *stock_system)
{
    cout << "****** MAIN MANU ******"<< endl;
    cout << "*** Please choose: ***" << endl;
    cout << "*** 1. Sell stock  ***" << endl;
    cout << "*** 2. Buy stock   ***" << endl;
    cout << "*** 3. Inquiry     ***" << endl;
    cout << "*** 4. Logout      ***" << endl;
    cout << "*** 5. Stock Pool  ***" << endl;
}

void SelectionPage::excute(StockSystem *stock_system)
{
    int _op;
    cin>>_op;
    op = Option(_op);
    transform(stock_system);
}

void SelectionPage::leave(StockSystem *stock_system)
{
    op = Option(-1);
}

void SelectionPage::transform(StockSystem *stock_system)
{
    switch (op)
    {
    case SelectionPage::SELL:
        stock_system->fsm->changePage(SellPage::getInstance());
        break;
    case SelectionPage::BUY:
        stock_system->fsm->changePage(BuyPage::getInstance());
        break;
    case SelectionPage::INQUIRY:
        stock_system->fsm->changePage(InquiryPage::getInstance());
        break;
    case SelectionPage::LOGOUT:
        stock_system->fsm->changePage(Logout::getInstance());
        break;
    case SelectionPage::STOCK_POOL:
        stock_system->fsm->changePage(StockPoolPage::getInstance());
        break;
    default:
        break;
    }
}