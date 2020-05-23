#include <iostream>
#include <string>
#include <memory>
#include <vector>

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
    virtual void attach(std::shared_ptr<Observer> obs) = 0;
    virtual void detach(std::shared_ptr<Observer> obs) = 0;
    virtual void notify() = 0;
};

class Hero: public Observer
{
public:
    Hero(string name, std::shared_ptr<Subject> pSub)
    {
        this->name = name;
        m_pSub = pSub;
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
    std::shared_ptr<Subject> m_pSub;

};



class ControlCenter: public Subject
{
public:
    vector<std::shared_ptr<Observer> > mObs;

    void  attach(std::shared_ptr<Observer> obs)
    {
        mObs.push_back(obs);
    }

    void detach(std::shared_ptr<Observer> obs)
    {
        vector<std::shared_ptr<Observer> >::iterator iter = std::find(mObs.begin(), mObs.end(), obs);
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
};

int main()
{
    std::shared_ptr<ControlCenter> center = std::make_shared<ControlCenter>();
    std::shared_ptr<Hero> js = std::make_shared<Hero>("剑圣", center);
    std::shared_ptr<Hero> jj = std::make_shared<Hero>("剑姬", center);
    std::shared_ptr<Hero> gl = std::make_shared<Hero>("盖伦", center);
    std::shared_ptr<Hero> zx = std::make_shared<Hero>("赵信", center);
    std::shared_ptr<Hero> hz = std::make_shared<Hero>("皇子", center);
    center->attach(std::static_pointer_cast<Observer>(js));
    center->attach(std::static_pointer_cast<Observer>(jj));
    center->attach(std::static_pointer_cast<Observer>(gl));
    center->attach(std::static_pointer_cast<Observer>(zx));
    center->attach(std::static_pointer_cast<Observer>(hz));

    hz->injured();
}