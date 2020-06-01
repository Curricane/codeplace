// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。



#include "minStack.h"


/**
 * 测试思路：
 * 1，入栈 0 1 3 2 -1 -1 -1， 最小值分别是 0 0 0 0 -1 -1 -1
 * 2，入栈 9 8 7 6 5 4 3 2 1， 最小值分别是 9 8 7 6 5 4 3 2 1
 * 3，入栈 1 2 3 4 5 6 7 8， 最小值分别是 1 1 1 1 1 1 1 1
*/

/**
 * 设计思路：
 * 用两个栈，一个栈A正常出入栈数据，另一个栈B入栈小于或等于栈顶的值
 * A出栈时，需要对比B栈的栈顶，如果小于等于B栈顶，则B也出栈
*/

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);

    return 0;
}
