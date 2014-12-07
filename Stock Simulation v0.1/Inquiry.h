#include"EmptyPage.h"
#include<string>
#include<iostream>
using std::string;

class InquiryPage:public EmptyPage
{
private:
    string input_line;
public:
    static InquiryPage* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    InquiryPage(){}
    InquiryPage(const InquiryPage& ){}
    InquiryPage& operator = (const InquiryPage& ){}
    void transform(StockSystem *stock_system);
};