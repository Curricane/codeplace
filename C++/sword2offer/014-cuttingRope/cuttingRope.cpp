// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int maxCuttingCore(int length, int maxPro[]);

int maxProductAfterCutting_Dynamic(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;

    // a array to record maxProduct value of segment rope 
    // what you need to pay attention to is that here is the value after
    // segmentation, not a whole value. such as 2 in whole rope is 1,but 
    // segmentation is 2.
    int* maxPro = new int[length + 1]();
    maxPro[0] = 0;
    maxPro[1] = 1;
    maxPro[2] = 2;
    maxPro[3] = 3;
    int ret = maxCuttingCore(length, maxPro);
    delete[] maxPro;
    return ret;
}

int maxCuttingCore(int length, int maxPro[])
{
    if (maxPro[length] > 0)
        return maxPro[length];
    
    int half = length / 2;
    int maxRet = 0;
    for (int i = 1; i <= half; ++i)
    {
        // 小的放前面计算会快一点，但还没充分使用动态规划
        int ret = maxCuttingCore(i, maxPro) * maxCuttingCore(length - i, maxPro);
        if (maxRet < ret)
            maxRet = ret;
    }
    maxPro[length] = maxRet;
    return maxRet;
}

int maxProductAfterCutting_Dynamic1(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;

    // a array to record maxProduct value of segment rope 
    // what you need to pay attention to is that here is the value after
    // segmentation, not a whole value. such as 2 in whole rope is 1,but 
    // segmentation is 2.
    int* maxPro = new int[length + 1]();
    maxPro[0] = 0;
    maxPro[1] = 1;
    maxPro[2] = 2;
    maxPro[3] = 3;

    int max;
    // 动态规划 最好是 从上而下分析问题， 自下而上计算，这样可以从分利用 辅助数组
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
    delete[] maxPro;
    return max;
}

// ==============测试代码============
void test(const char* testName, int length, int expectd)
{
    int result1 = maxProductAfterCutting_Dynamic(length);
    if (result1 == expectd)
        cout << "_Dynamic for " << testName << " passed." << endl;
    else
    {
        cout << "_Dynamic for " << testName << " failed we expected " 
        << expectd << " you get " << result1 << endl;
    }

    int result2 = maxProductAfterCutting_Dynamic1(length);
    if (result1 == expectd)
        cout << "_Dynamic1 for " << testName << " passed." << endl;
    else
    {
        cout << "_Dynamic1 for " << testName << " failed we expected " 
        << expectd << " you get " << result2 << endl;
    }
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
}