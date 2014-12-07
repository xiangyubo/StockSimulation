#include<fstream>
#include<sstream>
#include"DataManager.h"
using namespace std;

DataManager* DataManager::getInstance()
{
    static DataManager instance;
    return &instance;
}

string DataManager::readHistory(const string& user_name, 
                                UserType type)
{
    string file_path = getPath(type);
    ifstream input(file_path + user_name + ".txt", 
                    ios::binary);
    if(input.fail() == true)
    {
        return "";
    }
    stringstream  file_buffer;
    file_buffer<<input.rdbuf();
    string ret(file_buffer.str());
    input.close();

    return ret;
}

void DataManager::appendHistory(const string& user_name, 
                                const string& records,
                                UserType type)
{
    string file_path = getPath(type);
    ofstream output(file_path + user_name + ".txt", 
                    ios_base::app);
    if(output.fail() == true)
    {
        return ;
    }
    output<<records;
}

string DataManager::getPath(UserType type)
{
    switch (type)
    {
    case DataManager::SYSTEM:
        return "";
        break;
    case DataManager::USER:
        return "./UserData/";
        break;
    case DataManager::STOCKS:
        return "./Stocks/";
        break;
    }
}