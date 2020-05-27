#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

namespace ProxySample
{

class SearcherItf
{
public:
    virtual string DoSearch(string userId, string keyword) = 0;
    virtual ~SearcherItf(){};
};

class RealSearcher: public SearcherItf
{
public:
    string DoSearch(string userId, string keyword)
    {
        cout << "用户'" << userId << "'使用关键字'" << keyword << "'查询商务信息" << endl;
        return "具体信息";
    }
    RealSearcher()
    {
        cout << "RealSearcher created" << endl;
    }
    ~RealSearcher()
    {
        cout << "bye RealSearcher" << endl;
    }
};

class AccessValidator
{
public:
    bool Validate(string userId)
    {
        cout << "在数据库中验证用户：" << userId << "是否合法" << endl;
        if (userId.compare(string("杨过")) == 0)
        {
            cout << userId << "登录成功" << endl;
            return true;
        }
        else
        {
            cout << userId << "登录失败" << endl;
            return false;
        }
        
    }
    AccessValidator()
    {
        cout << "AccessValidator created" << endl;
    }
    ~AccessValidator()
    {
        cout << "bye AccessValidator" << endl;
    }
};

class Logger
{
public:
    void Log(string userId)
    {
        cout << "更新数据库，用户‘" << userId << "'查询次数+1" << endl;
    }
    Logger()
    {
        cout << "Logger created" << endl;
    }
    ~Logger()
    {
        cout << "bye Logger" << endl;
    }
};

class ProxySearch:public SearcherItf
{
public:
    ProxySearch()
    {
        cout << "ProxySearch created" << endl;
        mSearch = new RealSearcher();
    }
    ~ProxySearch()
    {
        cout << "bye ProxySearch" << endl;
        if(mSearch != nullptr)
        {
            delete mSearch;
            mSearch = nullptr;
        }
    }
    string DoSearch(string userId, string keyword)
    {
        if(mAValidate.Validate(userId))
        {
            return mSearch->DoSearch(userId, keyword);
        }
        return "";
    }

private:
    Logger mLogger;
    AccessValidator mAValidate;
    RealSearcher* mSearch;
};

}; // end ProxySample

int main()
{
    ProxySample::ProxySearch searchProxy;
    string result = searchProxy.DoSearch("杨过", "九阳神功");
    cout << result << endl;
    result = searchProxy.DoSearch("欧阳锋", "九阳神功");
    cout << result << endl;
}