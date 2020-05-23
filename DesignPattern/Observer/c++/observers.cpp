#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <mutex>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Observer
{
public:
    virtual void update() = 0;
};

class Subject
{
public:
    virtual void attach(Observer* obs) = 0;
    virtual void detach(Observer* obs) = 0;
    virtual void notify() = 0;
};

class Hero: public Observer
{
public:
    Hero(string name, Subject* pSub)
    {
        this->name = name;
        m_pSub = pSub;
        m_pSub->attach(this);
    }
    ~Hero()
    {
        cout << "再见，" << name << "去也！" << endl;
        m_pSub->detach(this);
        
    }
    void attack()
    {
        cout << "我乃" << name << "吃我一招" << endl;
    }
    void injured()
    {
        cout << "呼叫总部，我是" << name << "，我受伤了，请求支援！" << endl;
        m_pSub->notify();
    }
    void help()
    {
        cout << "别怕" << name << "来救你" << endl;
    }
    void update()
    {
        help();
    }
public:
    string name;

private:
    Subject *m_pSub;

};



class ControlCenter: public Subject
{
public:
    vector<Observer*> mObs;

    void  attach(Observer *obs)
    {
        mObs.push_back(obs);
    }

    void detach(Observer* obs)
    {
        std::lock_guard<std::mutex> guard(mMutex);
        vector<Observer*>::iterator iter = std::find(mObs.begin(), mObs.end(), obs);
        mObs.erase(iter);
    }

    void notify()
    {
        for(auto obs: mObs)
        {
            obs->update();
        }
    }

    ControlCenter(){};
private:
    std::mutex mMutex;
};

int main()
{
    ControlCenter *center = new ControlCenter();
    std::shared_ptr<Hero> js = std::make_shared<Hero>("剑圣", center);
    std::shared_ptr<Hero> jj = std::make_shared<Hero>("剑姬", center);
    std::shared_ptr<Hero> gl = std::make_shared<Hero>("盖伦", center);
    std::shared_ptr<Hero> zx = std::make_shared<Hero>("赵信", center);
    std::shared_ptr<Hero> hz = std::make_shared<Hero>("皇子", center);
    // center->attach(std::static_pointer_cast<Observer>(js));
    // center->attach(std::static_pointer_cast<Observer>(jj));
    // center->attach(std::static_pointer_cast<Observer>(gl));
    // center->attach(std::static_pointer_cast<Observer>(zx));
    // center->attach(std::static_pointer_cast<Observer>(hz));

    hz->injured();
    // center->detach(hz);
}