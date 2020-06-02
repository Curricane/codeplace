#include <iostream>
using namespace std;

// stactic_cast 与 reinterpret_cast 用法
void testSR()
{
	double dPi = 3.1415926;

	//1静态的类型转换:  在编译的时 进行基本类型的转换 能替代c风格的类型转换 可以进行一部分检查
	int num1 = static_cast<int> (dPi); //c++的新式的类型转换运算符  
	int num2 = (int)dPi;				//c语言的 旧式类型转换 
	int num3 = dPi;						//隐士类型转换
	cout << "num1:" << num1 << " num2:" << num2 << " num3:" << num3 << endl;


	char *p1 = "hello wangbaoming " ;
	int *p2 = NULL;
	p2 = (int *)p1;
    cout << "p2 = (int *)p1 : " << p2 << endl;
	//2 基本类型能转换 但是不能转换指针类型
	//p2 = static_cast<int *> (p1); //“static_cast”: 无法从“char *”转换为“int *”

	//3 可以使用  reinterpret_cast 进行重新解释 
	p2 = reinterpret_cast<int *> (p1);
	cout << "p2 = reinterpret_cast<int *> (p1); " << p2 << endl;

	//4 一般性的结论：	c语言中  能隐式类型转换的 在c++中可以用 static_cast<>()进行类型转换  //C++编译器在编译检查一般都能通过
	//c语言中不能隐式类型转换的,在c++中可以用 reinterpret_cast<>() 进行强行类型 解释 
}



// dynamic_cast 与 reinterpret_cast 用法
class Animal 
{
public:
	virtual void  cry() = 0; 
};

class Dog : public Animal 
{
public:
	virtual void  cry()
	{
		cout << "wangwang " << endl;
	}

	void doSwim()  
	{ 
		cout << "我要狗爬" << endl; 
	}
};


class Cat : public Animal
{
public:
	virtual void  cry()
	{
		cout << "miaomiao " << endl;
	}
	void doTree()  
	{ 
		cout << "我要爬树" << endl; 
	}

};

class Book
{
public:
	void printP()
	{
		cout << price << endl;
	}

private:
	int price;

};

void ObjPlay(Animal *base)
{
	base->cry();
	Dog *pDog = dynamic_cast<Dog *>(base);
	if (pDog != NULL)
	{
		pDog->cry();
		pDog->doSwim();
	}

	Cat *pCat = dynamic_cast<Cat *>(base);
	if (pCat != NULL)
	{
		pCat->cry();
		pCat->doTree();
	}
}

void testDR()
{
	Animal *base = NULL;

	//1 可以把子类指针赋给 父类指针 但是反过来是不可以的 需要 如下转换
	//pdog = base;  
	Dog *pDog = static_cast<Dog *> (base);

	//2 把base转换成其他 非动物相关的 err
	//Book *book= static_cast<Book *> (base);

	//3  reinterpret_cast //可以强制类型转换
	Book *book2= reinterpret_cast<Book *> (base);

	//4 dynamic_cast用法
	ObjPlay(new Cat());
}

// const_cast用法
//典型用法 把形参的只读属性去掉
void Opbuf(const char *p)
{
	cout << p << endl;
	char *p2 = const_cast<char*>(p);
	p2[0] = 'b';
	cout << p << endl;
}

void testC()
{
    	const char *p1 = "11111111111";

	char *p2 = "22222222";

	char *p3 = const_cast<char *>(p1);
	char buf[100] = "aaaaaaaaaaaa";

	Opbuf(buf);

	//要保证指针所执行的内存空间能修改才行 若不能修改 还是会引起程序异常
	//Opbuf("dddddddddddsssssssssssssss"); //能编译过，但运行出错 Bus error: 10
}

int main()
{
    testSR();

    testDR();

    testC();
}
