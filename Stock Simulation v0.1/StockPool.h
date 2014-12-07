#include"EmptyPage.h"
class StockPoolPage:public EmptyPage
{
public:
    static StockPoolPage* getInstance();
    void enter(StockSystem *stock_system);
    void excute(StockSystem *stock_system);
    void leave(StockSystem *stock_system);
private:
    StockPoolPage(){}
    StockPoolPage(const StockPoolPage& ){}
    StockPoolPage& operator = (const StockPoolPage& ){}
    void transform(StockSystem *stock_system);
};