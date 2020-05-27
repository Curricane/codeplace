// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

/**
 * 测试用例
 * 1，空
 * 2，一个节点
 * 3，全节点
 * 4，单边左树
 * 5，单边右树
 * 
 * 检查代码
*/

#include "BinaryTree.h"

#include <iostream>
#include <stack>
#include <vector>

using std::vector;
using std::stack;


void MirrorRecursively(BinaryTreeNode *pNode)
{
    if (nullptr == pNode)
        return;
    
    BinaryTreeNode *temp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = temp;

    MirrorRecursively(pNode->m_pLeft);
    MirrorRecursively(pNode->m_pRight);
}

void MirrorIteratively(BinaryTreeNode* pRoot)
{
    if (nullptr == pRoot)
        return;
    stack<BinaryTreeNode*> s;
    s.push(pRoot);
    while(s.size() > 0)
    {
        BinaryTreeNode *pNode = s.top();
        s.pop();

        BinaryTreeNode *temp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = temp;

        // 先序遍历，需要先右子树进栈
        if(pNode->m_pRight != nullptr)
            s.push(pNode->m_pRight);
        if(pNode->m_pLeft != nullptr)
            s.push(pNode->m_pLeft);
        
    }
    
}

// =========测试代码==========
void Test(const char* name, BinaryTreeNode* A, BinaryTreeNode* expected)
{
    printf("%s \n", name);
    printf("输入的树：\n");
    PrintBinaryTree(A);
    printf("\n");

    //MirrorIteratively(A);
    MirrorRecursively(A);

    printf("镜像后的树：\n");
    PrintBinaryTree(A);
    printf("\n");

    if(isEqual(A, expected))
    {
        printf("---------------------------------passed\n");
    }
    else
    {
        printf("---------------------------------failed\n");
    }
    DestroyTree(A);
    DestroyTree(expected);
}

void Test1()
{
    Test("test1", nullptr, nullptr);
}

void Test2()
{
    BinaryTreeNode *A = new BinaryTreeNode(1);
    BinaryTreeNode *B = new BinaryTreeNode(1);
    Test("test2", A, B);
}

void Test3()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> arr(a, a+15);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    int b[] = {1,3,2,7,6,5,4,15,14,13,12,11,10,9,8};
    vector<int> brr(b, b+15);
    BinaryTreeNode* B = CreateBinaryTreeByArray(brr);
    Test("test3", A, B);
}

void Test4()
{
    int a[] = {1,2,-1,3};
    vector<int> arr(a, a+4);
    BinaryTreeNode* A = CreateBinaryTreeByArray(arr);
    int b[] = {1,-1,2,-1,-1,-1,3};
    vector<int> brr(b, b+7);
    BinaryTreeNode* B = CreateBinaryTreeByArray(brr);
    Test("test4", A, B);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
}