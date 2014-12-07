#ifndef _STOCK_SYSTEM_
#define _STOCK_SYSTEM_

#include<string>
using std::string;

class FSM;
class User;
class Welcome;
class Login;
class Logout;
class BuyPage;
class InquiryPage;
class SelectionPage;
class SellPage;
class StockPoolPage;
class StockMarket;

class StockSystem
{
public:
    friend Welcome;
    friend Login;
    friend Logout;
    friend BuyPage;
    friend SellPage;
    friend SelectionPage;
    friend InquiryPage;
    friend StockPoolPage;

    enum SystemState
    {
        NONE,
        SOMEBODY
    };
private:
    FSM*        fsm;
    SystemState state;
public:
    User*       user;
public:
    StockSystem();
    ~StockSystem();
    bool init();
    void run();
    bool checkUser(const string& user_name, const string& password);
};

#endif