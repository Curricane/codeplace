#include <iostream>

class BinarySearch
{
public:
    BinarySearch()
    {
        std::cout << "BinarySearch created" << std::endl;
    }

    ~BinarySearch()
    {
        std::cout << "bye BinarySearch" << std::endl;
    }

    int search(int *array, int len, int key);
};