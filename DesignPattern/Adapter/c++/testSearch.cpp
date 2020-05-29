#include "search.h"

void Test(const char* name, int mid, bool expeced)
{
    if ( (mid >= 0) ^ expeced )
    {
        printf("----------%s failed\n", name);
    }
    else 
    {
        printf("----------%s passed\n", name);
    }
}

void testBinarySearch1()
{
    int a[] = {1,1,1};
    int len = 3;
    int key = 1;
    BinarySearch s;
    int ret = s.search(a, len, key);
    Test("testBinarySearch1", ret, true);
}

void testBinarySearch2()
{
    int a[] = {1,2,3};
    int len = 3;
    int key = 1;
    BinarySearch s;
    int ret = s.search(a, len, key);
    Test("testBinarySearch1", ret, true);
}

void testBinarySearch3()
{
    int a[] = {1,4,9, 10, 12};
    int len = 5;
    int key = 3;
    BinarySearch s;
    int ret = s.search(a, len, key);
    Test("testBinarySearch1", ret, false);
}

int main()
{
    testBinarySearch1();
    testBinarySearch2();
    testBinarySearch3();
}