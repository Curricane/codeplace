#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

class Shape
{
public:
    Shape(){
        cout << "shape init" << endl;
    }                    // 构造函数不能是虚函数
    virtual double calcArea()
    {
        cout << "shape calcArea" << endl;
        return 0.0;
    };
    virtual ~Shape()
    {
        cout << "shape bye bye" << endl;
    };           // 虚析构函数
};
class Circle : public Shape     // 圆形类
{
public:
    virtual double calcArea()
    {
        cout << "圆面积是5" << endl;
        return 5.0;
    }
    Circle()
    {
        cout << "circle init" << endl;
    }
    ~Circle()
    {
         cout << "circle bye bye" << endl;
    }
};
int main()
{
    // Shape * shape1 = new Circle();
    // shape1->calcArea();    
    // delete shape1;  // 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏。
    // shape1 = nullptr;
    // shape init
    // circle init
    // 圆面积是5
    // circle bye bye //当父类的解析函数是虚函数的时候，删除父类指向子类的指针，会先调用子类的析构函数
    // shape bye bye //再调用父类的析构函数

    Shape * shape1; 
    printf("未初始化的指针地址： %p\n", shape1); //未初始化的指针地址： 0x7ffee2c0f778
    Circle* p = new Circle(); // shape init
                              // circle init
    printf("初始化circle p指针地址： %p\n", p); // 初始化circle p指针地址： 0x7fbf0c405880
    shape1 = p; //这样写，先创建子类指针，赋值给父类指针，可以多态，删除时父类指针，如果父类析构函数是虚函数，则也会先子类析构，再析构父类。
    printf("子类指针赋值给父类指针后，父类指针： %p\n", shape1); // 子类指针赋值给父类指针后，父类指针： 0x7fbf0c405880
    cout << "shape1->calcArea():" << endl;
    shape1->calcArea(); // 圆面积是5
    cout << "p->calcArea():" << endl; 
    p->calcArea(); // 圆面积是5
    delete shape1;  // circle bye bye
                    // shape bye bye
    
    printf("删除父类指针后 子类指针p的地址： %p\n", p);  // 删除父类指针后 子类指针p的地址： 0x7fbf0c405880
    printf("删除父类指针后 父类指针的地址： %p\n", shape1); // 删除父类指针后 父类指针的地址： 0x7fbf0c405880
    printf("仍使用子类指针计算面积的结果: \n"); 
    p->calcArea(); // shape calcArea
    shape1->calcArea(); // shape calcArea //奇怪的是，delete 指向子类的父类指针， 子类看似析构了，但依旧可以调用接口，只是返回的是父类的值
                        // 可以这么理解，调用了析构函数，执行析构函数中的方法，然后把对象这一块的地址标记为可用，实际内存还是在的，在没有覆盖之前
                        // 依旧可以使用他的方法
                        // 但为什么会出现 打印的是父类的方法，可以猜测，把子类指针赋值给父类指针的时候，一定是在指针指向的地方做出了修改
    shape1 = nullptr;
    return 0;
}