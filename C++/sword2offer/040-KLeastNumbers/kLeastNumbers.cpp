// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

// 测试用例：
// 1，空数组，k<=0
// 2，数组长度为1
// 3，数组长度 = k
// 4，正常数组 k正常
// 5，数组值都相等

// 思路一：
// 用优先级队列

// 思路二：
// 用快速排序的变种，排序前K个

// 思路三：
// 直接先排序后取前K个

#include <queue>
#include <vector>
#include <set>
#include <exception>

using namespace std;

int Partition(int data[], int length, int start, int end);

// 使用优先级队列
void GetLeastNumbers_Solution1(int* input, int n, int* output, int k)
{
    if (nullptr == input || n <= 0 || output == nullptr || k <= 0)
        return;

    // priority_queue(beg,end)
    // std::priority_queue<int, std::vector<int>, std::greater<int> > priorQ(input, input + n);
    

    // 默认构造函数
    std::priority_queue<int, std::vector<int>, std::greater<int> > priorQ;
    for (int i= 0; i < n; i++)
        priorQ.push(input[i]);

    for (int i = 0; i < k; ++i )
    {
        output[i] = priorQ.top();
        priorQ.pop();
    }
}


// 快速排序的变体
void GetLeastNumbers_Solution2(int* input, int n, int* output, int k)
{
    if (nullptr == input || n <= 0 || output == nullptr || k <= 0)
        return;
    
    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while(index != k - 1)
    {
        if(index > k - 1)
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for(int i = 0; i < k; ++i)
        output[i] = input[i];
}

int Partition(int data[], int length, int start, int end)
{
    if(data == nullptr || length <= 0 || start < 0 || end >= length)
        throw "Invalid Parameters";
    
    int temp = data[start];
    while(start < end)
    {
        while(start < end && data[end] >= temp )
            --end;
        data[start] = data[end];
        while(start < end && data[start] < temp)
            ++start;
        data[end] = data[start];
    }
    data[start] = temp;
    return start;
}


// ====================测试代码====================
void Test(const char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    std::vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int* output = new int[k];
    GetLeastNumbers_Solution1(data, n, output, k);
    if(expectedResult != nullptr)
    {
        for(int i = 0; i < k; ++ i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}