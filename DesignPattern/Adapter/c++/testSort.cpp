#include "sort.h"

#include <iostream>

void print(int *a, int len);

void Test(const char* name, int* array, int* expected, int length)
{
    bool result = true;
    for (int i = 0; i < length; ++i)
    {
        if(array[i] != expected[i])
            result = false;
            break;
    }

    if (result)
    {
        printf("-------------------%s passed\n", name);
    }
    else
    {
        printf("-------------------%s failed\n", name);
        print(array, length);
    }
}

void testQuickSort1()
{
    int a[] = {1,1,1,1,1,1};
    int b[] = {1,1,1,1,1,1};
    int length = 6;
    QuickSort s;
    s.sort(a, length);
    Test("testQuickSort1", a, b, length);
}

void testQuickSort2()
{
    int a[] = {1};
    int b[] = {1};
    int length = 1;
    QuickSort s;
    s.sort(a, length);
    Test("testQuickSort2", a, b, length);
}

void testQuickSort3()
{
    int a[] = {4, 1, 3, 6, 5, 2};
    int b[] = {1, 2, 3, 4, 5, 6};
    int length = 6;
    QuickSort s;
    s.sort(a, length);
    Test("testQuickSort3", a, b, length);
}

void print(int *a, int len)
{
    if (nullptr == a || len <= 0)
        return;
    for (int i = 0; i < len; ++i)
        printf("3%d", a[i]);
    printf("\n");
}

int main()
{
    testQuickSort1();
    testQuickSort2();
    testQuickSort3();
}