#include"Utility.h"
#include"Login.h"
#include"Selection.h"
using namespace std;

Login* Login::getInstance()
{
    static Login instance;
    return &instance;
}

void Login::enter(StockSystem *stock_system)
{
    cout << "****** LOGIN ******"<< endl;
    cout << "Please input your username: " << endl;
    cin>>user_name;
    cout<<"Please input your password: "<<endl;
    cin>>password;
}

void Login::excute(StockSystem *stock_system)
{
    if(stock_system->checkUser(user_name, password) == true)
    {
        User user;
        stock_system->state = StockSystem::SystemState::SOMEBODY;
    }
    else
    {
        stock_system->state = StockSystem::SystemState::NONE;
    }
    transform(stock_system);
}

void Login::leave(StockSystem *stock_system)
{
    
}


void Login::transform(StockSystem *stock_system)
{
    if(stock_system->state == StockSystem::SystemState::NONE)
    {
        cout << "Incorret Username or Password! Please input again." << endl;
        stock_system->fsm->changePage(Login::getInstance());
    }
    else if(stock_system->state == StockSystem::SystemState::SOMEBODY)
    {
        stock_system->fsm->changePage(SelectionPage::getInstance());
    }
}