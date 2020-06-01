#include <iostream>

template <typename T>
class A
{
public:
    A(T t)
    {
        mA = t;
    }

    void print()
    {
        std::cout << "mA :" << mA << std::endl;
    }
private:
    T mA;
};


// 模板类派生普通的类
// 派生时，父类需要指定类型
class B:public A<int>
{
private:
    int mB;
public:
    B(int b, int a);
    ~B();
};

// 因为父类A只有有参构造函数，因此需要在构造列表中初始化
B::B(int b, int a):A<int>(a)
{
    mB = b;
}

B::~B()
{
}


// 模板类派生模模板类
// 需要声明派生的类型 T
//派生时，需要指定父类派生的类型T
template <typename T>
class C:public A<T> 
{
private:
    T mC;
public:
    C(T c, T a);
    void print();
};

template <typename T>
C<T>::C(T c, T a): A<T>(a)
{
    mC = c;
}

template <typename T>
void C<T>::print()
{
    std::cout << "mC: " << mC << std::endl;
}

// template <typename T>
// C::C(T c, T a):A<T>(a)
// {
//     t = c;
// }

int main()
{
    A<int> a(10);
    B b(11, 9);
    C<int> c(12, 8);
    a.print();
    b.print();
    c.print();
}
