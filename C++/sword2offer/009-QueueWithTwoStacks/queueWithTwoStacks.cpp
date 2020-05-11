// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <stack>
#include <cstdio>
using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void push_back(const T& node);

    T pop_head();

private:
    stack<T> sIn;
    stack<T> sOut;
};

template <typename T> 
CQueue<T>::CQueue(void)
{
};

template <typename T>
CQueue<T>::~CQueue<T>(void)
{
}

template <typename T>
void CQueue<T>::push_back(const T& node)
{
    sIn.push(node);
}

template <typename T>
T CQueue<T>::pop_head()
{
    if(sOut.size() <= 0)
    {
        while(sIn.size() > 0)
        {
            T &data = sIn.top();
            sIn.pop();
            sOut.push(data);
        }
    }

    if(sOut.size() == 0)
        throw -1;

    T head = sOut.top();
    sOut.pop();

    return head;
}

void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main()
{
    CQueue<char> q;

    q.push_back('a');
    q.push_back('b');
    q.push_back('c');
    q.push_back('d');

    char head = q.pop_head();
    Test(head, 'a');

    head = q.pop_head();
    Test(head, 'b');

    head = q.pop_head();
    Test(head, 'c');

    return 0;
}


