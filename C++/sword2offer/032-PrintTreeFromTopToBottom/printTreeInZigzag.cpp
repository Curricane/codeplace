#include <cstdio>
#include "BinaryTree.h"
#include <stack>

// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

void printTreeInZigzag(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    // 用2个栈来存放当前行和下一行
    std::stack<BinaryTreeNode*> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();

        printf("%d ", pNode->m_nValue);

        if(current == 0)
        {
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else
        {
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }

        if(levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}

// ====================测试代码====================
void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    PrintBinaryTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    printTreeInZigzag(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = new BinaryTreeNode(10);
    BinaryTreeNode* pNode6 = new BinaryTreeNode(6);
    BinaryTreeNode* pNode14 = new BinaryTreeNode(14);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode8 = new BinaryTreeNode(8);
    BinaryTreeNode* pNode12 = new BinaryTreeNode(12);
    BinaryTreeNode* pNode16 = new BinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyTree(pNode10);
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
void Test2()
{
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
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
void Test3()
{
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);
    BinaryTreeNode* pNode2 = new BinaryTreeNode(2);
    BinaryTreeNode* pNode3 = new BinaryTreeNode(3);
    BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
    BinaryTreeNode* pNode5 = new BinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

   return 0;
}