// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。


#include <iostream>
#include <exception>
#include <cstdio>

/* error 
// 
int Min_v1(int* numbers, int length)
{
    if (nullptr == numbers || length <= 0)
    {
        throw -1;
    }

    if ( numbers[0] < numbers[length - 1])
        return numbers[0];
    
    int min = numbers[length - 1];
    int l = 0;
    int r = length - 1;
    
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if (numbers[mid] <= min) // because you use min ,it is diffirent to normal divisive;cause some num for get to compare
        {
            min = numbers[mid];
            r = r - 1;
        }
        else
        {
            l = mid + 1;
        } 
    }

    return min;
}
*/

int Min_v1(int* numbers, int length)
{
    if (nullptr == numbers || length <= 0)
    {
        throw -1;
    }
 
    int l = 0;
    int r = length - 1;
    int mid = l;
    
    while( numbers[l] >= numbers[r] )
    {
        if(r - l <= 1)
        {
            mid = r;
            break;
        }
        mid = l + ((r - l) >> 1);
        if (numbers[mid] == numbers[r] && numbers[mid] == numbers[l])
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

    return numbers[mid];
}

// ====================测试代码====================
void Test(int *numbers, int length, int expected)
{
    int result1 = 0;
    try
    {
        result1 = Min_v1(numbers, length);
        for (int i = 0; i < length; ++i)
        {
            printf("%3d", numbers[i]);
        }

        if(result1 == expected)
            printf("\tpassed\n");
        else
        {
            printf("\tfailed\n");
        }
    }
    catch(...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
    
}

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(nullptr, 0, 0);

    // 
    int array7[] = {1, 1, 1, 1, 1, 1, 1 ,1 , 0, 1 };
    Test(array7, sizeof(array7) / sizeof(int), 0);

    // 数组中只有一个数
    int array8[] = {1, 1, 1, 1, 1, 1, 1 ,1 , 1, 1 };
    Test(array8, sizeof(array8) / sizeof(int), 1);

    return 0;
}

int bsearch(int a[], int n, int value)
{
    int low = 0;
    int hight = n-1;

    while( low <= hight)
    {
        int mid = low + ((hight - low) >> 1);
        if (a[mid] == value)
            return mid;
        else if (a[mid] < value)
            low = mid + 1;
        else
        {
            hight = mid - 1;
        } 
    }
    return -1;
}