// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向

/**
 * 测试用例
 * 1，空
 * 2，一个节点
 * 3，正常BST
 * 4，单边BST
 * 5，非BST
*/

/**
 * 思路一：
 * 中序遍历树，用一个数组存放节点指针，然后遍历数组中的节点指针，
 * 左指向值小的节点或nullptr，
 * 右指针指向大的节点或nullptr
 * 时间、空间复杂度均为O(n)
 * 
 * 思路二：
 * 中序遍历树，遍历的过程中修改指针
*/


#include "BinaryTree.h"

#include <iostream>

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode**  pLastNodeInList);

// pLastNodeInList相当于一个队列，记录着队列中最后一个节点
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if(pNode == nullptr)
        return;
    
    BinaryTreeNode* pCurrent = pNode;

    // 递归遍历到当前节点的最左节点
    if (pCurrent->m_pLeft != nullptr)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

    // 构建双向链表
    // 找到当前最小值，当前节点左指针指向上一个节点
    pCurrent->m_pLeft = *pLastNodeInList;

    // 最后节点的右节点指向，找到的当前最小节点
    if(*pLastNodeInList !=nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;
    
    // 更新当前节点为最后的节点
    *pLastNodeInList = pCurrent;

    // 遍历中序遍历右子树
    if(pCurrent->m_pRight != nullptr)
     ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

void inOrder(BinaryTreeNode *pNode, BinaryTreeNode** pLastNode)
{
    if (pNode == nullptr)
        return;

    if(pNode->m_pLeft != nullptr)
        inOrder(pNode->m_pLeft, pLastNode);
    
    pNode->m_pLeft = *pLastNode;
    if (*pLastNode != nullptr)
        (*pLastNode)->m_pRight = pNode;

    *pLastNode = pNode;

    if(pNode->m_pRight != nullptr)
        inOrder(pNode->m_pRight, pLastNode);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList = nullptr;
    inOrder(pRootOfTree, &pLastNodeInList);

    // pLastNodeInList指向双向链表的尾结点，
    // 我们需要返回头结点
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;

}

// ====================测试代码====================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pRight == nullptr)
            break;
        pNode = pNode->m_pRight;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pLeft == nullptr)
            break;
        pNode = pNode->m_pLeft;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        BinaryTreeNode* pNext = pNode->m_pRight;

        delete pNode;
        pNode = pNext;
    }
}

void Test(const char* testName, BinaryTreeNode* pRootOfTree)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    PrintBinaryTree(pRootOfTree);

    BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
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

    DestroyList(pNode4);
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

    DestroyList(pNode1);
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

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = new BinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
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