#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
class teacher
{
public:
    void teach()
    {
        cout << "我正在教书 dadadadadada...."  << endl;
    }

    // 需要无参构造函数，因为会被使用为new teacher[size],这条语句需要无参构造函数
    teacher()
    {
        name = new char[1];
        name[0] = '\0';
        age = 0;
    }

    teacher(const char* name, int age = 18)
    {
        cout << "teacher 带参构造函数" << endl;
        int len = strlen(name);
        this->name = new char[len + 1];
        strncpy(this->name, name, len);
        this->name[len] = '\0';
        this->age = age;
    }

    teacher(const teacher& obj)
    {
        cout << "teacher 赋值构造函数" << endl;
        int len = strlen(obj.name);
        name = new char[len + 1];
        strncpy(name, obj.name, len);
        name[len] = '\0';
        age = obj.age;
    }

    ~teacher();

    teacher& operator=(const teacher& obj);

    // static void* operator new[](size_t size)
    // {
    //     cout << "teacher: own new[] function" << endl;
    //     return ::operator new(size);
    // }

    // void operator delete[](void* p)
    // {
    //     cout << "teacher: own delete[] function" << endl;
    //     free(p);
    // }

    friend ostream & operator<<(ostream & out, const teacher& obj);


private:
    char* name;
    int age;
};

teacher::~teacher()
{
    cout << "teacher: 析构函数" << endl;
    if (name != nullptr)
    {
        delete [] name;
        name = nullptr;
    }
}

teacher& teacher::operator=(const teacher& obj)
{
    cout << "teacher 重载等号函数" << endl;
    if (name != nullptr)
    {
        delete [] name;
        name = nullptr;
    }

    int len = strlen(obj.name);
    name = new char[len + 1];
    strncpy(name, obj.name, len);
    name[len] = '\0';
    age = obj.age;
    return *this;
}

ostream & operator<<(ostream & out, const teacher& obj)
{
    cout << "teacher 重载<< " << endl;
    int len = strlen(obj.name);
    out << "<class teacher> name: ";
    for (int i= 0; i < len; ++i)
    {
        out << obj.name[i];
    }
    out << " age: " << obj.age;
    return out;
}

