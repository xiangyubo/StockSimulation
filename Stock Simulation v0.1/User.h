#include"StockRecord.h"
#include<unordered_map>
using std::string;
using std::unordered_map;

class User
{
private:
    typedef unordered_map<string, StockRecord> StockTable;

    string name;
    StockTable  stocks;    //手中所有的股票
public:
    User(string n = "unknown");
    bool inquiryStock(const string& stock_name);
    bool buyStock(const string& stock_name, int shares);
    bool sellStock(const string& stock_name, int shares);
    void initStocks();
    void saveStocks();
};