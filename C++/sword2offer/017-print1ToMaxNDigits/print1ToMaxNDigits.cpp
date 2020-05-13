// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

/**
 * 测试用的值：
 *  1，0 直接返回
 *  2，20 溢出
 *  3，-3 直接返回
 *  4，5 正常打印
 * 
 * 解决溢出-》拼接成字符串打印
 * 难点：如何拼接字符串
*/

//#include <cstdio>
#include <memory>

//字符串number表示一个数字，在number上增加1
//如果做法溢出，则返回true；否则返回false
bool Increment(char* number)
{
    //判断是否超过了number能表达的值
    bool isOverflow = false;
    int nTakeOver = 0; //十进一
    int nLength = strlen(number);

    //低位在数组的高下标
    for (int i = nLength - 1; i >= 0; --i)
    {
        int nSum = number[i] - '0' + nTakeOver; 

        //个位处+1
        if (i == nLength - 1)
            ++nSum; 

        // number[i]对应的整数值 + 1 > 9，需要进位，保留个位
        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nTakeOver = 1;
                nSum -= 10;
                number[i] = '0' + nSum;
            }  
        } 
        else
        {
            //没有进项 结束循环
            number[i] = '0' + nSum; 
            break;
        }
        
    }

    return isOverflow;
}

// 字符串number表示一个数字，数字有若干个0开头
// 打印的时候忽略开头的多个0
void PrintNumber(char* number)
{
    int len = strlen(number);
    if (len <= 0)
        return;
    
    bool isBegin = true;
    for (int i = 0; i < len; ++i)
    {
        if (isBegin && number[i] == '0')
            continue;
        
        isBegin = false;
        printf("%c", number[i]);
    }
    printf("\t");
}

void Print1ToMaxOfNDigits_1(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n + 1];
    memset(number, '0', n); // 置为0，不然会使'\0'打印不出来
    number[n] = '\0';

    while(!Increment(number))
    {
        PrintNumber(number);
    }

    delete [] number;
}


// 方法二 利用递归
void Print1ToMaxOfNDigits_recursive(int len, int index, char *number)
{
    // 此处终止条件，因为总是把index这位处理好了
    if (index == len - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = '0' + i;
        Print1ToMaxOfNDigits_recursive(len, index+1, number);
    }
}

void Print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n + 1];
    //memset(number, '0', n);
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = '0' + i; // 数是对称的 
        Print1ToMaxOfNDigits_recursive(n, 0, number);
    }

    delete [] number;
}


// ====================测试代码====================
void Test(int n)
{
    printf("\nTest for %d begins:\n", n);
    printf("\n1: \n");
    Print1ToMaxOfNDigits_1(n);
    printf("\n2: \n");
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
