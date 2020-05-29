#include "scoreAdapter.h"
#include "sort.h"
#include "search.h"

#include <iostream>

class OperationAdapter:public ScoreOperation
{
public:
    void sort(int* array, int length);
    int search(int *array, int length, int key);
    OperationAdapter()
    {
        std::cout << "OperationAdapter created" << std::endl;
    }
    ~OperationAdapter()
    {
        std::cout << "bye OperationAdapter" << std::endl;
    }

private:
    QuickSort mQuickSort;
    BinarySearch mBinarySearch;
};