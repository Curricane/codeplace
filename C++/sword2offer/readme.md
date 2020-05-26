# Introduction
this a folder to code sword2offer as some exercises
# 收获记录
## 001 =号赋值操作
1. 成员变量中如果含有指针，需要在初始化时赋值为`nullptr`,如果指针是字符指针，最好初始化为`'\0'`,如`m_pData = new char[1]; m_pData[0] = '\0'`.
2. 用一个**字符指针**给另一个**字符指针**赋值的时候，需要先做判空处理，再用`strncpy`或者 `memncpy`去**复制内存**而不是复制指针。
3. delete之前先判空
4. 字符指针结尾为`'\0'`,`strlen`遇到`'\0'`停止计算长度，因此复制字符数组，需要长度再加1，把`'\0'`也复制进去.
5. 对于指针内容不需要改变的，用const修饰
## 002 单例模式
6. 单例的实现，需要**私有化构造函数**，产生和销毁单例，需要使用`static`修饰.
```C++
public:
    static LazySingleon* GetSingleon(){...};
    static void Destroy(){...};
private:
    static LazySingleon* m_Instance;
    static std::mutex m_Mutex;
```
7. 成员中有被`static`修饰的变量，使用时需要在全局区声明初始化`HungrySingleon* HungrySingleon::instance = new HungrySingleon();`.
8. 对于线程安全的懒汉模式，需要用到锁，需要两次判空，安全更有效。
```C++
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
```
9. 使用`new`记得`delete`,指针不用`delete`不会触发他们的析构函数。
10. 智能指针不能在定义类的使用使用，容易出问题，可以在初始化时使用。
