/**
 * c++ implement singleon
 * 1,hungry
 * 2.lazy
*/

#include <iostream>
#include <mutex>

class HungrySingleon
{
private:
    HungrySingleon()
    {
        std::cout << "HungrySingleon()" << std::endl;
    }
    static HungrySingleon* instance;

public:
    static HungrySingleon* GetSingleon ()
    {
        return instance;
    }

    static void Destroy()
    {
        if (instance != nullptr)
        {
            std::cout << "instance is not nullptr, delete it" << std::endl;
            delete instance;
            instance = nullptr;
            return;
        }
        else
        {
            std::cout << "instance already deleted, do nothing" << std::endl;
            return;
        }
        
    }
};

class LazySingleon
{
private:
    LazySingleon()
    {
        std::cout << "LazySingleon()" << std::endl;
    }
    static LazySingleon* m_Instance;
    static std::mutex m_Mutex;

public:
    static LazySingleon* GetSingleon()
    {
        if (nullptr == m_Instance)
        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            if (nullptr == m_Instance)
            {
                m_Instance = new LazySingleon();
            }
        }
        return m_Instance;
    }


    static void Destroy()
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (nullptr != m_Instance)
        {
            std::cout << "instance is not nullptr, delete it" << std::endl;
            delete m_Instance;
        }
        else
        {
            std::cout << "instance already deleted, do nothing" << std::endl;
        }
        
        m_Instance = nullptr;
    }
};

//becasue its contain static member, befor use it, we should init it first
HungrySingleon* HungrySingleon::instance = new HungrySingleon();

void testHungrySingleon()
{
    std::cout << "test HungrySingleon" << std::endl;
    HungrySingleon* hs1 = HungrySingleon::GetSingleon();
    HungrySingleon* hs2 = HungrySingleon::GetSingleon();
    HungrySingleon* hs3 = HungrySingleon::GetSingleon();
    std::cout << "hs1: " << hs1 << std::endl;
    std::cout << "hs2: " << hs2 << std::endl;
    std::cout << "hs3: " << hs3 << std::endl;
    hs1->Destroy();
    hs2->Destroy();
    hs3->Destroy();
}

LazySingleon* LazySingleon::m_Instance = nullptr;
std::mutex LazySingleon::m_Mutex;
void testLazySingleon()
{
    std::cout << "test LazySingleon" << std::endl;
    LazySingleon* ls1 = LazySingleon::GetSingleon();
    LazySingleon* ls2 = LazySingleon::GetSingleon();
    LazySingleon* ls3 = LazySingleon::GetSingleon();
    std::cout << "ls1: " << ls1 << std::endl;
    std::cout << "ls2: " << ls2 << std::endl;
    std::cout << "ls3: " << ls3 << std::endl;
    ls1->Destroy();
    ls2->Destroy();
    ls3->Destroy();
}
int main()
{
    testHungrySingleon();
    testLazySingleon();
    return 0;
}