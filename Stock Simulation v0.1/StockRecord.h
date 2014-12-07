#include"TransactionItem.h"
#include<vector>
using std::vector;

class StockRecord
{
private:
    typedef vector<TransactionItem> TransTable;

    int         shares;
    float       price;
    float       gain_or_loss;
    TransTable  transaction_history;    //该股票的旧交易记录
    TransTable  new_transaction;        //该股票的新交易记录
public:
    StockRecord(int s = 0, float p = 0.0f, float g = 0.0f);
    void init();
    void updateShares(int );   
    void loadHistoryRecord(TransactionItem & );
    void addNewRecord(TransactionItem & );
    int getCurrentShares();
    float getCurrentPrice();
    float getGainOrLoss();
    void printHistory();
    std::string saveNewRecord();
private:
    void updatePrice();
    void updateGainOrLoss();
};
