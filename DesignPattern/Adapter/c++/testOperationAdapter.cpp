#include "operationAdapter.h"

#include <iostream>

void Test()
{
    ScoreOperation* s;
    s = new OperationAdapter();
    int scores[] = {84,76,50,69,90,91,88,96};

    s->sort(scores, 8);

    printf("排序后\n");
    for (int i = 0; i < 8; ++i)
    {
        printf("%3d", scores[i]);
    }
    printf("\n");

    int key = 90;
    int ret = s->search(scores, 8, key);
    if (ret >= 0)
        printf("find key: %3d, locat at %d\n", key, ret);
    else
    {
        printf("here is no %3d\n", key);
    }
    
}

int main()
{
    Test();
}