#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T>
void printVector(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
}

void test1()
{
    // 有参构造函数
    int iArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vecIntA(iArray, iArray + 9);
    cout << "vecIntA: ";
    printVector(vecIntA);
    cout << endl;

    vector<int> vecIntB(vecIntA.begin(), vecIntA.end());
    cout << "vecIntB: ";
    printVector(vecIntB);
    cout << endl;

    vector<int> vecIntC(9, 1);
    cout << "vecIntC: ";
    printVector(vecIntC);
    cout << endl;

    // vecIntA: 1 2 3 4 5 6 7 8 9 
    // vecIntB: 1 2 3 4 5 6 7 8 9 
    // vecIntC: 1 1 1 1 1 1 1 1 1
}

// 测试 swap
void test2()
{
    vector<int> vecIntA(9, 0);
    vector<int> vecIntB(9, 1);
    vector<int> vecIntC;

    vecIntA.swap(vecIntB);
    cout << "vecIntA: ";
    printVector(vecIntA);
    cout << endl;
    cout << "vecIntB: ";
    printVector(vecIntB);
    cout << endl;
    // vecIntA: 1 1 1 1 1 1 1 1 1 
    // vecIntB: 0 0 0 0 0 0 0 0 0

    vecIntA.swap(vecIntC);
    cout << "vecIntA: ";
    printVector(vecIntA);
    cout << endl;
    cout << "vecIntC: ";
    printVector(vecIntC);
    cout << endl;
    // vecIntA: 
    // vecIntC: 1 1 1 1 1 1 1 1 1 
}

void test3()
{
    
}

int main()
{
    // test1();
    test2();
}