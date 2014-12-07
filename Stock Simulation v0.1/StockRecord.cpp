#include"StockRecord.h"
#include<string>
using std::string;

StockRecord::StockRecord(int s, float p, float g):shares(s), price(p), gain_or_loss(g)
{
    
}

void StockRecord::init()
{
    for(auto it = transaction_history.begin();
        it != transaction_history.end(); ++it)
    {
        if(it->getType() == TransactionItem::TransType::SELL)
        {
            shares -= it->getShares();
        }
        else if(it->getType() == TransactionItem::TransType::BUY)
        {
            shares += it->getShares();
        }
    }
}

void StockRecord::updateShares(int s)
{
    shares += s;
}

void StockRecord::loadHistoryRecord(TransactionItem& item)
{
    transaction_history.push_back(item);
}

void StockRecord::addNewRecord(TransactionItem& item)
{
    new_transaction.push_back(item);
}

int StockRecord::getCurrentShares()
{
    return shares;
}

float StockRecord::getCurrentPrice()
{
    return price;
}

float StockRecord::getGainOrLoss()
{
    return gain_or_loss;
}

void StockRecord::printHistory()
{
    for(auto it = transaction_history.begin();
        it != transaction_history.end(); ++it)
    {
        it->printTransItem();
    }
    for(auto it = new_transaction.begin();
        it != new_transaction.end(); ++it)
    {
        it->printTransItem();
    }
}

string StockRecord::saveNewRecord()
{
    string records;
    for(auto it = new_transaction.begin();
        it != new_transaction.end(); ++it)
    {
        records += it->saveItem();
        records += "\n";
    }
    return records;
}

void StockRecord::updatePrice()
{
    //计算出新的持有股价格
}

void StockRecord::updateGainOrLoss()
{
    //计算出新的收益
}