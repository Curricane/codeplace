// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <iostream>

long long Fibonacci_Normal(unsigned int n)
{
    if ( n <= 1 )
        return n;
    else
    {
        return Fibonacci_Normal(n-1) + Fibonacci_Normal(n - 2);
    }
}


long long Fibonacci_Loop(unsigned int n)
{
    if (n <= 1)
        return n;
    
    long long n_2 = 0;
    long long n_1 = 1;
    long long result;
    
    for (int i = 2; i <= n; i++)
    {
        result = n_2 + n_1;
        n_2 = n_1;
        n_1 = result;
    }
    return result;
}

/**
 * this is a solution used tail recursive
 * the essence: tail recursive is to put the current operation result(or path, maybe a array) 
 * int the parameter, and pass it to the lower layer function.
 * the terminal condition,will always in the paramter ,just like this function's n parameter.
 * n determine to ternimal the recursive
 * n_2 is value of the terminal condition
 * 
*/
long long Fibonacci_TailRecursive(int n, long long  n_2, long long n_1)
{
    if (n == 0)
        return n_2;
    return Fibonacci_TailRecursive(n-1, n_1, n_2 + n_1);
}

// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci_Normal(n) == expected)
        printf("Test for %d in Fibonacci_Normal passed.\n", n);
    else
        printf("Test for %d in Fibonacci_Normal failed.\n", n);

    if(Fibonacci_Loop(n) == expected)
        printf("Test for %d in Fibonacci_Loop passed.\n", n);
    else
        printf("Test for %d in Fibonacci_Loop failed.\n", n);

    if(Fibonacci_TailRecursive(n, 0, 1) == expected)
        printf("Test for %d in Fibonacci_TailRecursive passed.\n", n);
    else
        printf("Test for %d in Fibonacci_TailRecursive failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}