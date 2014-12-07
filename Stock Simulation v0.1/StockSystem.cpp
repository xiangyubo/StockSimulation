#include"FSM.h"
#include"User.h"
#include"Welcome.h"
#include"StockSystem.h"
#include"DataManager.h"
#include"StockMarket.h"
#include<sstream>
using namespace std;

StockSystem::StockSystem():fsm(nullptr), 
                           state(SystemState::NONE),
                           user(nullptr)
{
    fsm = new FSM(this, Welcome::getInstance());
}

StockSystem::~StockSystem()
{
    delete fsm;
    delete user;
}

bool StockSystem::init()
{
    return StockMarket::getInstance()->init();
}

void StockSystem::run()
{
    while(true)
    {
        fsm->excute();
    }
}

bool StockSystem::checkUser(const string& user_name, const string& password)
{
    DataManager *data_instance = DataManager::getInstance();
    string data(data_instance->readHistory("UserInfo", 
                                            DataManager::UserType::SYSTEM));
    stringstream data_io(data);

    string name, pswd;
    while(data_io>>name>>pswd)
    {
        if(user_name == name && password == pswd)
        {
            user = new User(user_name);
            user->initStocks();
            return true;
        }
    }
    return false;
}