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
    int iArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vecIntA(iArray, iArray + 9);
    vector<int>::iterator it1 =  vecIntA.begin() + 2;
    cout << *it1 << endl; // 3
    vector<int>::iterator it2 =  vecIntA.erase(vecIntA.begin() + 2);
    cout << *it1 << endl; // 4
    cout << *it2 << endl; // 4
    cout << "vecIntA: ";
    printVector(vecIntA); //vecIntA: 1 2 4 5 6 7 8 9 
    cout << endl;

    vecIntA.erase(it2, it2 + 2);
    cout << "vecIntA: ";
    printVector(vecIntA); // vecIntA: 1 2 6 7 8 9
    cout << endl;

    vecIntA.push_back(2);
    vecIntA.push_back(2);
    vecIntA.push_back(9);
    vecIntA.push_back(9);

    // 用迭代器遍历删除的时候需要注意
    for (vector<int>::iterator it = vecIntA.begin(); it != vecIntA.end(); ) //小括号里不需要写 ++it
    {
        if (*it == 2)
        {
            it = vecIntA.erase(it); // 最好是返回给自己
        }
        else
        {
            ++it; 
        }
    }
    cout << "vecIntA: ";
    printVector(vecIntA); // 1 6 7 8 9 9 9
    cout << endl;
}

void test4()
{
    int iArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vecIntA(iArray, iArray + 9);
    vecIntA.insert(vecIntA.end(), 10);
    int arr[] = {11, 12, 13, 14, 15};
    vector<int> vecIntB(arr, arr + 2);
    vecIntA.insert(vecIntA.end(), 3, 0);
    vecIntA.insert(vecIntA.end(), vecIntB.begin(), vecIntB.end());
    vecIntA.insert(vecIntA.end(), arr + 2, arr + 5);
    cout << "vecIntA: ";
    printVector(vecIntA); // vecIntA: 1 2 3 4 5 6 7 8 9 10 0 0 0 11 12 13 14 15
    cout << endl;
}

int main()
{
    // test1();
    // test2();
     test3();
    // test4();
}