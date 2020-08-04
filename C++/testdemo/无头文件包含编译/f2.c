#include <stdio.h>

void fun2()
{
    printf("i am fun2\n");
}

int main()
{
    fun2();
    fun1();
    printf("the result is %d\n", fun3(3));
    return 0;
}