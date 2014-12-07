#include"StockMarket.h"
#include"DataManager.h"
#include<sstream>
#include<cstdio>
using namespace std;

StockMarket* StockMarket::getInstance()
{
    static StockMarket instance;
    return &instance;
}

StockMarket::~StockMarket()
{
    saveMarket();
}

void StockMarket::updateMarket()
{
    for(auto it = market.begin();
        it != market.end(); ++it)
    {
        it->second.update();
    }
}

void StockMarket::showStocks()
{
    for(auto it = market.begin(); it != market.end(); ++it)
    {
        printf("%-20s%-5.2f\n", 
            it->second.getName().c_str(),
            it->second.getPrice());
    }
}

void StockMarket::showStock(const string& stock_name)
{
    if(market.find(stock_name) != market.end())
    {
        printf("%-20s%-5.2f\n", 
            market[stock_name].getName().c_str(), 
            market[stock_name].getPrice());
    }
}

float StockMarket::getStockPrice(const string& stock_name)
{
    if(market.find(stock_name) != market.end())
    {
        return market[stock_name].getPrice();
    }
    else
    {
        return -1.0f;
    }
}

bool StockMarket::init()
{
    //通过DataBase读数据初始化
    DataManager *data_instance = DataManager::getInstance();
    string data(data_instance->readHistory("stocks", 
        DataManager::UserType::STOCKS));
    stringstream data_io(data);

    string  stock_name;
    float   price;
    while(data_io>>stock_name>>price)
    {
        market[stock_name] = Stock(stock_name, price);
    }

    return true;
}

void StockMarket::saveMarket()
{
    //通过DataBase保存数据
    string records;
    for(auto it = market.begin(); 
        it != market.end(); ++it)
    {
        records += it->second.getName();
        records += "    ";
        records += std::to_string(it->second.getPrice());
    }
    DataManager *data_instance = DataManager::getInstance();
    data_instance->appendHistory("stocks", records, 
                                 DataManager::UserType::STOCKS);
}