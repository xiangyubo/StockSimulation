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
    TransTable  transaction_history;    //�ù�Ʊ�ľɽ��׼�¼
    TransTable  new_transaction;        //�ù�Ʊ���½��׼�¼
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
