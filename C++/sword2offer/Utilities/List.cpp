#include "list.h"

#include <cstdio>

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if (pCurrent == nullptr)
    {
        printf("Error to connet two nodes.\n");
        exit(1);
    }
    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode *pNode)
{
    if (pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("[%3d]-->", pNode->m_nValue);
    } 
}

void PrintList(ListNode *pHead)
{
    ListNode *pNode = pHead;
    while(pNode != nullptr)
    {
        PrintListNode(pNode);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

void DestroyList(ListNode *pHead)
{
    ListNode* pNode =pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode **pHead, int val)
{
    ListNode *pNew = new ListNode(val);

    if(nullptr == *pHead)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode *pNode = *pHead;
        while(nullptr != pNode->m_pNext)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(nullptr == pHead || nullptr == *pHead)
        return;

    ListNode *pToBeDelete = nullptr;
    if ((*pHead)->m_nValue == value)
    {
        pToBeDelete = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode *pNode = *pHead;
        while(nullptr != pNode->m_pNext && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;
        
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDelete = pNode->m_pNext;
            pNode->m_pNext = pToBeDelete->m_pNext;
        }
    }

    if (pToBeDelete != nullptr)
    {
        delete pToBeDelete;
        pToBeDelete = nullptr;
    }
    
}
