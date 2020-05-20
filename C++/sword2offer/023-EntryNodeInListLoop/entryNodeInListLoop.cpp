#include "List.h"

#include <iostream>

/*
使用快慢节点，先找到相遇的节点，此时 链表到人口距离为a, 入口a到相遇点b的距离为b则有
2 * a + 2 * b = a + nLoop + b
a = nLoop - b
认为 从开头走到入口A，走了a步，等同于在环内 走了nLoop - b
因此此时从相遇点b开始走a步，最终会停留在路口位置
*/

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if (nullptr == pHead)
        return nullptr;

    // 先集体走一步，避开while循环中的判等
    ListNode *pSlow = pHead->m_pNext; 
    if (nullptr == pSlow)
        return nullptr;
    ListNode *pFast = pSlow->m_pNext;
    
   //找到相遇的地方，pFast必须连续走完2步，不能走一步遇到
    while (pFast != nullptr)
    {
        if (pFast == pSlow)
            break;
        
        pFast = pFast->m_pNext;
        if (nullptr == pFast)
            return nullptr;
        pFast = pFast->m_pNext;

        pSlow = pSlow->m_pNext;
    }

    // 判断是不是无环的
    if (nullptr == pFast)
        return nullptr;
    
    // pSlow1从头开始, pSlow从相遇点开始，等速前行，则相遇的点为入口位置
    ListNode *pSlow1 = pHead;
    while (pSlow1 != pSlow)
    {
        pSlow1 = pSlow1->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    return pSlow;
}

// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = new ListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
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