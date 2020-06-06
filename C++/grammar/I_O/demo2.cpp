#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void test1()
{
    // 测试 cin.get()
    char name[256];
    char c;
    cout << "输入一个字符：+ enter" << endl;
    cin.get(c); 
    cout << "得到一个字符c:" << c << endl;
    cin.get(); // 把/n收掉

    cout << "输入一个字符：" << endl;
    cin.get(c);
    cout << "得到一个字符c:" << c << endl;
    cin.get();

    cout << "输入一行：+ enter" << endl;
    cin.get(name, 256, '\n'); // 不会吸收缓存区的\n
    cout << "打印name：" << name << endl;
    cin.get(); //吸收缓存区的\n
    cout << "输入一行：+ enter" << endl;
    cin.get(name, 256);
    cout << "打印name：" << name << endl;
}

void test2()
{
    //cin.getline()
    char name[1024];
    char c;
    cout << "输入一行：+ enter" << endl;
    cin.getline(name, 1024); 
    cout << "打印name：" << name << endl;

    // 会把\n吸收掉，下面的语句直接获取

    cout << "输入一行：+ enter" << endl;
    cin.getline(name, 1024);
    cout << "打印name：" << name << endl;

}

void test3()
{
    char a, b ,c;
    cout << "输入一行: axxbxxc" << endl;
    cin.get(a);
    cin.ignore(2);
    cin.get(b);
    cin.ignore(2);
    cin.get(c);
    cout << "a: " << a << " b: " << b << " c:" << c << endl; //a: a b: b c:c
}

void test4()
{
    char a, b ,c;
    cout << "输入一行: a'enter''enter'bxxc" << endl;
    cin.get(a); //读取到a
    cin.peek(); // 阻塞
    cin.ignore(2); // 忽略两次enter enter
    cin.get(b); //b
    cin.ignore(2); // 忽略两个空
    cin.get(c); // c
    cout << "a: " << a << " b: " << b << " c:" << c << endl; //a: a b: b c:c
}   

void test5()
{
    char name[1024];
    char c;
    cout << "输入一行: 123456" << endl;
    cin.get(c);
    cin.putback('a');
    cin.getline(name, 1024);
    cout << "取出一个1，放回一个a后： " << name << endl; // 取出一个1，放回一个a后： a23456

}


int main()
{   
    // 测试 cin.get()
    // test1();
    
    // 测试 cin.getline()
    // test2();

    // 测试 cin.ignore()
    // test3();

    // 测试 cin.peek()
    // test4();

    // test cin.putback('a');
    test5();
}