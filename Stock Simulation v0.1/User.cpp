#include "User.h"
#include "StockMarket.h"
#include "DataManager.h"
#include <cstdio>
#include<sstream>
using namespace std;

User::User(string n):name(n)
{

}

bool User::inquiryStock(const string& stock_name)
{
    if(stocks.find(stock_name) == stocks.end())
    {
        return false;
    }
    else
    {
        printf("%s:\n", stock_name.c_str());
        stocks[stock_name].printHistory();
        return true;
    }
}

bool User::buyStock(const string& stock_name, int shares)
{
    StockMarket *market_instance =  StockMarket::getInstance();
    float current_price = market_instance->getStockPrice(stock_name);
    if(current_price <= 0)
    {
        return false;
    }
    else
    {
        TransactionItem temp(stock_name, TransactionItem::TransType::BUY, 
            shares, current_price);
        if(stocks.find(stock_name) == stocks.end())
        {
            stocks.insert(pair<string, StockRecord>(stock_name, StockRecord()));
        }
        stocks[stock_name].addNewRecord(temp);
        stocks[stock_name].updateShares(shares);
        return true;
    }
}
bool User::sellStock(const string& stock_name, int shares)
{
    if(stocks.find(stock_name) == stocks.end() ||
        stocks[stock_name].getCurrentShares() < shares)
    {
        return false;
    }
    else
    {
        StockMarket *market_instance =  StockMarket::getInstance();
        float current_price = market_instance->getStockPrice(stock_name);
        if(current_price <= 0)
        {
            return false;
        }
        TransactionItem temp(stock_name, TransactionItem::TransType::SELL, 
            shares, current_price);
        stocks[stock_name].addNewRecord(temp);
        stocks[stock_name].updateShares(-1 * shares);
        return true;
    }
}

void User::initStocks()
{
    DataManager *data_instance = DataManager::getInstance();
    string data(data_instance->readHistory(name, 
                                           DataManager::UserType::USER));
    stringstream data_io(data);

    string stock_name;
    int type;
    int share;
    float price;

    while(data_io>>stock_name>>type>>share>>price)
    {
        TransactionItem temp(stock_name,
            TransactionItem::TransType(type),
            share,
            price);
        if(stocks.find(stock_name) == stocks.end())
        {
            stocks.insert(pair<string, StockRecord>(stock_name, StockRecord()));
        }
        stocks[stock_name].loadHistoryRecord(temp);
    }
    for(auto it = stocks.begin(); it != stocks.end(); ++it)
    {
        it->second.init();
    }
}

void User::saveStocks()
{
    string records;
    for(auto it = stocks.begin(); 
        it != stocks.end(); ++it)
    {
        records += it->second.saveNewRecord();
    }
    DataManager *data_instance = DataManager::getInstance();
    data_instance->appendHistory(name, records, 
                                 DataManager::UserType::USER);
}