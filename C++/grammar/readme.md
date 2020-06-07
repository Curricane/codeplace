# 介绍
用于学习C++语法。
# 模板Template
**模板(Template)**指C++程序设计语言中采用**类型**作为**参数**的程序设计，以支持通用程序设计，在java等语言中的**泛型**类似。通常有两种形式：**函数模板**和**类模板**。需要借助关键字**template**和**typename**或者**class**。
## 函数模板
### 语法
```C++
template <class T1, class T2, class ...>
返回类型 函数名（参数列表）
{
    // 函数体
}

template <typename T>
void swap(T& a, T& b){}
```
其中**class可以用typename关键字代替**。
### 普通函数与模板函数的调用
- 普通函数的调用：**可以进行隐式的类型转换**
- 函数模板的调用：（本质：类型参数化）将严格按照类型进行匹配，**不会进行自动类型转换**。
### 函数模板的调用规则
- 函数模板可以像普通函数一样重载,也可以和同名普通函数一样一起构成重载；
- 普通函数与模板函数都**严格满足调用条件(同名普通函数不进行隐式转换）**时，C++编译器优先考虑普通函数；
- 如果函数模板可以产生一个**更好的匹配（同名普通函数可以隐式转换来满足，但模板直接满足）**，那么选择模板；
- 可以通过**空模板**实参列表 限定编译器只通过模板匹配；
```C++
template <typename T>
T Max(T a, T b);
T Max(T a, T b, T c);
int Max(int a, int b); // 三个函数都重载

Max(1, 2); // 严格满足 int Max(int a, int b) 和 T Max(T a, T b);优先代用普通函数
Max(1.0, 2.0) // 更满足T Max(T a, T b) 普通函数需要隐式转换才满足
Max<>(1, 2); // 使用空模板参数列表，只通过模板匹配调用
```
### 函数模板机制
- 编译器并不是把函数模板处理成能够处理任意类的函数；
- 编译器从函数模板通过具体类型**产生不同的函数**，帮程序员做了这些类型函数的工作；
- 编译器会对函数模板进行**两次编译**；
> **在声明的地方对模板代码本身**进行编译；**在调用的地方对参数替换后的代码**进行编译。
## 类模板
### 语法
```C++
template <typename T1, typename T2, typename ...>
class A
{

}
```
### 模板类派生为普通类
子类从模板类继承的时候,需要让编译器知道 父类的数据类型具体是什么(**数据类型的本质:固定大小内存块的别名**)。
```C++
// 模板类派生普通的类
// 派生时，父类需要指定类型
// 这里不需要写 template ，只需要指定父类的类型
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
```
**模板类是抽象的 ===》 需要进行具体化；编译器得知道怎么给它分配内存**
### 模板类派生模板类
**在声明的地方用到了父类，就需要指明父类的类型T.** 在**类外的实现成员函数**，都需要template声明，写凡声明的类类型不确定，都需要**模板列表指明**,而类内 和 函数类不需要。
```C++
// 模板类派生模模板类
// 需要声明派生的类型 T
//派生时，需要指定父类派生的类型T
template <typename T>
class C:public A<T> 
{
private:
    T mC;
public:
    C(T c, T a); // 类内，因此C后面不需要模板列表指明类型
    void print();
};

template <typename T>
C<T>::C(T c, T a): A<T>(a)
{
    mC = c;
}
```
### 所有的类模板函数写在类的外部，在一个cpp中
- 在类外的声明中用到了模板就要显示的声明类型T，函数内部可以不用申明
- 友元函数：用友元函数重载 << >>，**其他时候使用友元属于滥用**，**强烈建议模板的友元函数写在类中实现，不然很容易出问题**，因为友元函数不是类内函数，是外部函数，不能用类的域名指定。
### 类模板声明与实现分开在两个文件里
1. 如果分开放在M.h 与 M.cpp
当别的文件include M.h，是会编译失败的，因为模板实现的原理需要二次编译，因此需要include "M.cpp"才行，一般会把.cpp 改为后缀.hpp。
2. 建议把模板类都写在.h文件里，这样只要include <M.h>就可以了。
因为模板的机制是二次编译，分开写而值应用声明，在二次编译时会找不到。
### 类模板中的static关键字
1. 从类模板实例化的**每个模板类有自己的类模板数据成员**，该模板类的所有对象共享一个static数据成员
2. **和非模板类的static数据成员一样，模板类的static数据成员也应该在文件范围定义和初始化**
3. **每个模板类有自己的类模板的static数据成员副本**
### 应用中需要注意的地方
1. **所有容器提供的都是值（value）语意，而非引用（reference）语意**。容器执行插入元素的操作时，内部实施拷贝动作。所以STL容器内存储的元素必须能够被拷贝（**必须提供拷贝构造函数**）。
2. 如果模板涉及到new T[] 操作，应当给对应的T加上默认构造函数，不然会失败
``` c++
// 需要无参构造函数，因为会被使用为new teacher[size],这条语句需要无参构造函数
    teacher()
    {
        name = new char[1];
        name[0] = '\0';
        age = 0;
    }
```
# 类型转换
## 语法
### C风格类型转换
- type b = (type)a
### C++风格类型转换
- static_cast 静态类型转换。如int转换成char
- reinterpreter_cast 重新解释类型，类似于强制转换，但更强
- dynamic_cast 命名上理解是动态类型转换。如子类和父类之间的多态类型转换。
- const_cast 字面上理解就是去const属性
- 使用方式为`newtype new = xxx_cast<newtype> old`
### 一般性介绍
1. static_cast<>() 静态类型转换，**编译时c++编译器会做类型检查；
2. 一般性结论：
- C语言中  能**隐式类型转换**的，在c++中可用 static_cast<>()进行类型转换。因C++编译器在编译检查一般都能通过；
- C语言中**不能隐式类型转换**的，在c++中可以用reinterpret_cast<>() 进行强行类型解释。
- reinterpret_cast<>()很难保证移植性。
- dynamic_cast<>()，**动态类型转换**，安全的基类和子类之间转换；**运行时类型检查**；一般用于检查参数能否转化我特定的子类。
```c++
void ObjPlay(Animal *base) // 参数为一个父类
{
	base->cry();
	Dog *pDog = dynamic_cast<Dog *>(base); // 判断是否是某个子类
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
```
- const_cast<>()，去除变量的**只读属性**
```c++
//典型用法 把形参的只读属性去掉
void Opbuf(const char *p)
{
	cout << p << endl;
	char *p2 = const_cast<char*>(p);
	p2[0] = 'b';
	cout << p << endl;
}

const char *p1 = "11111111111"; // 只读

char *p2 = "22222222"; // 可读

char *p3 = const_cast<char *>(p1); // 去只读属性
char buf[100] = "aaaaaaaaaaaa"; 

//要保证指针所执行的内存空间能修改才行 若不能修改 还是会引起程序异常
//Opbuf("dddddddddddsssssssssssssss"); // 因为”dddd.."是在字符表中的，没有内存空间，不可以修改
```
3. 总结
- static_cast<>()和reinterpret_cast<>() 基本上把C语言中的 强制类型转换给覆盖
- 程序员要清除的知道: 要转的变量，类型转换前是什么类型，类型转换后是什么类型。转换后有什么后果。
- **一般情况下，不建议进行类型转换；避免进行类型转换**
# 异常Exception
- 异常是一种程序控制机制，与函数机制独立和互补
- 异常在错误处理方面活动最大的好处
## 传统错误处理机制
- 通过返回值，对不同的返回值处理，确定在于不够直观，也让返回值变成了错误处理机制，而不是需要的结果
## 异常处理的基本思想
- C++的异常处理机制使得异常的引发和异常的处理不必在同一个函数中，这样底层的函数可以着重解决具体问题，而不必过多的考虑异常的处理。上层调用者可以再适当的位置设计对不同类型异常的处理。
- 异常超脱于函数机制，决定了其对函数的**跨越式回跳**。
## 语法
### 抛掷异常
```c++
void fun()
{
	...
	throw 表达式(一般是个类型或者对象)
	...
}
```
### 捕获异常并处理异常的程序段
```c++
try 
{
	复合语句 //需要捕获异常的代码
}
catch (异常类型声明)
{
	处理异常
}
catch (类型 （可选形参)
{
	异常处理
}
catch (...) // 匹配任何异常，一般是未知异常处理
{
	异常处理
	throw; //处理不了，往更上层调用抛出异常，让上层处理
}
...
```
1. 若有异常则通过throw操作**创建一个异常对象**并抛掷
2. 将可能抛出异常的程序段嵌在try块之中。控制通过正常的顺序执行到达try语句，然后执行try块内的保护段
3. 如果在保护段执行期间没有引起异常，那么跟在try块后的catch子句就不执行。程序从try块后跟随的最后一个catch子句后面的语句继续执行下去
4. **catch子句按其在try块后出现的顺序被检查**。匹配的catch子句将捕获并处理异常（或继续抛掷异常）
5. **如果匹配的处理器未找到，则运行函数terminate将被自动调用，其缺省功能是调用abort终止程序**
6. 处理不了的异常，可以在catch的最后一个分支，使用throw语法，向上扔
7. 异常机制与函数机制互不干涉，但捕捉的方式是**基于严格类型匹配**。捕捉相当于函数返回类型的匹配，而不是函数参数的匹配，所以捕捉不用考虑一个抛掷中的多种数据类型匹配问题。
8. **栈解旋(unwinding)**：异常被抛出后，从进入try块起，到异常被抛掷前，这期间在栈上的构造的所有对象，都会被自动析构。析构的顺序与构造的顺序相反。
### 异常接口声明
1. 为了加强程序的可读性，可以**在函数声明中列出可能抛出的所有异常类型**，如`void func() throw(A,B,C,D);` 这个函数func**能够且只能够抛出类型ABCD及其子类型的异常**;
2. 如果在函数声明中**没有包含异常接口声明**，则次函数可以抛掷任何类型的异常，如`void func();`;
3. 一个**不抛掷任何类型异常的函数**可以声明为`void func() throw();`
4. 如果一个函数抛出了它的异常接口声明所不允许抛出的异常，unexpected函数会被调用，该函数默认行为调用terminate函数中止程序。
### 抛出对象对象的异常
1. 抛出值对象`throw MyCat();` 记得是有括号的,捕捉时也需要用值去捕捉`catch(MyCat c)`, **抛出时会调用类的构造函数，捕获时调用类的赋值构造函数(因此要注意浅拷贝和深拷贝，默认的赋值构造函数是浅拷贝)**;
2. 抛出值对象`throw MyCat();`捕获时也需要用引用去捕捉`catch(MyCat &c)`，**抛出时会调用类的构造函数，捕获时获得构造函数创建的异常类型，不会进行赋值构造函数**;
3. 抛出对象指针`throw new MyCat();`, 捕获时也需要用指针去捕捉`catch(MyCat *c)`，**但因为是指针，涉及到资源的释放，需要在catch中手动的delete，不然容易造成内存泄漏（无法释放或为释放造成系统资源的浪费）**。
结论：C++编译器**通过throw 来产生对象**，C++编译器再执行对应的catch分支，**相当于一个函数调用，把实参传递给形参**。使用是最好**用引用去捕获，让c++gc去接管他们的声明周期，也避免了拷贝构造函数的问题**。
### 标准程序异常
1. 这些类以基类`Exception`开始，该基类提供了一个成员函数`what()`，用于返回错误信息（返回类型为const char *) 在`Exception`类中，`what()`函数的声明如下：
```
virtual const char* what() const throw();
```
# I/O
## 常用的IO类
![c++io类库中常用的流类](./picture/c++io类库中常用的流类.png)
## 与iostream类库有关的头文件
- iostream  包含了对输入输出流进行操作所需的基本信息
- fstream  用于用户管理的文件的I/O操作
- strstream  用于字符串流I/O
- stdiostream  用于混合使用C和C + +的I/O机制时，例如想将C程序转变为C++程序
- iomanip  在使用**格式化I/O**时应包含此头文件
## 标准IO流
- cout
1. cout不是C++预定义的关键字，它是ostream流类的对象，在iostream中定义
2. 输出时不必考虑数据是什么类型，系统会判断数据的类型，并根据其类型选择调用与之匹配的运算符重载函数
3. cout流在内存中对应开辟了一个**缓冲区**，用来存放流中的数据，当向cout流插 人一个endl时，不论缓冲区是否已满，都立即输出流中所有数据，然后插入一个换行符，并**刷新流（清空缓冲区）**。注意如果插人一个换行符'\n'，如`cout<<a<<"\n"`，则只输出和换行，而不刷新cout流(但并不是所有编译系统都体现出这一区别）
- cin
- cerr
1. cerr流对象是标准错误流，cerr流已被指定为与显示器关联
2. cerr是**不经过缓冲区**，直接向显示器上输出有关信息
- clog
1. clog流对象也是标准错误流，它是console log的缩写。它的作用和cerr相同，都是在终端显示器上显示出错信息.
2. clog中的信息存放在缓冲区中，缓冲区满后或遇endl时向显示器输出
### 标准输入流对象cin常用的函数
- `cin.get() //一次只能读取一个字符` 不会自动吸收多余的enter
- `cin.get(一个参数) //读一个字符` 不会自动吸收enter
- `cin.get(name, 256, '\n'); // 不会吸收缓存区的\n` 
- `cin.getline()` 获取一行数据`cin.getline(buf1, 256, '\n');`或者`cin.getline(buf1, 256)`读取一行字符到buf1中 会把结尾多余的\n吸收掉
- `cin.ignore(int num)` 忽略nun个字符输入
- `cin.peek()`  // 没有数据的时候会阻塞
- `cin.putback(char c)` // 放回一个字符到缓冲区中
### 标准输出流对象cout常用的函数
- cout.flush()
- cout.put(char c)
- cout.write(char* s, int len)
- cout.width(int n)
- cout.fill(char c)
- cout.setf(标记)
### c++ 格式化输出
- 借助cout自带的函数
- 借助 <iomanip中的函数>
![c++输入输入出流控制符](./picture/c++输入输入出流控制符.png)
## 文件IO
**文件打开需要关闭**
### 打开文件
所谓打开(open)文件是一种形象的说法，打开文件是指在文件读写之前做必要的准备工作，包括：
- 为文件流对象和指定的磁盘文件建立关联，以便使文件流流向指定的磁盘文件
- 指定文件的工作方式，如，该文件是作为输入文件还是输出文件，是ASCII文件还是二进制文件等
#### 调用文件流的成员函数open
- 调用成员函数open的一般形式：文件流对象.open(磁盘文件名, 输入输出方式);
- 参数“输入输出方式”可根据对象做缺省，如ofstream 一般是输出，默然输出
```c++
ofstream outfile;  //定义ofstream类(输出文件流类)对象outfile
outfile.open("f1.dat",ios::out);  //使文件流与f1.dat文件建立关联
```
#### 文件输入输出方式的设置
![c++文件输入输出方式设置值](./picture/c++文件输入输出方式设置值.png)
### 关闭文件
- 在对已打开的磁盘文件的读写操作完成后，应关闭该文件。关闭文件用成员函数close。如
`outfile.close( );  //将输出文件流所关联的磁盘文件关闭`.
- 所谓关闭，实际上是解除该磁盘文件与文件流的关联，原来设置的工作方式也失效，这样，就不能再通过文件流对该文件进行输入或输出.
### ASCII文件读写
如果文件的每一个字节中均以ASCII代码形式存放数据,即一个字节存放一个字符,这个文件就是ASCII文件(或称字符文件)。程序可以从ASCII文件中读入若干个字符,也可以向它输出一些字符。
- 使用`ofstream对象 <<`来进行文件的写。
- 使用C++流成员函数put输出单个字符
- 使用`>>`输出单个字符
- `input.get(txtbuff[1]) `读取单个字符
- `input.getline(txtbuff+2, 1024); // 不会读取\n进去`
- `ofstream::ofstream(constchar *filename, int mode = ios::out,int penprot = filebuf::openprot);` (**但这个接口似乎废除了，只有两个参数的**)
1. filename：　　要打开的文件名
2. mode：　　　　要打开文件的方式
3. prot：　　　　打开文件的属性
![openprot属性表](./picture/openprot属性表.png)
- 可以用“或”或者“+”把以上属性连接起来 ，如3或1|2就是以只读和隐含属性打开文件。
- `input.read(txtbuff+len, 1024); // 读取指定长度，如果太长只读取有效长度的数据`
### 对二进制文件的读写操作
- `output.write("这里的风景真好\n", 1024);` **写入指定长度的数据，如果`长度大于有效数据长度`，则会写入错误数据**
- **二进制文件不是以ASCII代码存放数据的**，它将内存中数据存储形式不加转换地传送到磁盘文件，因此它又称为**内存数据的映像文件**。因为文件中的信息不是字符数据，而是字节中的二进制形式的信息，因此它又称为**字节文件**。
- **在打开时要用ios::binary指定为以二进制形式传送和存储**
- 对二进制文件的读写**主要用istream类成员函数的read和write来实现**，他们的原型为：
1. `istream& read(char *buffer, int len);`
2. `ostream& write(const char *buffer, int len);`
- 使用时还是用fstream，只是读写时用的是`std::ios::binary`,读写的函数用`write(const char* buffer, int len); read(char *buffer, int len);`
```c++
// 测试二进制文件的读写
void test2()
{
    const char * outPath = "./testBinaryIO.txt";
    const char * inPath = "./test.txt";
    char buffer[1024 * 32];

	// 文件的二进制读写依旧使用fstream，但得指明二进制读写方式
    std::ifstream reader(inPath, std::ios::binary);
    reader.read(buffer, 1024 * 32);
    reader.close();
    std::ofstream writer(outPath, std::ios::binary | std::ios::app);
    writer.write(buffer, strlen(buffer));
    writer.close();
    
    std::ifstream reader1(outPath, std::ios::binary);
    reader.read(buffer, 1024 * 32);
    reader.close();
}
```
# STL(标准模板库)理论基础
## 基本概念
- STL的从广义上讲分为三类：algorithm（算法）、container（容器）和iterator（迭代器），`容器和算法通过迭代器可以进行无缝地连接`。几乎所有的代码都采 用了模板类和模板函数的方式，这相比于传统的由函数和类组成的库来说提供了更好的代码重用机会。在C++标准中，STL被组织为下面的13个头文 件：`<algorithm>、<deque>、<functional>、<iterator>、<vector>、<list>、<map>、<memory>、<numeric>、<queue>、<set>、<stack> 和<utility>`。
- `STL的一个重要特点是数据结构和算法的分离`
### STL详细的说有六大组件
1. 容器（Container)
2. 算法（Algorithm）
3. 迭代器（Iterator）
4. 仿函数（Function object）
5. 适配器（Adaptor）
6. 空间配制器（allocator）
### 容器
- 用来管理一组元素
- 主要的头文件有：
1. `<vector>`
2. `<list>`
3. `<deque>`
4. `<set>`
5. `<map>`
6. `<stack>`
7. `<queue>`
#### 容器的分类
- 序列式容器(Sequence containers):每个元素都有固定位置－－取决于插入时机和地点，和元素值无关。
> `vector、deque、list`
- 关联式容器(Associated containers):元素位置取决于特定的排序准则，和插入顺序无关
> `set、multiset、map、multimap`
![STL常用的数据结构](./picture/STL常用的数据结构.png)
### 迭代器




