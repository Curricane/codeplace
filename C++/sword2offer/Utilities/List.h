#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
    ListNode(int x):m_nValue(x), m_pNext(nullptr){};
};

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);
