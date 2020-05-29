#include "sort.h"

void QuickSort::sort(int *array, int length)
{
    if (nullptr == array || length <= 0)
        return;

    sort(array, 0, length-1);
}
QuickSort::QuickSort()
{
    std::cout << "QuickSort created" << std::endl;
}
QuickSort::~QuickSort()
{
    std::cout << "bye QuickSort" << std::endl;
}
void QuickSort::sort(int *array, int left, int right)
{
    if (left >= right)
        return;

    int l = left;
    int r = right;
    int temp = array[l];
    while (l < r)
    {
        while(l < r && array[r] >= temp)
            --r;
        if (l < r && array[r] < temp)
        {
            array[l] = array[r];
            l++;
        }
        while(l < r && array[l] < temp)
        {
            ++l;
        }
        if (l < r && array[l] >= temp) 
        {
            array[r] = array[l];
            --r;
        }
    }
    array[l] = temp;

    sort(array, left, l - 1);
    sort(array, l + 1, right); 
}