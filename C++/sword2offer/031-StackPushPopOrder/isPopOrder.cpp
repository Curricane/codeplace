// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

/**
 * 测试用例：
 * 
 * 不存在重复的数字进栈
 * 1，1 2 3 4 5
 *      5 4 3 2 1
 *      1 2 3 4 5
 * 
 * 
*/

#include <stack>

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    if (nullptr == pPop || nullptr == pPush || nLength <= 0)
        return false;

    // 已经入栈的位置
    int posPushed = -1;

    // 用于模拟他们的入栈出栈
    std::stack<int> s;
    
    // 从出栈的第一个值判断
    for (int i = 0; i < nLength; ++i)
    {   
        // 当前的出栈值
        int nowPop = pPop[i];

        // 出栈值在push数组中的位置
        int nPos = -1;
        for (int j = 0; j < nLength; ++j)
        {
            if (pPush[j] == nowPop)
            {
                nPos = j;
                break;
            }     
        }

        // 在pPush数组中没找到，则参数有误
        if (nPos == -1)
        {
            printf("输入有误\n");
            return false;
        }

        // 当前出栈值 还没入栈，则入栈到nPos位置
        if (nPos > posPushed)
        {
            for (int k = posPushed + 1; k <= nPos; ++k)
            {
                s.push(pPush[k]);
            }
            posPushed = nPos;
        }
        else
        {
            int now = s.top();
            if (now != pPop[i])
                return false;
        }  

        // 当前的判断完了，出栈
        s.pop();
    }
    return true;
}

// 官方答案
bool IsPopOrder2(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;

    if(pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int> stackData;

        while(pNextPop - pPop < nLength)
        {
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while(stackData.empty() || stackData.top() != *pNextPop)
            {
                // 如果所有数字都压入辅助栈了，退出循环
                if(pNextPush - pPush == nLength)
                    break;

                stackData.push(*pNextPush);

                pNextPush ++;
            }

            if(stackData.top() != *pNextPop)
                break;

            stackData.pop();
            pNextPop ++;
        }

        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}


// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsPopOrder2(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
