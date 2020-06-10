// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

// 测试用例：
// 1. 空数组
// 2. 长度为1de数组
// 3. 长度为2的数组
// 4. 长度为奇数的正常数组 含有
// 5. 长度为奇数的正常数组 不含有
// 6. 长度为偶数的正常数组 含有
// 7. 长度为偶数的正常数组 不含有

// 思路1：
// 1. 排序后找中间位置的值，统计它是不是超过了长度一半

// 思路1：
// 1. 排序后找中间位置的值，二分的变体查找它的起始位置，
// 看他的长度是不是超过了长度的一半

#include <iostream>

void quickSortCore(int* arr, int l, int r);
void quickSort(int *arr, int len);
void printArr(int *arr, int len);
int BinarySearchStartPos(int *arr, int len, const int target);
int BinarySearchEndPos(int *arr, int len, const int target);

int MoreThanHalfNum_Solution1(int *nums, int len)
{
    if(nullptr == nums || len <= 0)
        return 0;
    quickSort(nums, len);
    int halfNum = nums[len / 2];
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (nums[i] == halfNum)
            ++count;
    }
    if (count > len / 2)
        return halfNum;
    
    return 0;
}

int MoreThanHalfNum_Solution2(int *nums, int len)
{
    if(nullptr == nums || len <= 0)
        return 0;
    quickSort(nums, len);
    int halfNum = nums[len / 2];
    int startPos = BinarySearchStartPos(nums, len, halfNum);
    int endPos = BinarySearchEndPos(nums, len, halfNum);

    if (endPos - startPos + 1 > len / 2)
        return halfNum;

    return 0;
}

// 在有序数组总中找到 目标的起始下标
int BinarySearchStartPos(int *arr, int len, const int target)
{
    if (nullptr == arr || len <= 0)
        return -1;
    int start = 0;
    int end = len - 1;
    int mid;
    while(start <= end)
    {
        mid= start + ((end - start) >> 2);
        if (arr[mid] == target)
        {
            // 关键一步，判断是不是开头
            if (mid == 0 || arr[mid - 1] != target)
                return mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (arr[start] == target)
        return start;
    return -1;
}

// 在有序数组总中找到 目标的结束下标
int BinarySearchEndPos(int *arr, int len, const int target)
{
    if (nullptr == arr || len <= 0)
        return -1;
    int start = 0;
    int end = len - 1;
    int mid;
    while(start <= end)
    {
        mid= start + ((end - start) >> 2);
        if (arr[mid] == target )
        {
            // 关键一步，判断是不是结尾
            if (mid == len -1 || arr[mid + 1] != target)
                return mid;
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (arr[start] == target)
        return start;
    return -1;
}



void quickSortCore(int* arr, int l, int r)
{
    int start = l;
    int end = r;
    if (start >= end)
        return;
    int a = arr[start];
    while(start < end)
    {
        // 双向扫描，选择头为pivot，则先从末尾开始扫描
        while(start < end && arr[end] >= a)
        {
            --end;
        }
            
        arr[start] = arr[end]; // 不用担心越界问题，最多start == end
        //++start; // 不加if判断不能写这条语句
 
        while(start < end && arr[start] < a)
        {
            ++start;
        }
            
        arr[end] = arr[start];
        //-- end; 
    }

    arr[start] = a;

    quickSortCore(arr, l, start - 1);
    quickSortCore(arr, start + 1, r);
}

void quickSort(int *arr, int len)
{
    if (nullptr == arr || len <= 0)
        return;
    quickSortCore(arr, 0, len - 1);
}

void printArr(int *arr, int len)
{
    if (nullptr == arr || len <= 0)
        return;
    for (int i = 0; i < len; ++i)
    {
        std::cout << arr[i];
    }

}

void TestQuickSort()
{
    int arr1[] = {2, 9 , 4, 6};
    int arr2[] = {1};
    int arr3[] = {2,2,2, 1,1,1,1};

    quickSort(arr1, 4);
    quickSort(arr2, 1);
    quickSort(arr3, 7);

    std::cout << "arr1 :";
    printArr(arr1, 4);
    std::cout << std::endl;

    std::cout << "arr2 :";
    printArr(arr2, 1);
    std::cout << std::endl;

    std::cout << "arr3 :";
    printArr(arr3, 7);
    std::cout << std::endl;

}

// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Solution2(numbers, length);
    if(result == expectedValue )
        printf("Passed.\n");
    else
        printf("Failed.\n");

    // printf("Test for solution2: ");
    // result = MoreThanHalfNum_Solution2(copy, length);
    // if(result == expectedValue )
    //     printf("Passed.\n");
    // else
    //     printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    TestQuickSort();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}


