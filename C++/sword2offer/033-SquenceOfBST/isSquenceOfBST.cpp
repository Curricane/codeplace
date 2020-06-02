// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

/**
 * 测试用例
 * 1，空
 * 2，1个节点
 * 3，单边非BST 
 * 4，单边BST
 * 5，普通BST
 * 
*/

#include <iostream>

bool isSequenceBST(int* arr, int len);
int findLeftTreePos(int *arr, int root, int left, int right);
bool checkRight(int *arr, int root, int left, int right);
bool checkLeft(int *arr, int root, int left, int right);
bool isSequenceBST(int *arr, int left, int right);

bool isSequenceBST(int *arr, int len)
{
    if (len <= 0 || nullptr == arr)
        return false;
    
    return isSequenceBST(arr, 0, len - 1);
}

bool isSequenceBST(int *arr, int left, int right)
{
    if (left >= right)
        return true;
    int leftTreeEndPos = findLeftTreePos(arr, arr[right], 0, right-1);
    if (leftTreeEndPos == -2)
    {
        return false;
    }
    // 只有右子树 或者 左子树
    if (leftTreeEndPos == left - 1)
    {
        if (!checkRight(arr, arr[right], left, right-1))
            return false;
        return isSequenceBST(arr, left, right-1);
    } 
    else if(leftTreeEndPos == right-1)
    {
        if (!checkLeft(arr, arr[right], left, right-1))
            return false;
        return isSequenceBST(arr, left, right-1);
    }
    else
    {
        if (!checkRight(arr, arr[right], leftTreeEndPos+1, right-1))
            return false;
        bool lRet = isSequenceBST(arr, left, leftTreeEndPos);
        bool rRet = isSequenceBST(arr, leftTreeEndPos+1, right-1);
        return lRet && rRet;
    }  
}

int findLeftTreePos(int *arr, int root, int left, int right)
{
    
    int leftTreeEndPos;
    int i = left;
    for (; i <= right; ++i)
    {
        if (arr[i] < root)
        {
            leftTreeEndPos = i;
        }
        else if(arr[i] == root)
        {
            printf("有相同的值，不是BST\n");
            leftTreeEndPos = -2;
            return leftTreeEndPos;
        }
        else
        {
            break;
        }
    }

    // 都小于root，只有左子树
    if (i == right + 1)
    {
        leftTreeEndPos = right;
    } 
    else if (i == left)
    {
        leftTreeEndPos = left - 1;
    }
    return leftTreeEndPos;
}

// 判断右子树是不是都大于 根节点
bool checkRight(int *arr, int root, int left, int right)
{
    for (int i = left; i <= right; ++i)
    {
        if (arr[i] <= root)
            return false;
    }
    return true;
}

bool checkLeft(int *arr, int root, int left, int right)
{
    for (int i = left; i <= right; ++i)
    {
        if (arr[i] >= root)
            return false;
    }
    return true;
}



// ====================测试代码====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isSequenceBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
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
    Test8();

    return 0;
}
