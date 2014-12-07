#ifndef _FSM_
#define _FSM_

#include"EmptyPage.h"
class StockSystem;

class FSM
{
private:
    StockSystem*    system;
    EmptyPage*      current_page;

public:
    FSM(StockSystem* stock_system, EmptyPage* page):
        system(stock_system), current_page(page)
    {

    }

    void excute()
    {
        current_page->enter(system);
        current_page->excute(system);
    }
    
    void changePage(EmptyPage *new_page)
    {
        current_page->leave(system);
        current_page = new_page;        
    }
};

#endif