// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <iostream>
#include <cstdio>
#include <string>
using std::cout;
using std::endl;
using std::string;
int NumberOf1_Solution1(int n)
{
    int count = 0;
    unsigned int one = 1;
    // while(n)
    // {
    //     if((n & one) == 1)
    //         ++count;
    //     n = n >> 1; //通过左移 n，当n为负数的时候，就会无限循环
    // }
    while (one)
    {
        if (n & one)
            ++count;
        one = one << 1; // 右移one, 1的位置右移动，末尾补零
    }
    return count;
}

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

string decimal2Binary(int n)
{
    // 如果用char数组转化为string，最后一个值要为'\0'不然会出问题
    // char a[33];
    // int i = 0;
    // for (; i< 32; ++i)
    // {
    //     a[i] = '0';
    // }
    // a[32] = '\0';

    //用这种办法也需要最后的值为'\0'
    char* a = new char[33]; 
    int i = 0;
    for (; i < 32; ++i) //初始化不可少
        a[i] = '0';
    a[32] = '\0';
    i = 31;
    unsigned int one = 1;
   
    while (one && i >= 0) 
    {
        
        if (n & one)
            a[i] = '1';
        --i;
        one = one << 1; 
    }
    string s(a);
    delete [] a;
    return s; 
}

// ====================测试代码====================
void Test(int n, unsigned int expected)
{
    int actual = NumberOf1_Solution1(n);
    if (actual == expected)
        //printf("Solution1: Test for %X passed.\n", n);
        cout << "Solution1: Test for " << decimal2Binary(n) << " passed get ones: " << actual << endl;
    else
    {
        printf("Solution1: Test for %X failed.\n", n);
    }

    int actual1 = NumberOf1_Solution2(n);
    if (actual1 == expected)
        //printf("Solution1: Test for %X passed.\n", n);
        cout << "Solution2: Test for " << decimal2Binary(n) << " passed get ones: " << actual1 << endl;
    else
    {
        printf("Solution2: Test for %X failed.\n", n);
    }
    
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}