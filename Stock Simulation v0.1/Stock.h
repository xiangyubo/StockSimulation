#include<string>
using std::string;
class Stock
{
private:
    string  name;
    float   price;
public:
    Stock(const string& name = "unkonwn", float f = 0.0f);
    float getPrice();
    string getName();
    void update();
};