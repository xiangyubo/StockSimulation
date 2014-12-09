#include"Utility.h"
#include"Inquiry.h"
#include"Selection.h"
#include<sstream>
using namespace std;

InquiryPage* InquiryPage::getInstance()
{
    static InquiryPage instance;
    return &instance;
}

void InquiryPage::enter(StockSystem *stock_system)
{
    cout << "*** Please input one or more stock names for inquiry: *** " << endl;
    cin>>input_line;
}

void InquiryPage::excute(StockSystem *stock_system)
{
    stringstream parser(input_line);
    string stock_name;
    while(parser>>stock_name)
    {
        if(stock_system->user->inquiryStock(stock_name) != true)
        {
            cout << "You do not have any transation record about " <<stock_name<<endl;
        }
    }
    transform(stock_system);
}

void InquiryPage::leave(StockSystem *stock_system)
{
    input_line.clear();
    input_line = "";
}

void InquiryPage::transform(StockSystem *stock_system)
{
    stock_system->fsm->changePage(SelectionPage::getInstance());
}