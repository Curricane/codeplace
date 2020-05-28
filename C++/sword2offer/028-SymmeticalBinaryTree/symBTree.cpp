// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。

/**
 * 测试用例
 * 1，空
 * 2，一个节点
 * 3，对称单边树
 * 4，全节点
 * 5，不对称的树
*/
#include "BinaryTree.h"

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool isSymmerical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool isSymmerical(BinaryTreeNode* pRoot)
{
    return isSymmerical(pRoot, pRoot);
}

bool isSymmerical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (nullptr == pRoot1 && nullptr == pRoot2)
        return true;
    
    if(nullptr == pRoot1 || nullptr ==pRoot2)
        return false;
    
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    
    return isSymmerical(pRoot1->m_pLeft, pRoot2->m_pRight) 
        && isSymmerical(pRoot1->m_pRight, pRoot2->m_pLeft);
}


// =========测试代码==========
void Test(const char* name, BinaryTreeNode* A, bool expected)
{
    printf("%s \n", name);
    printf("输入的树：\n");
    PrintBinaryTree(A);
    printf("\n");

    //MirrorIteratively(A);
    bool ret = isSymmerical(A);

    if(expected == ret)
    {
        printf("---------------------------------passed\n");
    }
    else
    {
        printf("---------------------------------failed\n");
    }
    DestroyTree(A);
}

void Test1()
{
    Test("test1", nullptr, true);
}

// 一个节点的树
void Test2()
{
    BinaryTreeNode *A = new BinaryTreeNode(1);
    Test("test2", A, true);
}

// 不对称的树
void Test3()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> arr(a, a+15);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    
    Test("test3", A, false);
}

// 对称的树
void Test4()
{
    int a[] = {1,2,2};
    vector<int> arr(a, a+3);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    Test("test4", A, true);
}

void Test5()
{
    int a[] = {8,6,6,5,7,7,5};
    vector<int> arr(a, a+7);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    Test("test5", A, true);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}