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
## 003 在二维数组中查找
11. 泛型`<>`符号需要与外层的`<>`隔开一个空格`>>`凑这么近是会报错的，需要写成`> >`.
12. **开始问题前，需要先养成考虑测试用例是什么，再从简但的用例出发解决问题**
## 007 中序和先序遍历结果重构二叉树
13. 先序遍历确定子树的根节点R，根据节点R在中序遍历找到左右子树的范围，递归构建
## 008 二叉树的下一个节点
14. 中序遍历时的下一分节点
- 当前节点有**右子树**，则下一个节点有右节点的最左节点
- 没有**右子树**，则判断**当前节点**是不是**父节点**的右子树，如果是右子树，这接着往上判断父节点；如果是左子树，则返回父节点。
## 009 用两个栈实现队列
15. 利用栈**先进后出**，模拟队列的**先进先出**，则需要用一个栈模拟进队，一个栈模拟出队列。
16. **模板**。
- 定义模板类需要在类之前申明`template <typename T1, typename T2>`
- 在模板类外申明成员函数，也需要在方法前声明用到的模板`template <typename T>`
- 在实例化使用的使用需要用到泛型`<typename>`指定实例化的具体类型。
## 010 斐波那契额数列
17. 尾递归。一般的递归是**从上往下**，尾递归是**从下往上**，它把计算的表达式放在递归函数的参数列表里，从下往上计算，用另一个参数去控制递归结束。
- 尾递归的优点在于省略了不断开辟栈的消耗，不会造成栈溢出
```C++
long long Fibonacci_TailRecursive(int n, long long  n_2, long long n_1)
{
    if (n == 0)
        return n_2;
    return Fibonacci_TailRecursive(n-1, n_1, n_2 + n_1);
}
// 使用时从下往上计算，这里下是从0，1开始，计算到n
Fibonacci_TailRecursive(n, 0, 1);
```



