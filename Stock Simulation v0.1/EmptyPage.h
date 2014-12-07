#ifndef _EMPTY_PAGE_
#define _EMPTY_PAGE_

class StockSystem;
class EmptyPage
{
public:
    virtual void enter(StockSystem *) = 0;
    virtual void excute(StockSystem *) = 0;
    virtual void leave(StockSystem *) = 0;
private:
    virtual void transform(StockSystem *) = 0;
};

#endif