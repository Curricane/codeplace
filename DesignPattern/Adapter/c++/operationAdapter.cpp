#include "operationAdapter.h"

void OperationAdapter::sort(int* array, int length)
{
    mQuickSort.sort(array, length);
}

int OperationAdapter::search(int *array, int length, int key)
{
    int ret = mBinarySearch.search(array, length, key);
    return ret;
}