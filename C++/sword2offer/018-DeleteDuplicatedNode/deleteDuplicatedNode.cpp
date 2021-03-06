// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？
// 这里重复的节点都要删除 如 1, 1, 1, 1, 1 去掉重复的节点是 null


#include "list.h"

#include <cstdio>

// 只要节点重复了，删除全部重复的节点，一个不留
void DeleteDuplication(ListNode** pHead)
{
    if (nullptr == pHead || nullptr == *pHead)
    {
        return;
    }

    //位于重复节点的前一个节点
    ListNode *pPreNode = nullptr;

    //重复节点的第一个节点
    ListNode *pNode = *pHead;

    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;
        bool isNeed2Del = false;
        if (pNext != nullptr && pNode->m_nValue == pNext->m_nValue) // 重复节点
        {
            isNeed2Del = true;
        }

        if (isNeed2Del)
        {
            int value = pNode->m_nValue; // 记录重复节点的值，用于判断删除最后一个重复节点
            ListNode *pToDel = pNode;
            while (pToDel != nullptr && pToDel->m_nValue == value) // 从第一个节点开始删除
            {
                pNext = pToDel->m_pNext;
                delete pToDel;
                pToDel = nullptr;
                pToDel = pNext;
            }
            if(pPreNode == nullptr) // 开头就有重复节点，链头移到下一个值节点
            {
                *pHead = pNext;
            }
            else
            {
                pPreNode->m_pNext = pNext; // 链上，保持节点完整，始终位于pNode之前
            }
            pNode = pNext;
        }
        else // 不是重复节点，判断下两个节点
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        
    }
    
}

// 去掉重复节点, 只保留一个
void DeleteDuplicationAndSaveOne(ListNode** pHead)
{
    if (nullptr == pHead || nullptr == *pHead)
    {
        return;
    }

    ListNode *pPreNode = *pHead;
    ListNode *pNode = pPreNode->m_pNext;

    while (pNode != nullptr )
    {
        bool isSame = false;
        if (pPreNode->m_nValue == pNode->m_nValue)
        {
            isSame = true;
        }
        else 
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }

        if (isSame)
        {
            ListNode *toBeDel = pNode;
            pNode = pNode->m_pNext;
            pPreNode->m_pNext = pNode;
            delete toBeDel;
            toBeDel = nullptr;
        }   
    }   
}

// 去掉重复节点中其他多于的节点，只保留一个
void DeleteDuplicationAndSaveOne2(ListNode** pHead)
{
    if (nullptr == pHead || nullptr == *pHead)
    {
        return;
    }

    ListNode *pPreNode = nullptr;
    ListNode *pNode = *pHead;

    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;
        
        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode *pToBeDel = pNext;
            while (pToBeDel != nullptr && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;
                pNode->m_pNext = pNext;
                delete pToBeDel;
                pToBeDel = nullptr;
                pToBeDel = pNext;
            }
            
            pNode = pNext;
        }
        
    }
}

// ====================测试代码====================
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    printf("原始的链表: \n");
    PrintList(*pHead);
    DeleteDuplication(pHead);
    printf("去重后的链表: \n");
    PrintList(*pHead);
    
    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 某些结点是重复的
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(4);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 没有重复的结点
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    ListNode* pNode7 = new ListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 所有结点的值都相同
void Test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 所有结点都成对出现
void Test5()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(2);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(3);
    ListNode* pNode7 = new ListNode(4);
    ListNode* pNode8 = new ListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void Test6()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);
    ListNode* pNode8 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void Test7()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有一个结点
void Test8()
{
    ListNode* pNode1 = new ListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有两个重复的结点
void Test9()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 空链表
void Test10()
{
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
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
    Test9();
    Test10();

    return 0;
}

