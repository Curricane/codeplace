// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值

#include <iostream>
#include <stack>

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
    ListNode(int x):m_nKey(x), m_pNext(nullptr){};
};

void printListInReverseOrder_Recursively(ListNode *node)
{
    if ( nullptr == node)
    {
        return;
    }
    
    printListInReverseOrder_Recursively(node->m_pNext);
    std::cout << node->m_nKey << " ";
}


void printListInReverseOrder_Stack(ListNode *node)
{
    if ( nullptr == node )
        return;
    
    std::stack<ListNode *> nodes;
    ListNode *pNode = node;
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty())      
    {
        pNode = nodes.top();
        std::cout << pNode->m_nKey << " ";
        nodes.pop();
    }
    
}

void Test1()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    l1->m_pNext = l2;
    l2->m_pNext = l3;
    l3->m_pNext = l4;
    l4->m_pNext = l5;
    l5->m_pNext = l6;
    
    //test a completed list
    printListInReverseOrder_Recursively(l1);
    std::cout << std::endl;
    printListInReverseOrder_Stack(l1);
    std::cout << std::endl;

    //test a null list
    printListInReverseOrder_Stack(nullptr);
    std::cout << std::endl;

    //test a list that contain one node
    printListInReverseOrder_Stack(l6);
    std::cout << std::endl;

}

int main(int argc, char **argv)
{
    Test1();
    return 0;
}
