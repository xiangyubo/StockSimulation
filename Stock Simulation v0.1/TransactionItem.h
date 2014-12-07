#include<string>
using std::string;

class TransactionItem      //一条交易记录
{
public:
    typedef enum class TransType   //交易记录类型，买or卖
    {
        UNKNOWN,
        BUY,
        SELL
    };
private:
    string      name;
    TransType   type;
    int         shares;
    float       price;
public:
    TransactionItem(const string& n = "unkonwn", TransType t = TransType::UNKNOWN, int s = 0, float p = 0.0f);
    void printTransItem();
    string saveItem();
    TransType getType();
    int getShares();
    float getPrice();
};

