<!-- TOC -->

- [Introduction](#introduction)
- [收获记录](#收获记录)
    - [001 =号赋值操作](#001-号赋值操作)
    - [002 单例模式](#002-单例模式)
    - [003 在二维数组中查找](#003-在二维数组中查找)
    - [007 中序和先序遍历结果重构二叉树](#007-中序和先序遍历结果重构二叉树)
    - [008 二叉树的下一个节点](#008-二叉树的下一个节点)
    - [009 用两个栈实现队列](#009-用两个栈实现队列)
    - [010 斐波那契额数列](#010-斐波那契额数列)
    - [011 旋转数组中的最小值](#011-旋转数组中的最小值)
    - [012 矩阵中的路径](#012-矩阵中的路径)
    - [013机器人的运动范围](#013机器人的运动范围)
    - [014剪绳子](#014剪绳子)
    - [015二进制中1的个数](#015二进制中1的个数)
    - [034 二叉树中和为某一值的路径](#034-二叉树中和为某一值的路径)
    - [036 二叉搜索树与双向链表](#036-二叉搜索树与双向链表)

<!-- /TOC -->
# Introduction
this a folder to code sword2offer as some exercises
# 收获记录
## 001 =号赋值操作
-  成员变量中如果含有指针，需要在初始化时赋值为`nullptr`,如果指针是字符指针，最好初始化为`'\0'`,如`m_pData = new char[1]; m_pData[0] = '\0'`.
- 用一个**字符指针**给另一个**字符指针**赋值的时候，需要先做判空处理，再用`strncpy`或者 `memncpy`去**复制内存**而不是复制指针。
- delete之前先判空
- 字符指针结尾为`'\0'`,`strlen`遇到`'\0'`停止计算长度，因此复制字符数组，需要长度再加1，把`'\0'`也复制进去.
- 对于指针内容不需要改变的，用const修饰
## 002 单例模式
- 单例的实现，需要**私有化构造函数**，产生和销毁单例，需要使用`static`修饰.
```C++
public:
    static LazySingleon* GetSingleon(){...};
    static void Destroy(){...};
private:
    static LazySingleon* m_Instance;
    static std::mutex m_Mutex;
```
- 成员中有被`static`修饰的变量，使用时需要在全局区声明初始化`HungrySingleon* HungrySingleon::instance = new HungrySingleon();`.
- 对于线程安全的懒汉模式，需要用到锁，需要两次判空，安全更有效。
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
- 使用`new`记得`delete`,指针不用`delete`不会触发他们的析构函数。
- 智能指针不能在定义类的使用使用，容易出问题，可以在初始化时使用。
## 003 在二维数组中查找
- 泛型`<>`符号需要与外层的`<>`隔开一个空格`>>`凑这么近是会报错的，需要写成`> >`.
- **开始问题前，需要先养成考虑测试用例是什么，再从简但的用例出发解决问题**
## 007 中序和先序遍历结果重构二叉树
- 先序遍历确定子树的根节点R，根据节点R在中序遍历找到左右子树的范围，递归构建
## 008 二叉树的下一个节点
- 中序遍历时的下一分节点
    - 当前节点有**右子树**，则下一个节点有右节点的最左节点
    - 没有**右子树**，则判断**当前节点**是不是**父节点**的右子树，如果是右子树，这接着往上判断父节点；如果是左子树，则返回父节点。
## 009 用两个栈实现队列
- 利用栈**先进后出**，模拟队列的**先进先出**，则需要用一个栈模拟进队，一个栈模拟出队列。
- **模板**。
    - 定义模板类需要在类之前申明`template <typename T1, typename T2>`
    - 在模板类外申明成员函数，也需要在方法前声明用到的模板`template <typename T>`
    - 在实例化使用的使用需要用到泛型`<typename>`指定实例化的具体类型。
## 010 斐波那契额数列
- 尾递归。一般的递归是**从上往下**，尾递归是**从下往上**，它把计算的表达式放在递归函数的参数列表里，从下往上计算，用另一个参数去控制递归结束。
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
## 011 旋转数组中的最小值
- 二分法变种，在两个排序的部分找到最小值，另类的终止条件，左边始终大于等于右边，不断逼近最小值
```c++
    while( numbers[l] >= numbers[r] ) // 
    {
        if(r - l <= 1) // 因为r ,l 的位置改变只能到mid 而不是mid-1 和mid + 1，需要额外的退出循环条件
        {
            mid = r;
            break;
        }
        mid = l + ((r - l) >> 1);
        if (numbers[mid] == numbers[r] && numbers[mid] == numbers[l]) // 在两个排序的部分找到最小值的特殊情况，改为顺序查询一次 
        {
            --r; //dont know minest one in which side,find it one by one from right to lefr
        }
        else if (numbers[mid] <= numbers[r])
        {
            r = mid;
        } 
        else 
        {
            l = mid;
        }
    }
```
## 012 矩阵中的路径
- 回溯法非常适合由多个步骤组成的问题，并且每个步骤都有多个选项，不断的重复选择，直到最终状态。**回溯法解决的问题的所有选项可以形象地用树状结构表示**回溯就是你选择一条路径，当走不通的时候，会原路返回选择其他的路径，如同遍历子树数目不确定的树去查找结果一样。
- 记住状态。这道题中，我们需要记住两个变量的状态 `pathLength`记录当前要识别的字符位置，`visited`标记哪些已经遍历过了。为了在递归中记录下来，传值采用的是引用和指针，并在每次走不通的时候，`--pathLength; visited[row * cols + col]=false;` 所谓**归来仍是少年**。
```c++
hasPath = hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited) || 
            hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited) ||
            hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited) ||
            hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited);
    
// this step is ok, however next step in not ok, than go back
if( !hasPath ) 
{
    --pathLength;
    visited[row * cols + col] = false;
}
```
- 一维数组表示二维数组。`rows, cols`从1开始，则`matrix[row][col]`（row 和 col从零开始）表示为`matrix[row * cols + col]`。
## 013机器人的运动范围
- 回溯法，用一个visited数组记录已经遍历过的地方，从头开始，上下左右遍历，约束好边界，用一个个小函数解决。
## 014剪绳子
- 动态规划。最好是 从上而下分析问题，自下而上计算，这样可以充分利用辅助数组。
- 贪心算法。需要有数学去证明这个贪心的选择是正确的。
- 剪绳子需要注意的是，整个绳子的长度值，与分割后再分割的长度计算。
```c++
// 整个长度对应的最大值
if (length < 2)
    return 0;
if (length == 2)
    return 1;
if (length == 3)
    return 2;

//开始分割后长度为x的部分对应的值，而整段对应的值是 0-0 1-0 2-1 3-2
int* maxPro = new int[length + 1]();
maxPro[0] = 0;
maxPro[1] = 1;
maxPro[2] = 2;
maxPro[3] = 3;
```
- 把剪绳子m段，简化为分为2段的问题
```c++
for (int i = 4; i <= length; ++i) // 从长度4 -> length计算
{
    max = 0;
    for (int j = 1; j <= i / 2; ++j) // 分割成多段 取i/2是因为对称了
    {
        int ret = maxPro[j] * maxPro[i - j];
        if (ret > max)
            max = ret;
    }
    maxPro[i] = max;
}

max = maxPro[length];
```
## 015二进制中1的个数
- 负数右移，高位补充的是1，左移补充0. 因此循环中用左移。
```c++
while (one)
{
    if (n & one)
        ++count;
    one = one << 1; // 右移one, 1的位置右移动，末尾补零
}
```
- n - 1让低位不断少一个1
```c++
int NumberOf1_Solution2(int n)
{
    int count = 0;
    while(n)
    {
        ++ count;

        // n - 1， 让最右边的 1 变为 0， 而其他的位置保持不变
        n = (n - 1) & n;
    }
    return count;
}
```
## 034 二叉树中和为某一值的路径
- 用栈1(vector模拟)来存放节点的路径，栈2(vector模拟)来存放当前路径之和。然后递归先序遍历。
    - 终止条件 1. 空节点 2. 叶子节点 && 路径之和等于目标值
    ```c++
    //终止条件
        if (nullptr == pRoot)
            return false;
        
        // 计算当前的和，并入值路径
        int sum = numPath.back() + pRoot->m_nValue;
        numPath.push_back(sum); // 和入栈
        nodePath.push_back(pRoot); // 节点不为空，则入栈
        if (nullptr == pRoot->m_pLeft && nullptr == pRoot->m_pRight && sum == target)
            return true;
    ```
    - 退出时，及得出栈，**归来仍是少年** 回溯法。
    ```c++
    // 这个节点没找到，退出，清除值路径记录
    numPath.pop_back();
    nodePath.pop_back();
    return false;
    ```
## 036 二叉搜索树与双向链表
- 思路一:中序遍历后得到排序的列表后再构建双向链表
- 思路二:中序遍历过程中构建双向链表
    - 需要一个双指针模拟当前排序列表list中的最后的节点`BinaryTreeNode** pLastNodeInList`,用双指针的原因是指针的指示会变的。
    - 递归中序遍历时，如何找到最左节点？
    ```c++
    // 递归遍历到当前节点的最左节点(最小值)
    if (pCurrent->m_pLeft != nullptr)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    ```
    - 构建双向链表,需要注意最后节点初始值是`nullptr`
    ```c++
    // 找到当前最小值，当前节点左指针指向上一个节点
    pCurrent->m_pLeft = *pLastNodeInList;

    // 最后节点的右节点指向，找到的当前最小节点
    if(*pLastNodeInList !=nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;
    ```
    - 更新列表最后的节点`*pLastNodeInList = pCurrent;`
    - 遍历右子树
- **对于二叉树的问题，大都逃不过前、中、后、层次，四种遍历 + 特殊的辅助数据 + 逻辑，因此可以先确定哪种遍历，写出该遍历，再进行修改，一次完整写出比较费脑，按着遍历走，可以减少思考**。
    
