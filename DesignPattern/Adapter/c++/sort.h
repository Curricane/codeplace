#include <iostream>

// 快速排序类：适配者adaptee
class QuickSort
{
public:
    void sort(int *array, int length);
    QuickSort();
    ~QuickSort();
    void sort(int *array, int left, int right);
};