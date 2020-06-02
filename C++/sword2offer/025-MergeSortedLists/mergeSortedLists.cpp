// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。

// 测试
// 两个空链表
// 有一个空链表
// 都只有一个节点
// 有一个节点都是一样的值
// 两个节点都是一样的值
// 链表不是排序的

#include "List.h"

#include <iostream>
#include <cstdio>

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (nullptr == pHead1)
        return pHead2;
    if (nullptr == pHead2)
        return pHead1;
    ListNode* pHead;
    ListNode* pPos1 = pHead1;
    ListNode* pPos2 = pHead2;

    if (pPos1->m_nValue <= pPos2->m_nValue)
    {
        pHead = pPos1;
        pPos1 = pPos1->m_pNext;
    }
    else
    {
        pHead = pPos2;
        pPos2 = pPos2->m_pNext;
    }
    ListNode* pPos = pHead;
    int value = pPos->m_nValue;

    while(pPos1 != nullptr && pPos2 != nullptr)
    {
        if (pPos1->m_nValue <= pPos2->m_nValue)
        {
            pPos->m_pNext = pPos1;
            pPos = pPos1;
            pPos1 = pPos1->m_pNext;
        }
        else
        {
            pPos->m_pNext = pPos2;
            pPos = pPos2;
            pPos2 = pPos2->m_pNext;
        }
        if (pPos->m_nValue < value) 
        {
            std::cout << "链表不是排序的" << std::endl;
            return pHead;
        }
        value = pPos->m_nValue;   
    }

    if (nullptr == pPos1)
    {
        pPos->m_pNext = pPos2;
    }
    else
    {
        pPos->m_pNext = pPos1;
    }

    return pHead;
}

// 官方答案
ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
{
    if (nullptr == pHead1)
        return pHead2;
    if (nullptr == pHead2)
        return pHead1;
    
    ListNode* pMergedHead = nullptr;

    if (pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge1(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge1(pHead1, pHead2->m_pNext);
    }
    
    return pMergedHead;
}
// ====================测试代码====================
ListNode* Test(const char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge1(pHead1, pHead2);
    PrintList(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode6 = new ListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode6 = new ListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

// 一个链表为空链表
// list1: 1 1 1 1
// list2: 1 1 1 1
void Test6()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);

    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(1);
    ListNode* pNode8 = new ListNode(1);

    

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);


    ListNode* pMergedHead = Test("Test6", pNode1, pNode5);

    DestroyList(pMergedHead);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    return 0;
}

