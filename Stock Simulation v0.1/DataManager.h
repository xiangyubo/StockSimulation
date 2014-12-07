#ifndef _DATABASE_
#define _DATABASE_

#include<string>
using std::string;

class DataManager
{
public:
    enum UserType
    {
        SYSTEM,
        STOCKS,
        USER
    };
private:
    DataManager(){};
    DataManager(const DataManager& ){};
    DataManager& operator =(const DataManager& ){};
    string getPath(UserType type);
public:
    static DataManager* getInstance();
    string readHistory(const string& user_name, UserType type);
    void appendHistory(const string& user_name, const string& records, UserType type);
};

#endif