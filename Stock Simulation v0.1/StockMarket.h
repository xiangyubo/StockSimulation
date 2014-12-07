#include<string>
#include<unordered_map>
#include"Stock.h"
using std::string;
using std::unordered_map;

class StockMarket
{
public:
    typedef unordered_map<string, Stock>    Market;
private:
    Market  market;
private:
    StockMarket(){};
    StockMarket(const StockMarket& ){};
    StockMarket& operator = (const StockMarket& ){};
public:
    static StockMarket* getInstance();
    ~StockMarket();
    void updateMarket();
    void showStocks();
    void showStock(const string& );
    float getStockPrice(const string& );
    bool init();
    void saveMarket();
};