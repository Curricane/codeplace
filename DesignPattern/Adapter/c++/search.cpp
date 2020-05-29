#include "search.h"

int BinarySearch::search(int *a, int len, int key)
{
    if (nullptr == a || len <= 0)
        return -1;

    int l = 0;
    int r = len - 1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (a[mid] == key)
            return mid;
        else if(a[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }  
    }
    return -1;
}