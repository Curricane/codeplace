// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

#include "BinaryTree.h"

#include <iostream>
#include <vector>
/**
 * 测试用例
 * 1，两个空树 否
 * 2，A非空，B空 否
 * 3，B是A的叶子节点 是
 * 4，B是A的左子树 是
 * 5，B是A的中间某一部分 是
 * 6, A = B
 * 
 * 检查代码
*/
bool equal(BinaryTreeNode *A, BinaryTreeNode *B);

bool isSubTree(BinaryTreeNode *A, BinaryTreeNode *B)
{
    if(nullptr == B && nullptr == A)
        return false;
    if (nullptr == B)
        return true;
    if (nullptr == A && B != nullptr)
        return false;
    if(equal(A, B) || isSubTree(A->m_pLeft, B) || isSubTree(A->m_pRight, B))
        return true;
    return false;
};

bool equal(BinaryTreeNode *A, BinaryTreeNode *B)
{
    if(nullptr == B)
        return true;
    if(nullptr == A && B != nullptr)
        return false;
    return A->m_nValue == B->m_nValue && equal(A->m_pLeft, B->m_pLeft) && equal(A->m_pRight, B->m_pRight);
};

// 88888888888888888888888888888888888888888

// 推荐的答案，考虑到值为浮点数
bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.000001))
        return true;
    return false;
}

//判断是否是其子树
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr)
        return false;
    
    if(!Equal(pRoot1->m_nValue, pRoot2->m_nValue))
    {
        return false;
    }

    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool ret = false;

    if(pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if(Equal(pRoot1->m_nValue, pRoot2->m_nValue))
            ret = DoesTree1HaveTree2(pRoot1, pRoot2);
        if(!ret)
            ret = DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2);
        if(!ret)
            ret = DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2);
    }
    return ret;
}

// ============测试代码=========
void Test(const char* testName, BinaryTreeNode* A, BinaryTreeNode* B, bool expected)
{
    
    if (expected == HasSubTree(A, B))
    {   
        printf("%s passed\n", testName);
    }
    else
    {
        printf("%s failed\n", testName);
    }
    printf("Tree A:\n");
    PrintBinaryTree(A);
    printf("Tree B:\n");
    PrintBinaryTree(B);
    printf("\n\n");
}

// 两个空树 否
void Test1()
{
    Test("test1", nullptr, nullptr, false);
}

// A非空，B空 否
void Test2()
{
    BinaryTreeNode* A = new BinaryTreeNode(1);
    Test("test2", A, nullptr, true);
    DestroyTree(A);
}

// B是A的叶子节点 是
void Test3()
{
    int a[] = {1,2,3};
    std::vector<int> arr(a, a+3);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    BinaryTreeNode* B = new BinaryTreeNode(2);
    Test("test3", A, B, true);
    DestroyTree(A);
    DestroyTree(B);
}

//B是A的左子树 是
void Test4()
{
    int a[] = {1, 2, -1, 3, -1, -1, -1};
    int b[] = {2, 3};
    std::vector<int> arr(a, a + 7);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    std::vector<int> brr(b, b + 2);
    BinaryTreeNode* B = CreateBinaryTreeByArray(brr);
    Test("test4", A, B, true);
    DestroyTree(A);
    DestroyTree(B);
}

// B是A的中间某一部分 是
void Test5()
{
    int a[] = {8,8,7,9,2,-1,-1,-1,-1,4,7};
    int b[] = {8,9,2};
    std::vector<int> arr(a, a + 11);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    std::vector<int> brr(b, b + 3);
    BinaryTreeNode* B = CreateBinaryTreeByArray(brr);
    Test("test5", A, B, true);
    DestroyTree(A);
    DestroyTree(B);
}

// A = B 是
void Test6()
{
    BinaryTreeNode *A = new BinaryTreeNode(1);
    BinaryTreeNode *B = new BinaryTreeNode(1);
    Test("test6", A, B, true);
    DestroyTree(A);
    DestroyTree(B);
}

// B不是A的子树 否
void Test7()
{
    int a[] = {8,8,7,9,2,-1,-1,-1,-1,4,7};
    int b[] = {8,9,4};
    std::vector<int> arr(a, a + 11);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    std::vector<int> brr(b, b + 3);
    BinaryTreeNode* B = CreateBinaryTreeByArray(brr);
    Test("test7", A, B, false);
    DestroyTree(A);
    DestroyTree(B);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
}






